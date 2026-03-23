#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>

// Array size (RGB)
constexpr int SIZE = 3;

// GPIO Pins
constexpr unsigned int RED_LED = 21;
constexpr unsigned int GREEN_LED = 22;
constexpr unsigned int BLUE_LED = 23;
constexpr uint16_t recvPin = 27;

// Remote values
constexpr unsigned int POWER_BUTTON = 0xFFA25D;
constexpr unsigned int PLUS_BUTTON = 0xFF02FD;
constexpr unsigned int MINUS_BUTTON = 0xFF9867;
constexpr unsigned int NEXT_BUTTON = 0xFF906F;
constexpr unsigned int PREVIOUS_BUTTON = 0xFFE01F;
constexpr unsigned int ONE_BUTTON = 0xFF30CF;
constexpr unsigned int TWO_BUTTON = 0xFF18EF;
constexpr unsigned int THREE_BUTTON = 0xFF7A85;
constexpr unsigned int HOLD_BUTTON = 0xFFFFFFFF;

// Limits & tuning
constexpr int MAX_VALUE = 4095;
constexpr int MIN_VALUE = 0;
constexpr unsigned long HOLD_INTERVAL = 120;
constexpr float SMOOTHING = 0.08;
constexpr float GAMMA = 2.2;
constexpr float RATIO = (4095/256);

// Shared state
extern int currentChannel;
extern int rawValues[SIZE];

#endif