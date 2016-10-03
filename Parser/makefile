# makefile

all: main

main: Main.o Engine.o Table.o Parser.o Attribute.o 
	g++ -std=c++11 Attribute.o Main.o Table.o Engine.o Parser.o -o main

Main.o: Main.cpp Parser.h Engine.h Table.h
	g++ -std=c++11 -c Main.cpp  
	
Attribute.o: Attribute.cpp Attribute.h
	g++ -std=c++11 -c Attribute.cpp 
	
Table.o: Table.cpp Table.h
	g++ -std=c++11 -c Table.cpp
 
Engine.o: Engine.cpp Engine.h Attribute.h Table.h
	g++ -std=c++11 -c Engine.cpp
	
Parser.o: Parser.cpp Parser.h Engine.h Token_stream.h
	g++ -std=c++11 -c Parser.cpp
	
clean:
	rm -f *.o

run:
	./main < parser_test.txt
