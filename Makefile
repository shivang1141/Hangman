all: main.o string.o vector.o
	gcc -o main main.o string.o vector.o -g
main.o: main.c
	gcc -c main.c -g
string.o: string.c
	gcc -c string.c -g
vector.o: vector.c
	gcc -c vector.c -g
clean:
	rm *.o main *~
