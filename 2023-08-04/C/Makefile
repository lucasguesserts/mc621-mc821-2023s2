TARGET = C
CC = gcc
CFLAGS = -std=c11

$(TARGET): clean
	$(CC) $(CFLAGS) -o $(TARGET).exec $(TARGET).c
	./$(TARGET).exec
	diff output.txt answer.txt

clean:
	rm -rf $(TARGET).exec output.txt
