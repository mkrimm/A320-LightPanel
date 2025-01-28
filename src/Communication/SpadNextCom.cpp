/*
 * File: SpadNextCom.cpp
 * File Created: Sunday, 26th January 2025 05:46:13
 * Author: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Last Modified: Tuesday, 28th January 2025 02:27:42 pm
 * Modified By: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Copyright (c) 2025 MK Lab & Martin Krimm
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 * 28-01-2025	MK	Init deployment
 */

#include "SpadNextCom.h"

// Initialize the static instance pointer
SpadNextCom *SpadNextCom::instance_{nullptr};

/**
 * @brief SpadNextCom::HandleMessage
 * Handle incoming LED messages
 */
void SpadNextCom::HandleMessage() {
  int command{cmd_messenger_.readInt16Arg()};
  switch (command) {
    case SerialCommands::kInit : {
      // Initialize the LED pins
      for (size_t i = 0; i < led_num_; ++i) {
        led_pins_[i] = 0;
      }
      break;
    }
    case SerialCommands::kSetLed : {
      int ledIndex{cmd_messenger_.readInt16Arg()};
      int ledState{cmd_messenger_.readInt16Arg()};
      printf("LED: %d, State: %d\n", ledIndex, ledState);
      if (ledIndex >= 0 && ledIndex < static_cast<int>(led_num_)) {
        led_pins_[ledIndex] = ledState;
      }
      break;
    }
  }
}


/**
 * @brief SpadNextCom::ModuleLoop
 * Main loop of the SpadNext communcation module
 * @param button_values - array of button values
 * @param led_values - array of led values
 * @return int - non-zero if an error occurred
 */
int SpadNextCom::ModuleLoop(int *button_values, int *led_values) {
  int ret{};
  // Send button values
  cmd_messenger_.sendCmdStart(SerialCommands::kButtonPress);
  for (size_t i = 0; i < button_num_; ++i)
    cmd_messenger_.sendCmdArg(button_values[i]);
  cmd_messenger_.sendCmdEnd();

  return ret;
}


/**
 * @brief SpadNextCom::StaticHandleMessage
 * static function to handle incoming serial commands
 */
void SpadNextCom::StaticHandleMessage() {
  // Use the instance pointer to call the member function
  if (instance_) {
    instance_->HandleMessage();
  }
}


/**
 * @brief SpadNextCom::SpadNextCom
 * Constructor for the SpadNextCom class
 * @param serial_port - Serial port to use for communication
 */
SpadNextCom::SpadNextCom(Stream &serial_port,
                        const int &button_num,
                        const int &led_num)
    : cmd_messenger_(serial_port),
      button_num_(button_num),
      led_num_(led_num) {
  // Set the instance pointer to this instance
  instance_ = this;

  // Attach static callback for received commands
  cmd_messenger_.attach(StaticHandleMessage);
}