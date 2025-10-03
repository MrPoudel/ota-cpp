
[![codecov](https://codecov.io/gh/MrPoudel/ota-cpp/branch/develop/graph/badge.svg?token=d8dffb55-1cab-4381-af35-b7835e9f561e)](https://codecov.io/gh/MrPoudel/ota-cpp)

## Lightweight Secure OTA Update Framework (OTA-CPP)

OTA-CPP is a C++ project that provides a framework for implementing Over-the-Air (OTA) updates in embedded systems and IoT devices. It focuses on reliability, lightweight design, and cross-platform support for resource-constrained environments.

### Features [Not impelemented yet]
- Firmware Updates – Secure download and installation of firmware images.
- Delta Updates – Support for partial updates to reduce bandwidth usage.
- Integrity Checks – Built-in checksum and cryptographic validation of downloaded files.
- Rollback Mechanism – Safe fallback in case of failed updates.
- Transport Agnostic – Works with HTTP, HTTPS, or custom communication protocols.
- Cross-Platform – Designed for microcontrollers, Linux-based systems, and edge devices.
- Configurable Storage – Support for flash memory, SD cards, or other storage mediums.
### Use Cases
- IoT devices requiring remote firmware upgrades
- Embedded systems in automotive, industrial, or consumer electronics
- Edge devices with limited connectivity needing secure update mechanisms
### Roadmap
- Add support for encrypted firmware bundles
- Integrate with cloud-based OTA management services
- Provide unit tests and CI/CD pipelines for automated validation


### Build instructions

#### Install Required Tools (Ubuntu)

```
sudo apt update
sudo apt install -y build-essential cmake git lcov libgtest-dev ninja-build valgrind
sudo apt install -y lcov genhtml

```

#### Clone the Repository

```
git clone https://github.com/yourusername/ota-cpp.git
cd ota-cpp
```

#### Generate the Build System

| Purpose             | Command                                                                 |
|--------------------|-------------------------------------------------------------------------|
| Development debug   | `cmake -DCMAKE_BUILD_TYPE=Debug .. && make`     |
| Coverage (CI)       | `cmake -DCMAKE_BUILD_TYPE=Coverage .. && make` |
| Production release  | `cmake -DCMAKE_BUILD_TYPE=Release .. && make`  |


```
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Coverage ..
make
make coverage
xdg-open coverage-report/index.html 2>/dev/null
```

This opens a visual coverage report in your browser.

This compiles the OTA library and the CLI tool otactl.

#### Run the CLI Tool
```./tools/otactl/otactl ../qemu-test/manifests/valid.json```

