#include <Arduino.h>

#include <Mouse.h>
#include <WiFiS3.h>

#include <hid_report.hpp>

#include "config.hpp"

int wifi_status = WL_IDLE_STATUS;
char packet_buffer[256];
WiFiUDP wifi_udp;

HIDReportMouseParser hid_mouse_parser;

void setup() {
  Serial.begin(9600);

  delay(1000);

  while (wifi_status != WL_CONNECTED) {
    wifi_status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    delay(100);
  }

  wifi_udp.begin(UDP_PORT);

  Mouse.begin();
  hid_mouse_parser.initialize();
}

void loop() {
  auto [mouse_button_left, mouse_button_right, mouse_button_middle, mouse_button_4, mouse_button_5, dx, dy, dz] = hid_mouse_parser.parse_report();

  Mouse.move(dx, dy, dz);
}