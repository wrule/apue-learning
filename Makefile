main: src/main.c
	gcc -o main src/main.c
	./main ./
copyer: src/copyer/main.c
	rm 1.txt
	gcc -o main src/copyer/main.c
	./main >> 1.txt
copyer-std: src/copyer/main-std.c
	rm 1.txt
	gcc -o main src/copyer/main-std.c
	./main >> 1.txt
getpid: src/getpid/main.c
	gcc -o main src/getpid/main.c
	./main
myshell: src/myshell/main.c
	gcc -o main src/myshell/main.c
	./main
forker: src/forker/main.c
	gcc -o main src/forker/main.c
	./main