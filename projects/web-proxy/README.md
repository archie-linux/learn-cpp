# WebProxy Suite

Minimal C++ HTTP Proxy with Web UI.

## Build
mkdir build && cd build
cmake ..
make -j4

## Run
cd ..
./build/webproxy

- Proxy listens on :8080 (configure browser to use it).
- UI at http://localhost:8081
- Logs traffic in-memory; export via UI.

<img src="./screenshots/ui 1.png" width="800" height="350">

<br />

<img src="./screenshots/ui 2.png" width="1000" height="350">
