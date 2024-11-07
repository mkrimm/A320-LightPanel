/*
 * File: logger.cpp
 * File Created: Saturday, 9th December 2023 02:22:00
 * Author: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Last Modified: Thursday, 7th November 2024 07:40:37 pm
 * Modified By: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Copyright (c) 2023 MK Lab & Martin Krimm
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 */

#include "utility/logger.h"

/**
 * @brief Generate the message for logging on serial
 * @param level
 * @param msg
 * @return std::string generated message for logging
 */
String Logger::GenerateMsgAsString(LogLevel level, String msg) {
  unsigned long uptime{millis()};
  unsigned long seconds{static_cast<unsigned long>(uptime / 1000)};
  unsigned long minutes{static_cast<unsigned long>(seconds / 60)};
  unsigned long hours{static_cast<unsigned long>(minutes / 60)};
  unsigned long days{static_cast<unsigned long>(hours / 24)};

  // Range protection
  seconds = seconds % 60;
  minutes = minutes % 60;
  hours = hours % 24;

  char buffer[80]{};
  snprintf(buffer,
            sizeof(buffer),
            "%02ludays %02lu:%02lu:%02lu",
            days,
            hours,
            minutes,
            seconds);

  // strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
  String strTime(buffer);

  switch (level) {
    case DEBUG:
      return String("\e[32m" + strTime + " DEBUG " + prefix_
                      + ": " + msg + "\e[0m");
      break;
    case INFO:
      return String("\e[97m" + strTime + " INFO " + prefix_
                      + ": " + msg + "\e[0m");
      break;
    case WARN:
      return String("\e[93m" + strTime + " WARN " + prefix_
                      + ": " + msg + "\e[0m");
      break;
    case ERROR:
      return String("\e[91m" + strTime + " ERROR " + prefix_
                      + ": " + msg + "\e[0m");
      break;
    case NONE:
      break;
  }
return String{'\0'};
}

/**
 * @brief This function convert the String log msg into a char array
 * @param log_msg the message which should converted
 * @param msg_as_char the char array which receives the string value
 */
void Logger::ConvertMsgToChar(String log_msg, char *msg_as_char) {
  // assigning value to string s
    String s(log_msg);

    // copying the contents of the
    // string to char array
    strcpy(msg_as_char, s.c_str());
}


/**
 * @brief This function return the given log level as string
 * @param level level to convert into string
 * @return std::string the log level as string
 */
String Logger::getLogLevelAsString(LogLevel level) {
  String level_as_string{};

  switch (level) {
    case DEBUG:
      level_as_string = "DEBUG";
      break;
    case INFO:
      level_as_string = "INFO";
      break;
    case WARN:
      level_as_string = "WARN";
      break;
    case ERROR:
      level_as_string = "ERROR";
      break;
    case NONE:
      level_as_string = "NONE";
      break;
  }

  return level_as_string;
}


/**
 * @brief Set the log level
 * @param level
 */
void Logger::setLogLevel(LogLevel level) {
  log_level_ = level;
  Info("Set log level for module %s to level %s", prefix_.c_str(), getLogLevelAsString(level).c_str());
}


/**
 * @brief Create a log message on level DEBUG
 * @param msg the log message
 */
int Logger::Debug(const char *msg, ...) {
  int ret{};
  if (log_level_ < INFO) {
    // Read message
    char msg_result[500];
    va_list args;
    va_start(args, msg);
    ret = vsprintf(msg_result, msg, args);
    va_end(args);

    // Create message
    String msg_str(GenerateMsgAsString(DEBUG, msg_result));
    char msg_char_array[msg_str.length() + 1];
    ConvertMsgToChar(msg_str, msg_char_array);

    Serial.println(msg_char_array);
  }
  return ret;
}


/**
 * @brief Create a log message on level INFO
 * @param msg the log message
 */
int Logger::Info(const char *msg, ...) {
  int ret{};
  if (log_level_ < WARN) {
    // Read message
    char msg_result[500];
    va_list args;
    va_start(args, msg);
    ret = vsprintf(msg_result, msg, args);
    va_end(args);

    // Create message
    String msg_str(GenerateMsgAsString(INFO, msg_result));
    char msg_char_array[msg_str.length() + 1];
    ConvertMsgToChar(msg_str, msg_char_array);

    Serial.println(msg_char_array);
  }
return ret;
}


/**
 * @brief  Create a log message on level WARNING
 * @param msg the log message
 */
int Logger::Warn(const char *msg, ...) {
  int ret{};
  if (log_level_ < ERROR) {
    // Read message
    char msg_result[500];
    va_list args;
    va_start(args, msg);
    ret = vsprintf(msg_result, msg, args);
    va_end(args);

    // Create message
    String msg_str(GenerateMsgAsString(WARN, msg_result));
    char msg_char_array[msg_str.length() + 1];
    ConvertMsgToChar(msg_str, msg_char_array);

    Serial.println(msg_char_array);
  }
return ret;
}


/**
 * @brief Create a log message on level ERROR
 * @param msg the log message
 */
int Logger::Error(const char *msg, ...) {
  int ret{};
  if (log_level_ < NONE) {
    // Read message
    char msg_result[256];
    va_list args;
    va_start(args, msg);
    ret = vsprintf(msg_result, msg, args);
    va_end(args);

    // Create message
    String msg_str(GenerateMsgAsString(ERROR, msg_result));
    char msg_char_array[msg_str.length() + 1];
    ConvertMsgToChar(msg_str, msg_char_array);

    Serial.println(msg_char_array);
  }
return ret;
}