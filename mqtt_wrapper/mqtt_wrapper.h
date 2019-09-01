//
// Created by paolo on 25/08/19.
//

#ifndef MOSQUITTO_PUBLISHER_MQTT_WRAPPER_H
#define MOSQUITTO_PUBLISHER_MQTT_WRAPPER_H

#include <iostream>
#include <mosquittopp.h>
#include <cstring>

class mqtt_wrapper {

private:
    const char *id ;
    const char *host;
    int port;
    const char *username;
    const char *password;
    int keepalive;
    const char *topic;

    struct mosquitto *client;

public:
    mqtt_wrapper(const char* _id, const char* _topic, const char* _host, int _port, const char* _username, const char* _password);

    static void on_connected(struct mosquitto *client, void *userdata, int result);
    static void on_disconnected(struct mosquitto *client, void *userdata, int result);
    static void on_publish(struct mosquitto *client, void *userdata, int mid);
    mosquitto *getClient();
    const char* getTopic();


};


#endif //MOSQUITTO_PUBLISHER_MQTT_WRAPPER_H
