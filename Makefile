all: clean compile

run: all
	./a.out

clean:
	rm -f *.o *.gch *.out

compile:
	gcc *.c *.h