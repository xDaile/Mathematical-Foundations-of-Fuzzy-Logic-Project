CC= g++
FLAGS= -lm

imf: imf.cpp
	$(CC) -o $@ imf.cpp $(FLAGS)

run:
	./imf
