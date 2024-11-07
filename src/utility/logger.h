/*
 * File: logger.h
 * File Created: Saturday, 9th December 2023 02:22:04
 * Author: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Last Modified: Thursday, 7th November 2024 05:13:38 pm
 * Modified By: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Copyright (c) 2023 MK Lab & Martin Krimm
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 */

#ifndef TOOLS_LOGGER_H_
#define TOOLS_LOGGER_H_

#include <Arduino.h>
// #include <string>
#include <stdio.h>
#include <stdarg.h>

enum LogLevel {DEBUG, INFO, WARN, ERROR, NONE};

//------------------------------------------------------------------------------
// Class Logger
//------------------------------------------------------------------------------
class Logger {
  public:
    /**
     * @brief Construct a new Logger:: Logger object
     */
    Logger(String class_name,
            LogLevel log_level_ = LogLevel::WARN) : prefix_(class_name) {}
    //enum class LogLevel {DEBUG, INFO, WARN, ERROR, NONE};
    int Debug(const char *msg, ...);
    int Info(const char *msg, ...);
    int Warn(const char *msg, ...);
    int Error(const char *msg, ...);
    void setLogLevel(LogLevel level);

  private:
    String prefix_{};
    LogLevel log_level_{};

    String GenerateMsgAsString(LogLevel level, String msg);
    void ConvertMsgToChar(String log_msg, char *msg_as_char);
    String getLogLevelAsString(LogLevel level);
};
//------------------------------------------------------------------------------

#endif // TOOLS_LOGGER_H_