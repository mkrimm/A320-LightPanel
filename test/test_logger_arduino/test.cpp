/*
 * File: test.cpp
 * File Created: Thursday, 7th November 2024 06:50:35
 * Author: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Last Modified: Thursday, 7th November 2024 07:35:33 pm
 * Modified By: Martin Krimm (krimmmartin@gmail.com)
 * -----
 * Copyright (c) 2024 MK Lab & Martin Krimm
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 */

#include "unity.h"
#include "../../src/utility/logger.h"

Logger logger_("TEST");

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_function_generateMsgAsString(void) {
  Logger logger_("TEST");
  TEST_ASSERT_EQUAL_UINT8(0, logger_.Debug("Test"));
}

void test_function_should_doAlsoDoBlah(void) {
  // more test stuff
}

int runUnityTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_function_generateMsgAsString);
  RUN_TEST(test_function_should_doAlsoDoBlah);
  return UNITY_END();
}

/**
  * For Arduino framework
  */
void setup() {
  // Wait ~2 seconds before the Unity test runner
  // establishes connection with a board Serial interface
  delay(2000);

  runUnityTests();
}
void loop() {}