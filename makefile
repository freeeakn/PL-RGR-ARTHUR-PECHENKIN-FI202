all:
	g++ -std=c++20 -Wall -Werror -Wextra src/main.cpp -o mvc

clean:
	rm -rf mvc
