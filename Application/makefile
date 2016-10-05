# makefile

all: marvel

marvel: Marvel.o Engine.o Table.o Parser.o Attribute.o 
	g++ -std=c++11 Attribute.o Marvel.o Table.o Engine.o Parser.o -o marvel

Marvel.o: Marvel.cpp Parser.h Engine.h Table.h Marvel.h
	g++ -std=c++11 -c Marvel.cpp  
	
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
	./marvel
