TARGET = D

.PHONY: $(TARGET), clean

$(TARGET):
	g++ -g -lm -std=c++17 -o $(TARGET).exec $(TARGET).cpp
	@for N in 1 2 3 ; do \
		./$(TARGET).exec < test_cases/in_$$N.txt > test_cases/out_$$N.txt ; \
		echo -e "\n=== Case $$N - Output ===" ; \
		cat test_cases/out_$$N.txt ; \
		echo -e "\n=== Case $$N - Diff ===" ; \
		diff test_cases/out_$$N.txt test_cases/answer_$$N.txt || true ; \
		echo -e " " ; \
	done

clean:
	rm -rf $(TARGET).exec out.txt
