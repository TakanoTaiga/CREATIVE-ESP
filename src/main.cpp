#include <Arduino.h>
#include <WiFi.h>
#include "creative_esp/network.hpp"

const std::string SSID = "TEST_ESP";
const std::string Passowrd = "123456789";

void setup() {
  creative_esp::newtwork::begin_ap(SSID.c_str() , Passowrd.c_str());
}

void loop() {
}