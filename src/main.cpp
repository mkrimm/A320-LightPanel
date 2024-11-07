/*
 * File: main.cpp
 * File Created: Sunday, 3rd November 2024 11:13:39
 * Author: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Last Modified: Monday, 4th November 2024 03:53:27 pm
 * Modified By: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Copyright (c) 2024 MK Lab & Martin Krimm
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 */
#include "main.h"


/**
 * @brief ReadAnalogeSwitchValues
 * @param analog_values - array of analoge values
 */
void ReadAnalogeSwitchValues(int *analog_values) {
  analog_values[kStrobeF] = analogRead(kStrobePin);
  analog_values[kBeaconF] = analogRead(kBeaconPin);
  analog_values[kWingF] = analogRead(kWingPin);
  analog_values[kNavLogoF] = analogRead(kNavLogoPin);
  analog_values[kRwyTurnF] = analogRead(kRwyTurnOffPin);
  analog_values[kLandLF] = analogRead(kLandLPin);
  analog_values[kLandRF] = analogRead(kLandRPin);
  analog_values[kNoseF] = analogRead(kNosePin);
}


/**
 * @brief EvalSwitchStates
 * @param pin_values - array of analoge values
 * @param button_values - array of button values
 */
void EvalSwitchStates(int *pin_values, bool *button_values) {
  // ---------------------------------------------------------------------------
  // Eval Strobe switch
  // ---------------------------------------------------------------------------
  // Strobe On
  if ((pin_values[kStrobeF] <= kResistorValueMaxTol)
     && (pin_values[kStrobeF] >= kResistorValueMinTol)) {
      button_values[kStrobeOn]    = true;
      button_values[kStrobeAuto]  = false;
      button_values[kStrobeOff]   = false;
  }
  // Strobe Auto
  else if (pin_values[kStrobeF] <= kMinValue) {
    button_values[kStrobeOn]    = false;
    button_values[kStrobeAuto]  = true;
    button_values[kStrobeOff]   = false;
  }
  // Strobe Off
  else if (pin_values[kStrobeF] >= kMaxValue) {
    button_values[kStrobeOn]    = false;
    button_values[kStrobeAuto]  = false;
    button_values[kStrobeOff]   = true;
  }

  // ---------------------------------------------------------------------------
  // Eval Beacon switch
  // ---------------------------------------------------------------------------
  // Beacon On
  if (pin_values[kBeaconF] <= kMinValue) {
    button_values[kBeaconOn]  = true;
    button_values[kBeaconOff] = false;
  }
  // Beacon Off
  else if (pin_values[kBeaconF] >= kMaxValue) {
    button_values[kBeaconOn]  = false;
    button_values[kBeaconOff] = true;
  }

  // ---------------------------------------------------------------------------
  // Eval Wing switch
  // ---------------------------------------------------------------------------
  // Wing On
  if (pin_values[kWingF] <= kMinValue) {
    button_values[kWingOn]  = true;
    button_values[kWingOff] = false;
  }
  // Wing Off
  else if (pin_values[kWingF] >= kMaxValue) {
    button_values[kWingOn]  = false;
    button_values[kWingOff] = true;
  }

  // ---------------------------------------------------------------------------
  // Eval Nav & Logo switch
  // ---------------------------------------------------------------------------
  // Nav & Logo 2
  if ((pin_values[kNavLogoF] <= kResistorValueMaxTol)
     && (pin_values[kNavLogoF] >= kResistorValueMinTol)) {
    button_values[kNavLogo2]    = true;
    button_values[kNavLogo1]    = false;
    button_values[kNavLogoOff]  = false;
  }
  // Nav & Logo 1
  else if (pin_values[kNavLogoF] <= kMinValue) {
    button_values[kNavLogo2]    = false;
    button_values[kNavLogo1]    = true;
    button_values[kNavLogoOff]  = false;
  }
  // Nav & Logo Off
  else if (pin_values[kNavLogoF] >= kMaxValue) {
    button_values[kNavLogo2]    = false;
    button_values[kNavLogo1]    = false;
    button_values[kNavLogoOff]  = true;
  }

  // ---------------------------------------------------------------------------
  // Eval Rwy Turn Off switch
  // ---------------------------------------------------------------------------
  // Rwy Turn Off On
  if (pin_values[kRwyTurnF] <= kMinValue) {
    button_values[kRwyTurnOn]   = true;
    button_values[kRwyTurnOff]  = false;
  }
  // Rwy Turn Off Off
  else if (pin_values[kRwyTurnF] >= kMaxValue) {
    button_values[kRwyTurnOn]   = false;
    button_values[kRwyTurnOff]  = true;
  }

  // ---------------------------------------------------------------------------
  // Eval Landing Left switch
  // ---------------------------------------------------------------------------
  // Landing Left On
  if ((pin_values[kLandLF] <= kResistorValueMaxTol)
     && (pin_values[kLandLF] >= kResistorValueMinTol)) {
    button_values[kLandingLOn]      = true;
    button_values[kLandingLOff]     = false;
    button_values[kLandingLRetract] = false;
  }
  // Landing Left Off
  else if (pin_values[kLandLF] <= kMinValue) {
    button_values[kLandingLOn]      = false;
    button_values[kLandingLOff]     = true;
    button_values[kLandingLRetract] = false;
  }
  // Landing Left Retract
  else if (pin_values[kLandLF] >= kMaxValue) {
    button_values[kLandingLOn]      = false;
    button_values[kLandingLOff]     = false;
    button_values[kLandingLRetract] = true;
  }

  // ---------------------------------------------------------------------------
  // Eval Landing Right switch
  // ---------------------------------------------------------------------------
  // Landing Right On
  if ((pin_values[kLandRF] <= kResistorValueMaxTol)
     && (pin_values[kLandRF] >= kResistorValueMinTol)) {
    button_values[kLandingROn]      = true;
    button_values[kLandingROff]     = false;
    button_values[kLandingRRetract] = false;
  }
  // Landing Right Off
  else if (pin_values[kLandRF] <= kMinValue) {
    button_values[kLandingROn]      = false;
    button_values[kLandingROff]     = true;
    button_values[kLandingRRetract] = false;
  }
  // Landing Right Retract
  else if (pin_values[kLandRF] >= kMaxValue) {
    button_values[kLandingROn]      = false;
    button_values[kLandingROff]     = false;
    button_values[kLandingRRetract] = true;
  }

  // ---------------------------------------------------------------------------
  // Eval Nose switch
  // ---------------------------------------------------------------------------
  // Nose TO
  if ((pin_values[kNoseF] <= kResistorValueMaxTol)
     && (pin_values[kNoseF] >= kResistorValueMinTol)) {
    button_values[kNoseTo]    = true;
    button_values[kNoseTaxi]  = false;
    button_values[kNoseOff]   = false;
  }
  // Nose Taxi
  else if (pin_values[kNoseF] <= kMinValue) {
    button_values[kNoseTo]    = false;
    button_values[kNoseTaxi]  = true;
    button_values[kNoseOff]   = false;
  }
  // Nose Off
  else if (pin_values[kNoseF] >= kMaxValue) {
    button_values[kNoseTo]    = false;
    button_values[kNoseTaxi]  = false;
    button_values[kNoseOff]   = true;
  }
}


