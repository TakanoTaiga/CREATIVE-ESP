#include <Arduino.h>
#include <WiFi.h>
#include <vector>
#include "utilization/macro.hpp"
#include "utilization/loop_macro.hpp"

namespace cl = creative_esp::loop;

namespace creative_esp{
namespace newtwork{
    CESP_WIFI_MODE begin_scan(){
        WiFi.mode(WIFI_STA);
        WiFi.disconnect();
        delay(100);
        return CEST_WIFI_OK;
    }

    CESP_WIFI_MODE begin_connect_sync(
        const char* ssid ,const char* password ,CESP_IS_SERIAL_BEGIN status){
        WiFi.begin(ssid,password);

        for(auto _ : cl::Loop10){
            if(WiFi.status() == WL_CONNECTED){return CEST_WIFI_OK;}
            if(status == CESP_SERIAL_STATUS_STARTED){
                Serial.print(".");
            }
            delay(500);
        }
        return CEST_WIFI_ERROR;
    }

    CESP_WIFI_MODE begin_ap(
        const char* ssid ,const char* password){
            WiFi.softAP(ssid,password);
            return CESP_SERIAL_STATUS_STARTED;
        }
}
}