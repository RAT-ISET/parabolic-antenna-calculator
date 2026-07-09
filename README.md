# Parabolic Antenna Calculator
>**Parabolic-Antenna-Calculator** is a software application，which is used for the rapid design and analysis of the critical performance characteristics of parabolic reflector antennas.

## Contents
1. Project Introduction
2. Functional Features
3. Technology stack
4. Quick Start
   - Environmental Requirements
   - Download and Installation
 5. Instructions for Use
 6. Project Structure
 8. License
 9. Contact Information
 
##  Project Introduction
Parabolic-Antenna-Calculators is a professional auxiliary tool aimed at antenna designers, used for rapidly calculating the core performance parameters of parabolic reflector antennas. 

This software can help users avoid complex manual iterative calculations in the early stages of design, thereby shortening the antenna selection and preliminary design cycle.

## Functional Features
-  Compact size, downloads in seconds
- Cross-platform: Windows / macOS / Linux
- No environment setup required, easy to download and run

## Technology stack
- Frontend: None (CLI-based)
- Backend: C++
- Deployment: apt / dnf / pacman / winget (later) + manual download

## Quick Start
### Environmental Requirements
- x64 binaries included; 
- other platforms require manual compilation.
### Download and Installation
    Package Repositories: https://repos.ratiset.org (RPM: /rpm, DEB: /deb, Arch: /arch)

## Instructions for Use
### Usage

#### Basic Command Structure

```bash
ParabolicAntennaCalculator [OPTIONS] <project_path> [SUBCOMMANDS]
```

#### Global Options

| Option | Description |
|--------|-------------|
| `-h, --help` | Print this help message and exit |
| `-v, --version` | Display program version information and exit |
| `--debug` | Enable debug mode |

#### Subcommands

| Subcommand | Description |
|------------|-------------|
| `init` | Initialize the project |
| `para` | Manage parameters |
| `run` | Start the calculator |

#### Parameter Management (para)

`para` includes the following subcommands:

| Subcommand | Description |
|------------|-------------|
| `set` | Set a parameter |
| `delete` | Delete a parameter |
| `show` | Show parameter list |

**Available parameters:** `frequency` / `wavelength` / `efficiency` / `diameter` / `increase` / `focalLength` / `height` / `f/D`

```bash
# Show all parameters
ParabolicAntennaCalculator <project_path> para show

# Show a specific parameter
ParabolicAntennaCalculator <project_path> para show <parameter_name>

# Set a single parameter
ParabolicAntennaCalculator <project_path> para set <parameter_name> <value>

# Delete a parameter
ParabolicAntennaCalculator <project_path> para delete <parameter_name>
```

#### Run Calculation (run)

```bash
# Run calculation (continues until termination)
ParabolicAntennaCalculator <project_path> run

# Run with a specific step size
ParabolicAntennaCalculator <project_path> run --step <step_size>
```

#### Complete Example

```bash
# 1. Initialize project
ParabolicAntennaCalculator myproject init

# 2. Set parameters
ParabolicAntennaCalculator myproject para set frequency 10
ParabolicAntennaCalculator myproject para set diameter 2.4
ParabolicAntennaCalculator myproject para set efficiency 0.65

# 3. View a specific parameter
ParabolicAntennaCalculator myproject para show frequency

# 4. View all parameters
ParabolicAntennaCalculator myproject para show

# 5. Run calculation (auto-iterates to completion)
ParabolicAntennaCalculator myproject run

# 6. Check parameters again (wavelength is auto-calculated after run)
ParabolicAntennaCalculator myproject para show
```

## Project Structure
 ```bash
./
│  .editorconfig
│  .gitignore
│  CMakeLists.txt
│  LICENSE
│  LICENSE.rtf
│  LICENSE.txt
│  README.md
│  
├─.github
│  ├─pkg
│  │  └─arch
│  │          PKGBUILD.in
│  │          
│  └─workflows
│          Build.yml
│          Release.yml
│          
├─cmake
│      ArchPkg.cmake
│      Deps.cmake
│      Release.cmake
│      
├─docs
│      FILE.md
│      
├─include
│  └─pac
│      ├─arg
│      │      Cmd.hpp
│      │      CmdError.hpp
│      │      
│      ├─core
│      │      Definition.hpp
│      │      Entry.hpp
│      │      Error.hpp
│      │      Logger.hpp
│      │      Message.hpp
│      │      
│      ├─io
│      │      DataFile.hpp
│      │      IoError.hpp
│      │      LogFile.hpp
│      │      PacProject.hpp
│      │      
│      └─math
│              Calculate.hpp
│              Constants.hpp
│              Function.hpp
│              
└─src
    │  CMakeLists.txt
    │  Main.cpp
    │  
    ├─arg
    │      CMakeLists.txt
    │      Cmd.cpp
    │      CmdError.cpp
    │      
    ├─core
    │      CMakeLists.txt
    │      Entry.cpp
    │      Error.cpp
    │      Logger.cpp
    │      
    ├─io
    │      CMakeLists.txt
    │      DataFile.cpp
    │      IoError.cpp
    │      LogFile.cpp
    │      PacProject.cpp
    │      
    └─math
            Calculate.cpp
            CMakeLists.txt
   ```

## License
This project is licensed under the ***MIT License***.

## Contact Information
- Author: ***Team ISET***
- Email: ratiset@outlook.com
- Website: https://ratiset.org
- Repository: https://github.com/RAT-ISET/parabolic-antenna-calculator
- Issues: https://github.com/RAT-ISET/parabolic-antenna-calculator/issues

