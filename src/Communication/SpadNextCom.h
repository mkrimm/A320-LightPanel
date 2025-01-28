/*
 * File: SpadNextCom.h
 * File Created: Sunday, 26th January 2025 05:46:15
 * Author: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Last Modified: Tuesday, 28th January 2025 02:27:49 pm
 * Modified By: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Copyright (c) 2025 MK Lab & Martin Krimm
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 * 28-01-2025	MK	Init deployment
 */

#ifndef COM_SPADNEXT_H_
#define COM_SPADNEXT_H_

#include <CmdMessenger.h>

class SpadNextCom {
private:
  // Create a CmdMessenger object
  CmdMessenger cmd_messenger_;

  // Pin assignments
  const size_t button_num_{};
  int         *button_pins_{};
  const size_t led_num_{};
  int         *led_pins_{};

  // Command IDs
  enum SerialCommands {
    kInit,        // Initialization command
    kSetLed,      // Command to set LED state
    kButtonPress  // Command to notify SPAD.neXt of button states
  };

  static SpadNextCom *instance_;
  void HandleMessage();

public:
  SpadNextCom(Stream &serial_port, const int &button_num, const int &led_num);
  static void StaticHandleMessage();
  int ModuleLoop(int *button_values, int *led_values);
};

#endif /* COM_SPADNEXT_H_ */