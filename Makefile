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
