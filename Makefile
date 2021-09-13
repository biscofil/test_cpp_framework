CC=g++
all: Main

Main: src/main.cpp
	$(CC) src/main.cpp -lstdc++ -fPIC -std=c++11 -o main