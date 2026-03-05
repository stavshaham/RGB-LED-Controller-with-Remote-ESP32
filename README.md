# ESP32 RGB LED Controller with IR Remote

An ESP32-based RGB LED controller that uses an infrared remote for real-time color and brightness control.  
Supports single-press actions, hold acceleration, gamma correction, and smooth color transitions using non-blocking timing.

---

## 🚀 Features

- IR remote decoding (ESP32 + IR receiver)
- Single-press brightness adjustment
- Hold-to-increase with acceleration
- Non-blocking timing using `millis()`
- Gamma correction for realistic brightness
- Exponential smoothing for smooth color transitions
- Modular C++ architecture (`.h` / `.cpp` separation)
- Clean separation of concerns

---

## 🧠 What This Project Demonstrates

- Embedded systems timing without `delay()`
- State management in microcontrollers
- IR protocol decoding
- PWM control using ESP32 `ledcWrite`
- C++ modularization and proper header/source structure
- Debugging linker and constant-expression errors

---

## 🛠 Hardware Requirements

- ESP32 development board
- IR receiver module
- RGB LED (common cathode recommended)
- 3 current-limiting resistors
- IR remote control

---

## 🔌 Pin Configuration

| Component     | GPIO |
|--------------|------|
| Red LED      | 21   |
| Green LED    | 22   |
| Blue LED     | 23   |
| IR Receiver  | 15   |

*(Pins can be modified in `Constants.h`)*

---

## 🎮 Remote Behavior

- **Power Button** → Turn off all colors
- **Plus Button (Single Press)** → Increase brightness by 1
- **Plus Button (Hold)** → Accelerated brightness increase
- Acceleration increases step size the longer the button is held
- Values are capped at a maximum (4095)

---

## 📂 Project Structure

LED/
├── LED.ino
├── Constants.h
├── Constants.cpp
├── LEDController.h
├── LEDController.cpp
├── RemoteControl.h
├── RemoteControl.cpp

---


### Architecture Overview

- `LEDController` → Handles smoothing, gamma correction, PWM output
- `RemoteControl` → Handles IR decoding and button logic
- `Constants` → Shared configuration and global state
- `LED.ino` → Main loop and system initialization

---

## 🔄 How Hold Acceleration Works

- Detects `results.repeat` from IR receiver
- Uses `millis()` to track hold duration
- Step size increases over time
- Clamped to prevent overflow

This ensures smooth, responsive behavior without blocking the main loop.

---

## 📈 Future Improvements

- Add color selection (R/G/B toggle)
- Add preset color modes
- Save last color to EEPROM
- Convert to reusable Arduino library
- Add fade animations

---

## 📜 License

MIT License (or choose your preferred license)

---

## 💡 Author

Built as part of my embedded systems learning journey using ESP32 and C++.
