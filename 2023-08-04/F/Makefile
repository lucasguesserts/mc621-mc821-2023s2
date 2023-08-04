.PHONY: F, clean

F:
	@for N in 1 2 3 ; do \
		python F.py < test_cases/in_$$N.txt > test_cases/out_$$N.txt ; \
		echo -e "\n=== Case $$N - Output ===" ; \
		cat test_cases/out_$$N.txt ; \
		echo -e "\n=== Case $$N - Diff ===" ; \
		diff test_cases/out_$$N.txt test_cases/answer_$$N.txt || true ; \
		echo -e " " ; \
	done

clean:
	rm -rf F.exec test_cases/out_?.txt


