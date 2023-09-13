TARGET = H
VERIFIER = verify_answer

.PHONY: $(TARGET), clean

$(TARGET):
	python3 $(TARGET).py < in.txt > out.txt
	@echo -e "\n=== Output ==="
	@cat out.txt
	@echo -e "\n=== Verifying ==="
	python3 $(VERIFIER).py 

clean:
	rm -rf out.txt
