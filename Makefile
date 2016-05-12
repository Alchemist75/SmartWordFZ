all: Word.o Dictionary.o handler.o searchHandler.o mainHandler.o main.o 
	g++ -std=c++11 main.o Word.o Dictionary.o handler.o searchHandler.o mainHandler.o -o smartword
main.o: main.cpp
	g++ -c -g -Wall -std=c++11 main.cpp -o main.o
handler.o: handler.h handler.cpp
	g++ -c -g -Wall -std=c++11 handler.cpp -o handler.o
mainHandler.o: mainHandler.h mainHandler.cpp
	g++ -c -g -Wall -std=c++11 mainHandler.cpp -o mainHandler.o
searchHandler.o: searchHandler.h searchHandler.cpp
	g++ -c -g -Wall -std=c++11 searchHandler.cpp -o searchHandler.o
Word.o: Word.h Word.cpp
	g++ -c -g -Wall -std=c++11 Word.cpp -o Word.o
Dictionary.o: Dictionary.h Dictionary.cpp
	g++ -c -g -Wall -std=c++11 Dictionary.cpp -o Dictionary.o



clean:
	rm *.o
