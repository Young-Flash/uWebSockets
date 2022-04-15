# Overview
This project is fork from [uNetworking/uWebSockets](https://github.com/uNetworking/uWebSockets), which add unix domain support, now websocket connection can be established over unix domain socket (a file), not just over tcp ip:port. Test program lies in tests/UnixServer.cpp, tests/UnixClient.js, note that [websockets/ws](https://github.com/websockets/ws) is needed to run tests/UnixClient.js.

# Build 
`make` the project with [specific compilation options](https://github.com/uNetworking/uWebSockets/blob/master/misc/READMORE.md#compiling), `make install` to install head files to system path, note that you need to manually copy `uSockets/uSockets.a` and `uSockets/src/libusockets.h` to system path after `make` if you don't want specifies the link path at run time.

# Run Test program
for UnixServer.cpp: `g++ -std=c++17 -o UnixServer UnixServer.cpp -luSockets -lssl -lz -lcrypto -lpthread && ./UnixServer`

for UnixClient.js: `node UnixClient.js`