
CFLAGS = -g -I. -Og -Wall
DEPS = linkedlist.h minheap.h comparator.h
EXEC_FILE = libdstruct

all: $(EXEC_FILE)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC_FILE): main.o linkedlist.o minheap.o comparator.o
	$(CC) $^ -o libdstruct

clean:
	rm -f *.o libdstruct