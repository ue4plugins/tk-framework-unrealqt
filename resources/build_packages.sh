#!/bin/bash
# Copyright 2019 GPL Solutions, LLC.  All rights reserved.
#
# Use of this software is subject to the terms of the GPL Solutions license
# agreement provided at the time of installation or download, or which otherwise
# accompanies this software in either electronic or hard copy form.
#

#####################################################################
long_help='

This script helps building and shipping Python packages
with this framework.

It uses virtual env and pip to do so, so you will need them
on your machine to use this script. On Windows, git-bash is
needed.

== Typical workflow ================================================

* Run this script once with no option to get a virtual env and a
 requirements.txt file
* Use the virtual env to install packages with standard pip install
 or update commands
* Update the requirements.txt file with pip freeze -r requirements.txt > requirements.txt
* Build and copy the packages into their shipping destination with the
 -b option
* Run some tests
* Update git with the copied packages and push


== Structure =======================================================

* This script use a "packagevenv_$platform_name_$python_major_version" virtual env to
 do packages downloads and buildings, where platform_name can either
 be "linux", "osx" or "windows".
* Packages are shipped in "../python/vendors/py${python_major_version}/${platform_name}".
 They are full copy of the virtual env for the current platform,
 with .pyc and .egg-info files deleted.
* They need to be added in git to ship with the framework
* Packages dependencies are stored in a standard requirements.txt
 pip file, build with regular pip commands

== Starting from scratch ===========================================

* A virtual env for the current platform will be created if needed
 by running the script without any option.
* An empty requirements.txt will be created if needed

== Building packages for a platform ================================

* If you are on Windows, you will have to run the script from
 a git-bash, NOT a cygwin shell, as cygmin will not use the right
 compiler and libraries
* On Windows, A Microsoft Visual C++ for Python 2.7 can be downloaded from :
 http://aka.ms/vcpython27
* Just run the script with the -b option, and all needed packages
 should be downloaded, build and copied into the shipping folder

== Adding packages =================================================

* Activate the virtual env for your platform, e.g. :
  source packagevenv_linux/bin/activate
* Install / update packages using pip, e.g. :
     pip install pycrypto
* Update the requirements.txt file :
     pip freeze -r requirements.txt > requirements.txt
* It is possible to edit the requirements.txt manually, although this
 is not recommended
* Copy the packages into their shipping location with the -b option

== Commiting packages in git ========================================

* Go into ../python/vendors shipping directory, and do:
    git add -f -A ./$platform
 where $platform is the platform name you want to update.
* The -f option is used to bypass .gitignore and add .so or .dll files.
'

#####################################################################
# Stop on errors
set -e
usage()
{
    echo "Usage : $0 [-h] [-b] [-p <python command>]"
    echo "Options :"
    echo " -h : show this help message"
    echo " -b : build packages into their shipping destination"
    echo " -p : specify which python command to use, e.g. python, python2, python3"
    echo "$long_help"
}
# Parse command line arguments
do_build=0
python_cmd="python"
while getopts “hp:b” option
do
     case $option in
         h)
             usage
             exit 1
             ;;
         b)
             do_build=1
             ;;
         p)
             python_cmd=$OPTARG
             ;;
         ?)
             usage
             exit
             ;;
     esac
done

uname_os_str=`uname`


# Build nice platform names from the os
if [[ "$uname_os_str" == Linux ]];
then
    platform_name="linux"
elif [[ "$uname_os_str" == Darwin ]];
then
    platform_name="osx"
elif [[ "$uname_os_str" == MINGW??_NT-* ]];
then
    platform_name="windows"
else
    echo "Unsupported platform !"
    exit 1
fi
echo "Detecting Python version..."
python_version=$($python_cmd --version 2>&1)
# 2 or 3
python_major_version=${python_version:7:1}
if [ -z $python_major_version ];
then
   echo "Unable to detect python version, aborting"
   exit 1
fi

echo "Detected python version ${python_major_version} from ${python_version}"

packagevenv="packagevenv_${platform_name}_${python_major_version}"
if [ ! -d $packagevenv ]; then
    if [ ${python_major_version} == 2 ];
    then
        # Create the virtual env to install packages
        # Please note that we used --no-site-packages but this option does not
        # exist anymore with virtualenv v20 is the default.
        virtualenv --always-copy $packagevenv
    elif [ ${python_major_version} == 3 ];
    then
        $python_cmd -m venv --copies $packagevenv
    else
        echo "Unsupported python version ${python_major_version}"
        exit 1
    fi
    echo "Created virtual env in $packagevenv"
fi
# Activate the virtual env
if [ $platform_name == "windows" ]; then
    . ${packagevenv}/Scripts/activate
else
    . ${packagevenv}/bin/activate
fi
# If the requirements.txt file does
# not already exist, create it and exit
if [ ! -f requirements.txt ]; then
    pip freeze > requirements.txt
    echo "Created requirements.txt file"
    echo "You can build it with virtualenv and pip"
    echo "Activate the virtual env :"
    echo "  source ${packagevenv}/bin/activate"
    echo "Install your modules :"
    echo "  pip install the_module_I_need"
    echo "Update the requirements.txt file :"
    echo "  pip freeze -r requirements.txt > requirements.txt"
    echo "Deactivate the virtual env:"
    echo "  deactivate"
    exit 0
fi
if [ $do_build == 1 ]; then
    # Build needed packages and copy them
    # into their shipping destination
    echo "Building packages ..."
    # Install packages from the requirements
    pip install -r requirements.txt
    # If there are some platform specific requirements, install them as well
    platform_requirements="${platform_name}_requirements.txt"
    if [ -f $platform_requirements ]; then
        echo "Installing plaform specific packages from $platform_requirements"
        pip install -r $platform_requirements
    fi
    # If there are requirements for a specific version of python, install them as well
    python_version_requirements="python_${python_major_version}_requirements.txt"
    if [ -f $python_version_requirements ]; then
        echo "Installing Python version specific packages from $python_version_requirements"
        pip install -r $python_version_requirements
    fi
    # Copy packages to their shipping destination
    if [ -d ./${packagevenv} ]; then
        mkdir -p ../python/vendors/py${python_major_version}
        target="../python/vendors/py${python_major_version}/${platform_name}"
        if [ -d $target ]; then
            echo "Deleting previous build in $target"
            # Clean up git but don't fail if there is nothing matching
            git rm -r -f ${target} --ignore-unmatch
            rm -r -f ${target}
            mkdir -p ${target}
        fi
        echo "Copying in ${target}"
        cp -R ./${packagevenv} $target
        cd ${target}
        # Do some cleanup
        find . -name "*.pyc" | xargs rm -f
        find . -name "*.egg-info" | xargs rm -rf
    fi
fi
