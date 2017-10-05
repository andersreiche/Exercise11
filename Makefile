# -*- Makefile -*-

all: Exercise11

Exercise11: Exercise11.o OptChars.o Options.o OptWord.o
	g++ Exercise11.o OptChars.o OptWord.o Options.o -o Exercise11

Exercise11.o: Exercise11.cpp
	g++ -c Exercise11.cpp

OptChars.o: OptChars.cpp OptChars.h
	g++ -c OptChars.cpp

OptWord.o: OptWord.cpp OptWord.h
	g++ -c OptWord.cpp

Options.o: Options.cpp Options.h
	g++ -c Options.cpp

clean:
	rm *.o Exercise11