TARGET = D

$(TARGET): clean
	python3 $(TARGET).py < in.txt > out.txt
	diff out.txt answer.txt

clean:
	rm -rf out.txt
