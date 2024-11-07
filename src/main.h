/*
 * File: main.h
 * File Created: Monday, 4th November 2024 09:58:24
 * Author: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Last Modified: Thursday, 7th November 2024 09:52:42 am
 * Modified By: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Copyright (c) 2024 MK Lab & Martin Krimm
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 */
#include <Joystick.h>
// #define DEBUG

// HID report id = 0x05; you can also use JOYSTICK_DEFAULT_REPORT_ID
Joystick_ joystick_(0x05,
  JOYSTICK_TYPE_JOYSTICK, 21, 0,
  false, false, false, false, false, false,
  false, false, false, false, false);

static constexpr bool kAutoSendMode{true};

// Analoge input values
static constexpr int kResistorValue{580};
static constexpr int kResistorToleranz{static_cast<int>(
                                        static_cast<float>(kResistorValue)
                                        * 0.2f)};
static constexpr int kResistorValueMaxTol{kResistorValue
                                          + kResistorToleranz};
static constexpr int kResistorValueMinTol{kResistorValue
                                          - kResistorToleranz};
static constexpr int kMaxValue{1000};
static constexpr int kMinValue{50};

static constexpr int kStrobeF{0};
static constexpr int kBeaconF{1};
static constexpr int kWingF{2};
static constexpr int kNavLogoF{3};
static constexpr int kRwyTurnF{4};
static constexpr int kLandLF{5};
static constexpr int kLandRF{6};
static constexpr int kNoseF{7};

static constexpr const char* kPinName[9]{"Strobe",
                                         "Beacon",
                                         "Wing",
                                         "Nav&Logo",
                                         "RwyTurnOff",
                                         "LandL",
                                         "LandR",
                                         "Nose",
                                         "Backlight"};
static constexpr const char* kButtonName[22]{"",
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
                                             "Nose_Off"};



// Constant that maps the phyical pin to the joystick button
static constexpr int kNosePin{A0};
static constexpr int kRwyTurnOffPin{A1};
static constexpr int kBeaconPin{A2};
static constexpr int kWingPin{A3};
static constexpr int kStrobePin{A6};
static constexpr int kNavLogoPin{A7};
static constexpr int kLandLPin{A8};
static constexpr int kLandRPin{A9};
static constexpr int kBackLightPin{A10};

// Joystick button numbers
// Strobe switch
static constexpr int kStrobeOn{1};
static constexpr int kStrobeAuto{2};
static constexpr int kStrobeOff{3};

// Beacon switch
static constexpr int kBeaconOn{4};
static constexpr int kBeaconOff{5};

// Wing switch
static constexpr int kWingOn{6};
static constexpr int kWingOff{7};

// Nav & Logo switch
static constexpr int kNavLogo2{8};
static constexpr int kNavLogo1{9};
static constexpr int kNavLogoOff{10};

// Rwy turn off switch
static constexpr int kRwyTurnOn{11};
static constexpr int kRwyTurnOff{12};

// Landing switch
static constexpr int kLandingLOn{13};
static constexpr int kLandingLOff{14};
static constexpr int kLandingLRetract{15};
static constexpr int kLandingROn{16};
static constexpr int kLandingROff{17};
static constexpr int kLandingRRetract{18};

// Nose switch
static constexpr int kNoseTo{19};
static constexpr int kNoseTaxi{20};
static constexpr int kNoseOff{21};

// Buttons
bool button_values_[22]{};