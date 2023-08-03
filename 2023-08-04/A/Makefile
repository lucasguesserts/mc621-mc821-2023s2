.PHONY: A, clean

A:
	g++ -lm -std=c++17 -o A.exec A.cpp
	./A.exec < in.txt > out.txt
	@echo -e "\n=== Output ==="
	@cat out.txt
	@echo -e "\n=== Diff ==="
	@diff out.txt answer.txt || true
	@echo -e " "

clean:
	rm -rf A.exec out.txt


