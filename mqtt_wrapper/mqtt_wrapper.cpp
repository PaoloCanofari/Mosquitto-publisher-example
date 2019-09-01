//
// Created by paolo on 25/08/19.
//

#include <unistd.h>
#include "mqtt_wrapper.h"

void mqtt_wrapper::on_connected(mosquitto *client, void *userdata, int result){

    if(result == 0){
        std::cout << "Connected to broker successfully" << std::endl;
    } else {
        std::cout << "Couldn't connect to broker. \nERROR CODE: " << result << std::endl;
    }

}

void mqtt_wrapper::on_disconnected(struct mosquitto *client, void *userdata, int result){

    std::cout << "Disconnected from broker." << std::endl;

}

void mqtt_wrapper::on_publish(struct mosquitto *client, void *userdata, int mid){
    std::cout << "Message (" << mid << ") successfully sent." << std::endl;
}

mqtt_wrapper::mqtt_wrapper(const char *_id, const char *_topic, const char *_host, int _port, const char *_username,
                           const char *_password) {

    this->id = _id;
    this->topic = _topic;
    this->host = _host;
    this->port = _port;
    this->username = _username;
    this->password = _password;
    this->keepalive = 20;

    mosquitto_lib_init();
    mosquitto_lib_cleanup();

    client = mosquitto_new(id, true, NULL);

    mosquitto_username_pw_set(client, username, password);
    mosquitto_connect_callback_set(client, on_connected);
    mosquitto_disconnect_callback_set(client, on_disconnected);
    mosquitto_publish_callback_set(client, on_publish);

    mosquitto_connect_async(client, host, port, keepalive);

}

const char* mqtt_wrapper::getTopic() {
    return this->topic;
}

mosquitto* mqtt_wrapper::getClient() {
    return this->client;
}
