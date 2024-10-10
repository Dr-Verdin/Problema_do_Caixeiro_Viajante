##all: item.o grafo.o teste.o
##	gcc item.o grafo.o teste.o -o Teste -std=c99 -Wall

## main
all: item.o listas_adj.o main.o
	gcc item.o listas_adj.o main.o -o runabble -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

listas_adj.o:
	gcc -c listas_adj.c -o listas_adj.o

## main
main.o:
	gcc -c main.c -o main.o

##teste.o:
##	gcc -c teste.c -o teste.o

clean:
	rm *.o runabble