CC = g++
CFLAGS = -Wall -Iinclude -std=c++17
SRC = src/Disk.cpp src/Inode.cpp src/Directory.cpp src/FileSystem.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = filesystem

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
