CC = clang++
FLAGS = -o
BUILD=bin

$(BUILD)/lexer: lexer/lexer.cpp
	$(CC) lexer/lexer.cpp -o $(BUILD)/lexer

build:
	mkdir -p $(BUILD)

clean:
	rm -f $(BUILD)/lexer