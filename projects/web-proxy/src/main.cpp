#include "proxy_server.h"
#include "web_server.h"
#include <iostream>
#include <thread>
#include <csignal>

volatile bool running = true;

void signalHandler(int) {
    running = false;
}

int main() {
    signal(SIGINT, signalHandler);

    ProxyServer proxy(8080);
    WebServer web(8081);

    std::thread proxy_thread([&]() { proxy.start(); });
    std::thread web_thread([&]() { web.start(); });

    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    proxy.stop();
    web.stop();
    proxy_thread.join();
    web_thread.join();

    return 0;
}
