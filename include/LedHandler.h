//
// Created by felix on 14.03.25.
//

#ifndef LEDHANDLER_H
#define LEDHANDLER_H

#include "ESPAsyncWebServer.h"
#include "ArduinoJson.h"
#include <LedStripeOnPin.h>
#include <Adafruit_NeoPixel.h>
#include "WebServerManager.h"

class LedHandler {
public:


private:

};

void handlePinListGet(AsyncWebServerRequest *request);
void handleGet(AsyncWebServer* server);
void handlePost(AsyncWebServerRequest *request, JsonObject &jsonObject);
void handleDelete(AsyncWebServerRequest *request, JsonObject &jsonObject);
void setColor(uint32_t color);
uint32_t wheel(byte wheelPos);
[[noreturn]] void animationSet(void *parameter);

std::vector<LedStripeOnPin *> ledStripeOnPinList;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(0, 0, NEO_RGBW + NEO_KHZ800);
TaskHandle_t AnimationTask;

#endif //LEDHANDLER_H
