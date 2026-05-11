CC= gcc
CFLAGS= -Wall -Wextra -Wpedantic -std=c11
SRC= ./src/main.c
PKG= glfw3 glew
INCLUDE= `pkg-config --cflags $(PKG)`
LIBS= `pkg-config --libs $(PKG)` -lm
OUT= ./build/app

compile:
	@$(CC) $(CFLAGS) $(INCLUDE) -o $(OUT) $(SRC) $(LIBS)

run: compile
	@$(OUT)
