# Arduino-CLI Tutorial for ESP32-C6

[![ESP32](https://img.shields.io/badge/ESP32-Supported-blue.svg)](https://www.espressif.com/en/products/socs/esp32)
[![Arduino CLI](https://img.shields.io/badge/Arduino%20CLI-Compatible-brightgreen.svg)](https://arduino.github.io/arduino-cli/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A concise guide on using Arduino-CLI with the ESP32-C6 development board and other ESP32 family microcontrollers.

## Table of Contents

- [Introduction](#introduction)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Setting Up ESP32-C6 Core](#setting-up-esp32-c6-core)
- [Creating a New Sketch](#creating-a-new-sketch)
- [Compiling the Sketch](#compiling-the-sketch)
- [Uploading the Sketch](#uploading-the-sketch)
- [Troubleshooting](#troubleshooting)
- [ESP32 Family Comparison](#esp32-family-comparison)
- [Popular ESP32 Projects](#popular-esp32-projects)
- [Contributing](#contributing)
- [Additional Resources](#additional-resources)

## Introduction

Arduino-CLI is a powerful command-line tool for compiling and uploading Arduino sketches to various microcontrollers. This tutorial focuses on its use with the ESP32 family of boards, with special attention to the newer ESP32-C6. The instructions are applicable to all ESP32 variants supported by Arduino, including:

- ESP32
- ESP32-S2
- ESP32-S3
- ESP32-C3
- ESP32-C6
- ESP32-H2

Whether you're working with the versatile ESP32, the Bluetooth 5 (LE) capable ESP32-C3, or the latest ESP32-C6 with Wi-Fi 6, this guide has you covered.

## Prerequisites

- Arduino and CLI basics
- Windows, macOS, or Linux computer
- ESP32-C6 board
- USB cable

## Installation

1. Download [Arduino-CLI](https://github.com/arduino/arduino-cli).
2. Add to system PATH.
3. Verify:
   ```bash
   arduino-cli version
   ```

## Setting Up ESP32-C6 Core

1. Update index:
   ```bash
   arduino-cli core update-index
   ```
2. Install ESP32 core:
   ```bash
   arduino-cli core install esp32:esp32
   ```
3. Verify:
   ```bash
   arduino-cli core list
   ```

## Creating a New Sketch

```bash
arduino-cli sketch new MyESP32C6Project
cd MyESP32C6Project
```

## Compiling the Sketch

```bash
arduino-cli compile --fqbn esp32:esp32:esp32c6 ./
```

## Uploading the Sketch

1. List boards:
   ```bash
   arduino-cli board list
   ```
2. Note your board's port (e.g., /dev/ttyACM0 or COMx).
3. Upload:
   ```bash
   arduino-cli upload -p /dev/ttyACM0 --fqbn esp32:esp32:esp32c6 ./
   ```

## Troubleshooting

- "Board not found": Verify core installation and FQBN.
- Upload issues: Check USB connection and port.

## ESP32 Family Comparison

| Feature | ESP32 | ESP32-S2 | ESP32-S3 | ESP32-C3 | ESP32-C6 | ESP32-H2 |
|---------|-------|----------|----------|----------|----------|----------|
| CPU     | Dual-Core | Single-Core | Dual-Core | Single-Core | Single-Core | Single-Core |
| Wi-Fi   | 2.4 GHz | 2.4 GHz | 2.4 GHz | 2.4 GHz | Wi-Fi 6 | 2.4 GHz |
| Bluetooth | Classic & BLE | - | BLE 5.0 | BLE 5.0 | BLE 5.3 | BLE 5.0 |
| USB     | - | Native | Native | - | Native | - |
| Zigbee/Thread | - | - | - | - | Yes | Yes |

## Popular ESP32 Projects

1. **Smart Home Automation**: Use ESP32's Wi-Fi capabilities for home device control.
2. **Wireless Sensor Networks**: Create networks for environmental or industrial monitoring.
3. **Bluetooth Mesh Networks**: Build scalable device networks with ESP32's Bluetooth.
4. **IoT Data Loggers**: Efficient data collection and transmission with low power modes.
5. **Wearable Technology**: Develop fitness trackers or smart clothing.

## Contributing

Contributions are welcome! Open an issue or submit a pull request to help improve this guide or share your ESP32 projects.

## Additional Resources

- [Official ESP32 Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
- [Arduino-ESP32 GitHub Repository](https://github.com/espressif/arduino-esp32)
- [Arduino-CLI Documentation](https://arduino.github.io/arduino-cli/)

---

Keywords: Arduino-CLI, ESP32-C6, ESP32, microcontroller, IoT, embedded systems, command-line interface, Arduino sketches, Wi-Fi 6, Bluetooth LE, Zigbee, Thread, smart home, wireless sensor networks, wearable technology