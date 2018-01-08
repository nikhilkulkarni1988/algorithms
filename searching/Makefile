#place for header files
IDIR = ./include

#place for object files
ODIR =./obj

#place for source C files
SDIR =./src

#place for executables
BDIR =./bin

#compiler
CC = gcc

#Flags needed for compilation
CFLAGS = -I$(IDIR) -Werror -Wall -Wextra

#libraries needed for compilation
LIBS =

#provide required header files and replace with relative paths
_DEPS = linearSearch.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#provide required object files and replace with relative paths
_OBJ = linearSearch.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

#provide required source files and replace with relative paths
_SRC = linearSearch.c main.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

#Create and rename object file for each source file
$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)
	@echo "Compiled "$<" successfully!"

#Create executable
$(BDIR)/search: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	@echo "Linking complete!"

#Make ignores any action on file named clean if any
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BDIR)/*
	@echo "Cleanup complete!"
