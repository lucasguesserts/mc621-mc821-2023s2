TARGET = I

.PHONY: $(TARGET), clean

$(TARGET):
	java ./$(TARGET).java < in.txt > out.txt
	@echo -e "\n=== Output ==="
	@cat out.txt
	@echo -e "\n=== Diff ==="
	@diff out.txt answer.txt || true
	@echo -e " "

clean:
	rm -rf $(TARGET).exec out.txt
