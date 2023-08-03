.PHONY: K, clean

K:
	g++ -g -lm -std=c++17 -o K.exec K.cpp
	./K.exec < in.txt > out.txt
	@echo -e "\n=== Output ==="
	@cat out.txt
	@echo -e "\n=== Diff ==="
	@diff out.txt answer.txt || true
	@echo -e " "

clean:
	rm -rf K.exec out.txt


