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
   - Usage
      - Basic Command Structure
      - Global Options
      - Subcommands
      - Parameter Management (para)
      - Run Calculation (run)
      - Complete Example
   - Report
      - Required Information
      - How to Collect Debug Log
      - What to Include in Your Report
      - Example Bug Report Template
              - Description
              - Log
              - Environment
7. Project Structure
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

| Option          | Description                                  |
|-----------------|----------------------------------------------|
| `-h, --help`    | Print this help message and exit             |
| `-v, --version` | Display program version information and exit |
| `--debug`       | Enable debug mode                            |

#### Subcommands

| Subcommand | Description            |
|------------|------------------------|
| `init`     | Initialize the project |
| `para`     | Manage parameters      |
| `run`      | Start the calculator   |

#### Parameter Management (para)

`para` includes the following subcommands:

| Subcommand | Description         |
|------------|---------------------|
| `set`      | Set a parameter     |
| `delete`   | Delete a parameter  |
| `show`     | Show parameter list |
| `value`    | Set parameters using --<parameter_name> <parameter_value> format |

- *Available parameters:* `frequency` / `wavelength` / `efficiency` / `diameter` / `increase` / `focalLength` / `height` / `f/D`


```bash
# Show all parameters
ParabolicAntennaCalculator <project_path> para show

# Show a specific parameter
ParabolicAntennaCalculator <project_path> para show <parameter_name>

# Set a single parameter
ParabolicAntennaCalculator <project_path> para set <parameter_name> <value>

# Delete a parameter
ParabolicAntennaCalculator <project_path> para delete <parameter_name>

# Set one or more parameters using --<parameter_name> <parameter_value> format
ParabolicAntennaCalculator <project_path> para value --frequency 1.0 --diameter 2.4
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

### Report

> ***Bug Reporting Guidelines***
 When submitting a bug report, please include the following information to help us diagnose and resolve the issue efficiently:

#### Required Information

- Item Description
- Program Version Run ParabolicAntennaCalculator --version and include the output
- Operating System Include OS name, version, and architecture (e.g., Ubuntu 22.04 LTS x86_64)
- Debug Log Run the program with --debug flag and capture the full output

> **Debug log path:** `<project_path>/log.txt`

#### What to Include in Your Report

1. Version Information
   ```bash
   ParabolicAntennaCalculator --version
   ```
2. System Information
- OS: uname -a (Linux/macOS) or systeminfo (Windows)
- Architecture: x64 / ARM / others
3. Debug Log
- Attach the complete debug log file generated with --debug flag
- This includes detailed execution traces, parameter states, and calculation steps
4. Steps to Reproduce
- Provide the exact commands that led to the issue
- Include your project parameters if applicable
5. Expected vs Actual Behavior
- Describe what you expected to happen
- Describe what actually happened

#### Example Bug Report Template
##### Description
When the program throws an error, the Input will be duplicate printed.

##### Log

```text
.\ParabolicAntennaCalculator.exe test --debug para set increase -1.0 
[DEBUG][arg/Cmd.cpp:command] The command handler was parsed

......

[DEBUG][arg/Cmd.cpp:matchValue] To match the value -1.0
[ERROR]The input argument was invalid
Input: -1.000000-1.0
[INFO][arg/Cmd.cpp:shutdown] Close the project
[DEBUG][io/Project.cpp:close] Close the data file
[DEBUG][io/Project.cpp:close] Close the log file
```

##### Environment

> *Version: Commit 57e35a9b2ca80f6eb35abd8e830034602d42ff42*
> *System: Windows 11*
> *Affected System: All*

> **Note:** Debug logs contain detailed internal information. Please review them before sharing publicly and remove any sensitive data if necessary.

## Project Structure

```text
.
│  LICENSE
│  README.md
├─.github/...
│          
├─cmake
│      ArchPkg.cmake
│      Deps.cmake
│      Release.cmake
│      
├─src
│   │  CMakeLists.txt
│   │  Main.cpp
│   │  
│   ├─arg
│   │      Cmd.cpp
│   │      CmdError.cpp
│   │      
│   ├─core
│   │      Entry.cpp
│   │      Error.cpp
│   │      Logger.cpp
│   │      
│   ├─io
│   │      DataFile.cpp
│   │      IoError.cpp
│   │      LogFile.cpp
│   │      PacProject.cpp
│   │      
│   └─math
│           Calculate.cpp
│              
├─docs/...
└─include/...

```

---

## Contact Information
- Author: **Team ISET**
- Email: ratiset@outlook.com
- Website: [ISET](https://www.ratiset.org/)
- Repository: [Parabolic Antenna Calculator](https://github.com/RAT-ISET/parabolic-antenna-calculator)
- Issues: [Parabolic Antenna Calculator Issues](https://github.com/RAT-ISET/parabolic-antenna-calculator/issues)

---

>**Copyright (c) 2026 Team ISET**
>**This project is licensed under [MIT](https://github.com/RAT-ISET/parabolic-antenna-calculator/blob/main/LICENSE).**
