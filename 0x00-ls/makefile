CC = gcc

CFLAGS = -Wall -Werror -Wextra -pedantic

TARGET = *.c

OUTPUT = hls

all: $(TARGET)
	$(CC) $(CFLAGS) $(TARGET) -o $(OUTPUT)

run:
	./$(OUTPUT)
	./$(OUTPUT) hola

betty:
	betty *.c

valgrind:
	valgrind ./$(OUTPUT)

clean:
	$(RM) $(OUTPUT)