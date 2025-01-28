/*
 * File: main.cpp
 * File Created: Sunday, 3rd November 2024 11:13:39
 * Author: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Last Modified: Tuesday, 28th January 2025 02:34:28 pm
 * Modified By: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Copyright (c) 2024 MK Lab & Martin Krimm
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 * 28-01-2025	MK	Update to new SpadNext serial communication
 */
#include "main.h"


/**
 * @brief SetBacklight
 * @param value - value for the backlight
 */
void SetBacklight(int value) {
  analogWrite(kBackLightPin, value);
}


/**
 * @brief initPins
 * Initialize the arduino IO-pins
 */
void InitPins() {
  // Initialize multiplexer input pins
  pinMode(kMultiplexer1S0, INPUT);
  pinMode(kMultiplexer1S1, INPUT);
  pinMode(kMultiplexer1S2, INPUT);
  pinMode(kMultiplexer2S0, INPUT);
  pinMode(kMultiplexer2S1, INPUT);
  pinMode(kMultiplexer2S2, INPUT);
  pinMode(kMultiplexer3S0, INPUT);
  pinMode(kMultiplexer3S1, INPUT);
  pinMode(kMultiplexer3S2, INPUT);

  // Initialize multiplexer output pins
  pinMode(kMultiplexer4S0, OUTPUT);
  pinMode(kMultiplexer4S1, OUTPUT);
  pinMode(kMultiplexer4S2, OUTPUT);
  pinMode(kMultiplexer5S0, OUTPUT);
  pinMode(kMultiplexer5S1, OUTPUT);
  pinMode(kMultiplexer5S2, OUTPUT);

  // Initialize other pins
  pinMode(kBtnExtPwr, INPUT);
  pinMode(kBackLightPin, OUTPUT);
}


void setup() {
  delay(1000);

  Serial.begin(kSerialBaudRate);
  Serial.println();

#ifdef DEBUG
  Serial.println("Debug Mode");
#endif

  // Setup IO-pins
  InitPins();

  // Setup modules
  spad_next_com_ = new SpadNextCom(Serial, kButtonNum, kLedNum);

  SetBacklight(0);
}

void loop() {
  // int switch_analoge_values[8]{};

  spad_next_com_->ModuleLoop(button_values_, led_values_);

#ifdef DEBUG
  // LED values
  Serial.println("Eval LED values: " + String(millis()));
  for (size_t i = 0; i < kLedNum; ++i){
    Serial.println("LED " + String(kLedName[i]) + " value: "
                    + String(led_values_[i]));
  }
  // Button values
  Serial.println("Eval buttons: " + String(millis()));
  for (size_t i = 0; i < kButtonNum; ++i){
    Serial.println("Button " + String(kButtonName[i]) + " value: "
                    + String(button_values_[i]));
  }
#endif

  delay(25);
}