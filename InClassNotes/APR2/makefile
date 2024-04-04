Book.o : Book.cc Book.h
	g++ -c -Wall -std=c++17 $<

Textbook.o : Textbook.cc Textbook.h Book.h
	g++ -c -Wall -std=c++17 $<

testtextbook.o : testtextbook.cc Book.h
	g++ -c -Wall -std=c++17 $<

test : testtextbook.o Textbook.o Book.o
	g++ -Wall -std=c++17 $^
	./a.out

clean :
	rm *.o a.out
