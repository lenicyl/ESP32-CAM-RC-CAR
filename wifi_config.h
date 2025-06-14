#ifndef WIFI_CONFIG_H
#define WIFI_CONFIG_H

#include "secrets.h"

bool connectToWifi() {
  for (int i = 0; i < NET_COUNT; i++) {
    WiFi.begin(networks[i].ssid, networks[i].password);

    for (int j = 0; j < 10 && WiFi.status() != WL_CONNECTED; j++) {
      delay(500);
      Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("\nWiFi connected");
      Serial.print("Camera Stream Ready! Go to: http://");
      Serial.println(WiFi.localIP());
      return true;
    }
  }
  return false;
}

#endif
