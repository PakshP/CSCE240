# comments
# $@ = the target
# $< = the first prerequisite
# $^ = all prerequisites

flags = -std=c++17 -Wall -I .
compile = g++ $(flags) -c
link = g++ $(flags)

program3functions.o : program3functions.cc program3functions.h
	$(compile) $<

testRemoveValues : testRemoveValues.cc p3compares.cc program3functions.o
	$(link) $^
	./a.out

testReplace1With2 : testReplace1With2.cc p3compares.cc program3functions.o
	$(link) $^
	./a.out

testSwapRowsAndColumns : testSwapRowsAndColumns.cc p3compares.cc program3functions.o
	$(link) $^
	./a.out

testShiftArray : testShiftArray.cc p3compares.cc program3functions.o
	$(link) $^
	./a.out

testIsAnagram : testIsAnagram.cc p3compares.cc program3functions.o
	$(link) $^
	./a.out

clean :
	rm program3functions.o a.out

