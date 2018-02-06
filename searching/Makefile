all: linearSearch

linearSearch: ./obj/linearSearch.o
	gcc -o ./bin/linearSearch ./obj/linearSearch.o

./obj/linearSearch.o: ./src/linearSearch.c ./include/linearSearch.h
	gcc -o ./obj/linearSearch.o -c ./src/linearSearch.c -I ./include

clean:
	rm -f ./obj/* ./bin/*
