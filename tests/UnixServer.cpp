#include <uWebSockets/App.h>
#include <nlohmann/json.hpp>
#include <string>

using namespace std;
using namespace uWS;
using namespace nlohmann;

// store something you care about for a client
struct ConnectionData{
    string_view address;
    ConnectionData() = default;
};

int main() {

    string path = "ws.sock";

    auto app = App().ws<ConnectionData>("/*", App::WebSocketBehavior<ConnectionData> {
            // 5 minutes to timeout
            .idleTimeout = 300,
            .open = [](auto *ws) {
                std::cout << "websocket connection established" << std::endl;
            },
            .message = [&](WebSocket<false, true, ConnectionData> *ws, std::string_view message, OpCode opCode) {
                std::cout << "received: " << message << std::endl;
                ws->send(message, OpCode::TEXT);./U
            },
            .close = [](auto *ws, int /*code*/, std::string_view /*message*/) {
                ws->send("websocket connection closed", OpCode::TEXT);
                std::cout << "websocket connection closed here" << std::endl;
            }
    }).listen_unix(path, [&](auto *listen_socket) {
        if (listen_socket) {
            std::cout << "Listening on path: " << path << std::endl;
        } else std::cout << "failed to listen" << std::endl;

    });

    app.run();

    return 0;
}

// g++ -std=c++17 -o UnixServer UnixServer.cpp -luSockets -lssl -lz -lcrypto -lpthread && ./UnixServer