TARGET = B

.PHONY: $(TARGET), clean

$(TARGET):
	# g++ -g -lm -std=c++17 -o $(TARGET).exec $(TARGET).cpp
	@for N in 1 2 3 4 ; do \
		# ./$(TARGET).exec < test_cases/in_$$N.txt > test_cases/out_$$N.txt ; \
		python ./$(TARGET).py < test_cases/in_$$N.txt > test_cases/out_$$N.txt ; \
		# echo -e "\n=== Case $$N - Output ===" ; \
		# cat test_cases/out_$$N.txt ; \
		echo -e "\n=== Case $$N - Check ===" ; \
		python check.py < test_cases/out_$$N.txt || true ; \
		# echo -e " " ; \
	done

clean:
	rm -rf $(TARGET).exec out.txt
