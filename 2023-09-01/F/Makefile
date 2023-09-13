TARGET = F

.PHONY: $(TARGET), clean

$(TARGET):
	g++ -g -lm -std=c++17 -o $(TARGET).exec $(TARGET).cpp
	./$(TARGET).exec < in.txt > out.txt
	@echo -e "\n=== Output ==="
	@cat out.txt
	@echo -e "\n=== Diff ==="
	@diff out.txt answer.txt || true
	@echo -e " "

clean:
	rm -rf $(TARGET).exec out.txt
