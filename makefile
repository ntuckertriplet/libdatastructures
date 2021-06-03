
CFLAGS = -g -I. -Og -Wall
DEPS = linkedlist.h maxheap.h comparator.h queue.h binarysearchtree.h
EXEC_FILE = libdstruct

all: $(EXEC_FILE)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC_FILE): main.o linkedlist.o maxheap.o comparator.o queue.o binarysearchtree.o
	$(CC) $^ -o libdstruct

clean:
	rm -f *.o libdstruct