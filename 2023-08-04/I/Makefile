.PHONY: I, clean

I:
	g++ -g -lm -std=c++17 -o I.exec I.cpp
	./I.exec < in.txt > out.txt
	@echo -e "\n=== Output ==="
	@cat out.txt
	@echo -e "\n=== Diff ==="
	@diff out.txt answer.txt || true
	@echo -e " "

clean:
	rm -rf I.exec out.txt


