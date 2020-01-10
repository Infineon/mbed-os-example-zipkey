# Introduction
This repository contains the Cirrent library code example for PSOC6 MCU family of devices bundled with connectivity.

This application demonstrates onboarding device to the required Wi-Fi network using Cirrent's ZipKey and SoftAP onboarding feature.

# Supported Platforms
This application and it's features are supported on following Cypress platforms:
* [PSoC6 WiFi-BT Prototyping Kit (CY8CPROTO-062-4343W)](https://www.cypress.com/documentation/development-kitsboards/psoc-6-wi-fi-bt-prototyping-kit-cy8cproto-062-4343w)
* [PSoC6 WiFi-BT Pioneer Kit (CY8CKIT-062-WiFi-BT)](https://www.cypress.com/documentation/development-kitsboards/psoc-6-wifi-bt-pioneer-kit-cy8ckit-062-wifi-bt)

# Dependencies
This section provides the list of dependency libraries required for this application to work.
* [ARM mbed-os version 5.15 and above](https://os.mbed.com/mbed-os/releases)
* [Cypress Cirrent Library](https://github.com/cypresssemiconductorco/cirrent)
* [Cypress HTTP Server Library](https://github.com/cypresssemiconductorco/http-server)
* [Cypress Connectivity Utilities Library](https://github.com/cypresssemiconductorco/connectivity-utilities)
* [HTTP Client Library](https://os.mbed.com/teams/sandbox/code/mbed-http/)

# Instructions to build this code example
1) Prepare the cloned working directory for mbed using
     - `mbed config root .`
2) Pull the necessary dependencies using
     - `mbed deploy`
3) Register your device with [Cirrent Console](https://console.cirrent.com/) to generate **Account Id**, **Device Id** and **Device Secret**. Refer article [Registering Devices with Cirrent](https://support.cirrent.com/hc/en-us/articles/115000119646) for details.
4) Generate config header file with the following command inside `cirrent/pdm_tool`. This script can only be run on Windows. For more information about this tool refer to [README](https://github.com/cypresssemiconductorco/cirrent/tree/master/pdm_tool/README.md)
    - `pdm_generate.sh ACCOUNT_ID DEVICE_ID SECRET`
5) Build and download the application on Cypress target platform
    - `mbed compile -t GCC_ARM -m CY8CPROTO_062_4343W -f`
     **Note** : The default application uses ZipKey onboarding feature. To enable SoftAP onboarding feature, set `ca_init_config.softap_config.softap_enabled = true` in main.cpp
6) Reset the board and check serial console logs. Board shall boot and start Cirrent Agent.

# Additional Information
- [ZipKey Application version](./version.txt)
- More information about the Cirrent Agent can be found in the [Knowledge Center](https://support.cirrent.com/hc/en-us/categories/201995283-Wireless-Connection-Manager-CA-)

