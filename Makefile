CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=my_mat.o
FLAGS= -Wall -g

all: stringProg
stringProg: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN)


main.o: main.c
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so connections
