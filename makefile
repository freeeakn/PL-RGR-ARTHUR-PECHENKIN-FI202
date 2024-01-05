CC=g++
FLAGS=-Wall -Werror -Wextra
STD=-std=c++20

all:
	$(CC) $(STD) $(FLAGS) src/main.cpp -o mvc

lint:
	clang-format -i src/*.cpp src/*.h

clean:
	rm -rf mvc
