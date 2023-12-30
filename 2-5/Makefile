CC = gcc
CFLAGS = -Wall

SOURCE = main.c
EXECUTABLE = exec

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean

run:
	./exec

