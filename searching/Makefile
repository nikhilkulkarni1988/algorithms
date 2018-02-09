IDIR   = ./include
ODIR   = ./obj
SDIR   = ./src
BDIR   = ./bin
CC     = gcc
CFLAGS = -I $(IDIR) -Werror -Wall -Wextra -g

all: linearSearch.exe binarySearchRegular.exe KMPSearching.exe

#LinearSearch
linearSearch.exe: $(ODIR)/linearSearch.o
	$(CC) -o $(BDIR)/linearSearch.exe $(ODIR)/linearSearch.o

$(ODIR)/linearSearch.o: $(SDIR)/linearSearch.c $(IDIR)/linearSearch.h
	$(CC) -o $(ODIR)/linearSearch.o -c $(SDIR)/linearSearch.c $(CFLAGS)

#BinarySearchRegular
binarySearchRegular.exe: $(ODIR)/binarySearchRegular.o
	$(CC) -o $(BDIR)/binarySearchRegular.exe $(ODIR)/binarySearchRegular.o

$(ODIR)/binarySearchRegular.o: $(SDIR)/binarySearchRegular.c $(IDIR)/binarySearchRegular.h
	$(CC) -o $(ODIR)/binarySearchRegular.o -c $(SDIR)/binarySearchRegular.c $(CFLAGS)

#KMPSearch
KMPSearching.exe: $(ODIR)/KMPSearching.o
	$(CC) -o $(BDIR)/KMPSearching.exe $(ODIR)/KMPSearching.o

$(ODIR)/KMPSearching.o: $(SDIR)/KMPSearching.c $(IDIR)/KMPSearching.h
	$(CC) -o $(ODIR)/KMPSearching.o -c $(SDIR)/KMPSearching.c $(CFLAGS)


clean:
	rm -f $(ODIR)/* $(BDIR)/*
