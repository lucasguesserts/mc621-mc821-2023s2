TARGET = C
CC = gcc
CFLAGS = -std=c11

.PHONY: $(TARGET), clean

$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET).exec $(TARGET).c
	./$(TARGET).exec
	@echo -e "\n=== Output ==="
	@cat output.txt
	@echo -e "\n=== Diff ==="
	@diff output.txt answer.txt || true
	@echo -e " "

clean:
	rm -rf $(TARGET).exec output.txt
