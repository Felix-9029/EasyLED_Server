//
// Created by felix on 20.03.25.
//

#ifndef GARDENDOORHANDLER_H
#define GARDENDOORHANDLER_H

#include "ESPAsyncWebServer.h"
#include "ArduinoJson.h"
#include "Helper.h"
#include "WebServerManager.h"

using namespace std;

class WebServerManager;

class GardenDoorHandler {
public:
    GardenDoorHandler(WebServerManager *webServerManager);
    void handleGetServerType(AsyncWebServerRequest *request);
    void handlePinListGet(AsyncWebServerRequest *request);
    void handleGet(AsyncWebServer* server);
    void handlePost(AsyncWebServerRequest *request, JsonObject &jsonObject);
    void handleDelete(AsyncWebServerRequest *request, JsonObject &jsonObject);

private:
    static void startCountdown(void *pvParameters);

    WebServerManager *_webServerManager;
    bool _stateOn = false;
    int _timeInSec = 10;
    TaskHandle_t _countdownTask = nullptr;
};

#endif //GARDENDOORHANDLER_H
