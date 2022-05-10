# Unreal QT Framework

This is a helper library designed to be used in 
conjunction with the [tk-unreal](https://github.com/ue4plugins/tk-unreal) engine.

This framework contains hooks which can be re-used in configurations where the
Unreal integration is needed, and PySide2 binaries needed to run the SG Toolkit
integration in Unreal.

Please see the engine for more details.

## The PySide2 libraries

Binaries for PySide2 libraries for all platforms are not included in the
source tree and must be built before being able to use this framework.

### Building the PySide2 libraries locally

Use the [build_packages.sh](resources/build_packages.sh) script with the `-b` option to build and install 
the packages specified in the [requirements.txt](resources/requirements.txt) file.
```
Usage : ./build_packages.sh [-h] [-b] [-p <python command]
Options :
 -h : show this help message
 -b : build packages into their shipping destination
 -p : specify which python command to use, e.g. python, python2, python3
```
The framework can be used with a local descriptor (e.g. dev or path) once the 
binaries are build. 

### Building the PySide2 libraries with Azure Pipelines

The [build_packages.sh](resources/build_packages.sh) script can be used with [Azure Pipelines](https://docs.microsoft.com/en-us/azure/devops/pipelines/get-started/pipelines-get-started?view=azure-devops) 
to automatically build the packages each time a new version tag is added in Github.

You can get access to Azure Pipelines for free [from your Github account](https://docs.microsoft.com/en-us/azure/devops/pipelines/get-started/pipelines-sign-up?view=azure-devops#sign-up-with-a-github-account)
if you don't already have an account.

You can use the provided [azure-pipelines.yml](azure-pipelines.yml) file to create a [new Azure Pipeline](https://docs.microsoft.com/en-us/azure/devops/pipelines/repos/github?view=azure-devops&tabs=yaml#access-to-github-repositories).

A [service connection to Github](https://docs.microsoft.com/en-us/azure/devops/pipelines/repos/github?view=azure-devops&tabs=yaml#permissions-needed-in-github-1)
 will have to be created if you don't already have one.

The Azure pipeline builds the PySide2 libraries for Windows, Linux and Mac, and upload them to Github releases.

<img width="512" alt="Github releases" src="https://user-images.githubusercontent.com/39291844/153920988-0dcb80d3-3c37-479d-8079-33496f8952f4.png">

## Using this framework in your Setup

Add this framework in the `frameworks` settings section of the Toolkit application needing
it. 
For example:

```
frameworks:
     - {"name": "tk-framework-unrealqt", "version": "v1.x.x"}
```

- If you're using a local descriptor (dev or path) you need to build the PySide2 libraries
yourself. See [building the PySide2 libraries locally](#building-the-pyside2-libraries-locally).

- If you're using a remote descriptor, just in time download must be added so these binaries are downloaded in SG TK bootstrap process. The provided [bootstrap.py](hooks/core/bootstrap.py) script implements just in time downloads from Github releases with a `git` or a `github_release` descriptor:
   - Copy the `hooks/core/bootstrap.py` file to your config `core/hooks/bootstrap.py`
hook.
   - Use a `git` descriptor for the framework, e.g.:
      ```
      tk-framework-unrealqt_v1.x.x:
        location:
          version: v1.3.0
          type: git
          path: git@github.com:ue4plugins/tk-framework-unrealqt.git
      ```
   - Or use a `github_release` descriptor for the framework, e.g.:
      ```
      tk-framework-unrealqt_v1.x.x:
        location:
          version: v1.3.0
          type: github_release
          organization: ue4plugins
          repository: tk-framework-unrealqt
      ```