/**
 * @brief SetJoystickButton
 * @param buttons - array of button values
 */
void SetJoystickButton(bool *buttons) {
  // Set Joystick button
  for (size_t i = 0; i < 21; ++i) {
#ifdef DEBUG
  Serial.println("Joystick button " + String(kButtonName[i+1]) + " value: "
                + String(buttons[i+1]));
#endif
    joystick_.setButton(i, buttons[i+1]);
  }
}


/**
 * @brief SetBacklight
 * @param value - value for the backlight
 */
void SetBacklight(int value) {
  analogWrite(kBackLightPin, value);
}


void setup() {
  delay(1000);

  Serial.begin(57600);
  Serial.println();

#ifdef DEBUG
  Serial.println("Debug Mode");
#endif

  // Initialize Joystick Library
  if (kAutoSendMode)
    joystick_.begin();
  else
    joystick_.begin(false);

  // Set LED pin as output
  pinMode(kBackLightPin, OUTPUT);

  SetBacklight(0);
}

void loop() {
  int switch_analoge_values[8]{};

  // Read analoge values
  ReadAnalogeSwitchValues(switch_analoge_values);
#ifdef DEBUG
  Serial.println("Loop count: " + String(millis()));
  // for (size_t i = 0; i < sizeof(switch_analoge_values_); ++i){
  for (size_t i = 0; i < 8; ++i){
    Serial.println("Input " + String(kPinName[i]) + " analoge value: "
                    + String(switch_analoge_values[i]));
  }
#endif

  // Eval switches
  EvalSwitchStates(switch_analoge_values, button_values_);
#ifdef DEBUG
  Serial.println("Loop count: " + String(millis()));
  for (size_t i = 0; i < sizeof(button_values_); ++i){
  // for (size_t i = 1; i < 4; ++i){
    Serial.println("Button " + String(kButtonName[i]) + " value: "
                    + String(button_values_[i]));
  }
#endif

  if (button_values_[kNavLogo1])
    SetBacklight(255);
  else if (button_values_[kNavLogoOff])
    SetBacklight(0);

  // Set Joystick button
  SetJoystickButton(button_values_);

  delay(25);
}