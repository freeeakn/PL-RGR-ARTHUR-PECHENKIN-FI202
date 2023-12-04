all:
	g++ -Wall -Werror -Wextra src/main.cpp -o mvc

clean:
	rm -rf mvc