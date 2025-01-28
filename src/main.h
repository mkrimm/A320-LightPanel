/*
 * File: main.h
 * File Created: Monday, 4th November 2024 09:58:24
 * Author: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Last Modified: Tuesday, 28th January 2025 02:34:40 pm
 * Modified By: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Copyright (c) 2024 MK Lab & Martin Krimm
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 * 28-01-2025	MK	Update to new SpadNext serial communication
 */

#include <Arduino.h>

#include "Communication/SpadNextCom.h"

#define DEBUG

// Serial baud rate
static constexpr long kSerialBaudRate{115200};

// Constant that maps the phyical pin to the joystick button
static constexpr int kMultiplexer1S0{0};  // Button multiplexer 1 --> Input
static constexpr int kMultiplexer1S1{1};  // Button multiplexer 1 --> Input
static constexpr int kMultiplexer1S2{2};  // Button multiplexer 1 --> Input
static constexpr int kMultiplexer2S0{3};  // Button multiplexer 2 --> Input
static constexpr int kMultiplexer2S1{4};  // Button multiplexer 2 --> Input
static constexpr int kMultiplexer2S2{5};  // Button multiplexer 2 --> Input
static constexpr int kMultiplexer3S0{6};  // Button multiplexer 3 --> Input
static constexpr int kMultiplexer3S1{7};  // Button multiplexer 3 --> Input
static constexpr int kMultiplexer3S2{8};  // Button multiplexer 3 --> Input
static constexpr int kMultiplexer4S0{9};  // LED multiplexer 1 --> Output
static constexpr int kMultiplexer4S1{10}; // LED multiplexer 1 --> Output
static constexpr int kMultiplexer4S2{16}; // LED multiplexer 1 --> Output
static constexpr int kMultiplexer5S0{14}; // LED multiplexer 2 --> Output
static constexpr int kMultiplexer5S1{15}; // LED multiplexer 2 --> Output
static constexpr int kMultiplexer5S2{18}; // LED multiplexer 2 --> Output
static constexpr int kBtnExtPwr{19};      // External power button --> Input
static constexpr int kBackLightPin{20};   // Backlight pin --> Output

static constexpr const char* kPinName[17]{"U1.S0",
                                          "U1.S1",
                                          "U1.S2",
                                          "U2.S0",
                                          "U2.S1",
                                          "U2.S2",
                                          "U3.S0",
                                          "U3.S1",
                                          "U3.S2",
                                          "U4.S0",
                                          "U4.S1",
                                          "U4.S2",
                                          "U5.S0",
                                          "U5.S1",
                                          "U5.S2",
                                          "BtnExtPwr",
                                          "Backlight"};

static constexpr int kButtonNum{35};
static constexpr const char* kButtonName[kButtonNum]{"",
                                             "Strobe_On",
                                             "Strobe_Auto",
                                             "Strobe_Off",
                                             "Beacon_On",
                                             "Beacon_Off",
                                             "Wing_On",
                                             "Wing_Off",
                                             "Nav&Logo_2",
                                             "Nav&Logo_1",
                                             "Nav&Logo_Off",
                                             "RwyTurnOff_On",
                                             "RwyTurnOff_Off",
                                             "LandL_On",
                                             "LandL_Off",
                                             "LandL_Retract",
                                             "LandR_On",
                                             "LandR_Off",
                                             "LandR_Retract",
                                             "Nose_To",
                                             "Nose_Taxi",
                                             "Nose_Off",
                                             "ExtPwr",
                                             "ApuBleed",
                                             "ApuMasterSwitch",
                                             "ApuStart",
                                             "SeatBeltOn",
                                             "SeatBeltOff",
                                             "SeatBeltAuto",
                                             "NoSmokingOn",
                                             "NoSmokingOff",
                                             "NoSmokingAuto",
                                             "AntiIceWing",
                                             "AntiIceEng1",
                                             "AntiIceEng2"};
int button_values_[kButtonNum]{};

static constexpr int kLedNum{15};
static constexpr const char* kLedName[kLedNum]{"ExtPwrAvail",
                                         "ExtPwrOn",
                                         "ApuMasterFault",
                                         "ApuMasterOn",
                                         "ApuStartAvail",
                                         "ApuStartOn",
                                         "ApuBleedFault",
                                         "ApuBleedOn",
                                         "AntiIceWingFault",
                                         "AntiIceWingOn",
                                         "AntiIceEng1Fault",
                                         "AntiIceEng1On",
                                         "AntiIceEng2Fault",
                                         "AntiIceEng2On",
                                         "Backlight"};
int led_values_[kLedNum]{};


SpadNextCom *spad_next_com_{nullptr};
