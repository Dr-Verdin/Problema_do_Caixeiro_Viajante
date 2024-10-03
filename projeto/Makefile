##all: item.o grafo.o teste.o
##	gcc item.o grafo.o teste.o -o Teste -std=c99 -Wall

## main
all: item.o grafo.o main.o
	gcc item.o grafo.o main.o -o Batata -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

grafo.o:
	gcc -c grafo.c -o grafo.o

## main
main.o:
	gcc -c main.c -o main.o

##teste.o:
##	gcc -c teste.c -o teste.o

clean:
	rm *.o Batata