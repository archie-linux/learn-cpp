CXX = g++
CXXFLAGS = -std=c++17 -pthread -Iinclude

all: server client

server: src/server.cpp src/auth.cpp
	$(CXX) $(CXXFLAGS) -o server src/server.cpp src/auth.cpp

client: src/client.cpp
	$(CXX) $(CXXFLAGS) -o client src/client.cpp

clean:
	rm -f server client
