# Arduino IoT Cloud Light Control

## Overview

This project is an Arduino IoT Cloud-based light control system using an **Arduino LED Matrix** and a relay to control a light source. It leverages the **Arduino IoT Cloud** to adjust light intensity and switch states remotely.

## Hardware Requirements

- **Arduino board** (compatible with Arduino IoT Cloud)
- **Arduino LED Matrix**
- **Relay Module**
- **Light source**
- **Internet Connection** (Wi-Fi or Ethernet, depending on the board)
- **Wires and Power Supply**

## Software Requirements

- **Arduino IDE**
- **Arduino Create IoT Cloud**
- **Required Libraries:**
  - `ArduinoIoTCloud`
  - `Arduino_LED_Matrix`

## Features

- Control light intensity remotely via the **Arduino IoT Cloud Dashboard**.
- Toggle the light ON/OFF using IoT Cloud variables.
- View light brightness and switch status through serial output.
- Debugging information via `ArduinoCloud.printDebugInfo()`.

## Code Overview

### Initialization

- The program initializes the **serial communication**, **relay pin**, and **LED Matrix**.
- IoT Cloud properties are set up using `initProperties()`.
- The device connects to **Arduino IoT Cloud** using `ArduinoCloud.begin()`.

### Main Loop

- `ArduinoCloud.update()` is called to sync with the cloud.
- The relay is turned **ON** or **OFF** based on the **light_intensity** switch state.
- A delay of **40ms** prevents excessive updates.

### Event Function

- `onLightIntensityChange()` is triggered whenever the light intensity value changes.
- The new brightness level and switch status are printed to the **Serial Monitor**.

## Circuit Diagram

| Component | Pin Connection |
|-----------|---------------|
| Relay Module | Digital Pin 4 |
| LED Matrix | Integrated SPI/I2C |
| Arduino IoT Cloud | Wi-Fi/Ethernet |

## Installation

1. **Set up Arduino IoT Cloud** and create a **Thing**.
2. Define **CloudDimmedLight light_intensity** in the IoT Cloud Dashboard.
3. Install necessary **Arduino Libraries** (`ArduinoIoTCloud`, `Arduino_LED_Matrix`).
4. Update `arduino_secrets.h` with Wi-Fi credentials.
5. Upload the sketch to the **Arduino Board**.

## Usage

- Use the **Arduino IoT Cloud Dashboard** to **turn ON/OFF** the light.
- Adjust brightness and monitor real-time changes.
- View debug messages using the **Serial Monitor**.

## Debugging

- Enable `setDebugMessageLevel(2)` for more detailed logs.
- Use `Serial.println()` to print values for troubleshooting.
