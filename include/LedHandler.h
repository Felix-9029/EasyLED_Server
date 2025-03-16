//
// Created by felix on 14.03.25.
//

#ifndef LEDHANDLER_H
#define LEDHANDLER_H

#include "ESPAsyncWebServer.h"
#include "ArduinoJson.h"
#include "Helper.h"
#include "LedStripeOnPin.h"
#include "Adafruit_NeoPixel.h"
#include "WebServerManager.h"

using namespace std;

class WebServerManager;

class LedHandler {
public:
    LedHandler(WebServerManager *webServerManager);
    void handlePinListGet(AsyncWebServerRequest *request);
    void handleGet(AsyncWebServer* server);
    void handlePost(AsyncWebServerRequest *request, JsonObject &jsonObject);
    void handleDelete(AsyncWebServerRequest *request, JsonObject &jsonObject);
    [[noreturn]] static void animationSet(void *parameter);

private:
    WebServerManager *webServerManager;
    void setColor(uint32_t color);
    uint32_t wheel(byte wheelPos);

    vector<LedStripeOnPin *> _ledStripeOnPinList;
    Adafruit_NeoPixel _strip = Adafruit_NeoPixel(0, 0, NEO_RGBW + NEO_KHZ800);
    TaskHandle_t _animationTask = nullptr;
};

#endif //LEDHANDLER_H
