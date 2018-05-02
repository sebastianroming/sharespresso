#ifndef MQTT_H
#define MQTT_H

#include "Arduino.h";
#include <PubSubClient.h>;
#include <ESP8266WiFi.h>;
#include "settings.h"
#include "IMessageBroker.h"

class MqttService : public IMessageBroker {
    private:
      WiFiClient espClient;
      PubSubClient mqttClient;
  
    public:
        MqttService();
        
        void init(MQTT_CALLBACK_SIGNATURE);
        void loop();
        void reconnect();
        void publish(String message);
        void sendmessage(const String cardId, const String product, const int price); 
};
#endif
