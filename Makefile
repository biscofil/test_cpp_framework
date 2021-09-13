CC=g++
all: Main

Main: src/main.cpp src/system/response.h src/system/serializable.h src/system/router.h src/controllers/posts_controller.h src/models/post.h
	$(CC) src/main.cpp -lstdc++ -fPIC -std=c++20 -o main