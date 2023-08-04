TARGET = E
CC = gcc
CFLAGS = -std=c11

$(TARGET): clean
	$(CC) $(CFLAGS) -o $(TARGET).exec $(TARGET).c
	./$(TARGET).exec < in.txt > out.txt
	diff out.txt answer.txt

clean:
	rm -rf $(TARGET).exec out.txt
