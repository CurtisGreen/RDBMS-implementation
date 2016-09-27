# makefile

all: main

main: Main.o Attribute.o Engine.o Table.o 
	g++ -std=c++11  Main.o Attribute.o Table.o Engine.o -o main

Main.o: Main.cpp Attribute.h Engine.h Table.h
	g++ -std=c++11 -c Main.cpp  
	
Attribute.o: Attribute.cpp Attribute.h
	g++ -std=c++11 -c Attribute.cpp 
	
Table.o: Table.cpp Table.h
	g++ -std=c++11 -c Table.cpp
 
Engine.o: Engine.cpp Engine.h Attribute.h Table.h
	g++ -std=c++11 -c Engine.cpp
	
Parser.o: Parser.cpp Parser.h Engine.h
	g++ -std=c++11 -c Parser.cpp

clean:
	rm -f *.o

run:
	./main
