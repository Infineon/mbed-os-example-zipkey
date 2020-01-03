# Introduction

This repository contains the example application and associated header files required to demonstrate Cirrent's ZipKey and SoftAP onboarding features. For more information refer to [README](./cirrent/README.md)

### Supported Compilers

- GCC Arm Embedded - version 6.3.1
- ARM Compiler - version 6.11
- IAR EWARM Compiler - version 8.3

### Required Mbed OS tools

- mbed-cli - version 1.10.1

### Supported Targets

1) [PSoC6 WiFi-BT Prototyping Kit (CY8CPROTO-062-4343W)](https://www.cypress.com/documentation/development-kitsboards/psoc-6-wi-fi-bt-prototyping-kit-cy8cproto-062-4343w)
2) [PSoC6 WiFi-BT Pioneer Kit (CY8CKIT-062-WiFi-BT)](https://www.cypress.com/documentation/development-kitsboards/psoc-6-wifi-bt-pioneer-kit-cy8ckit-062-wifi-bt)

### Dependencies

- [ARM mbed-os version 5.14 and above](https://os.mbed.com/mbed-os/releases)
- [Cypress HTTP Server Library](https://github.com/cypresssemiconductorco/mbed-os-example-http-server)
- [HTTP and HTTPS Library for Mbed OS 5](https://os.mbed.com/teams/sandbox/code/mbed-http/)
- [Cypress Connectivity Utilities Library](https://github.com/cypresssemiconductorco/connectivity-utilities)

### Steps to build the application

1) Prepare the cloned working directory for mbed using
     - `mbed config root .`
2) Pull the necessary dependencies using
     - `mbed deploy`
3) Register your device with Cirrent at https://support.cirrent.com/hc/en-us/articles/115000119646 and get the **Account Id**, **Device Id** and **Secret**.
4) Generate config header file with the following command inside `cirrent/pdm_tool`. This script can only be run on Windows. For more information about this tool refer to [README](./cirrent/pdm_tool/README.md).
    - `pdm_generate.sh ACCOUNT_ID DEVICE_ID SECRET`
5) Build and download the application on Cypress target platform
    - `mbed compile -t GCC_ARM -m CY8CPROTO_062_4343W -f`
     **Note** : The default application runs ZipKey onboarding. To run SoftAP onboarding change `ca_init_config.softap_config.softap_enabled = true`
6) Reset the board and check serial console logs. Board shall boot and start Cirrent Agent.


### Additional Information

- [ZipKey Application version](./version.txt)
- More information about the Cirrent Agent can be found in the [Knowledge Center](https://support.cirrent.com/hc/en-us/categories/201995283-Wireless-Connection-Manager-CA-)
