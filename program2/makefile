flags = -std=c++17 -Wall -I .

googlestyle : program2functions.h program2functions.cc
	cpplint program2functions.h program2functions.cc

program2functions.o : program2functions.cc program2functions.h
	g++ -c $(flags) $<  -I .

testToClosestPrime.o : testToClosestPrime.cc program2functions.h
	g++ -c $(flags) $<  -I .

testToClosestPrime : testToClosestPrime.o program2functions.o
	g++ $(flags) $^
	./a.out

testPrintPrimesBetweenCall : testPrintPrimesBetweenCall.cc program2functions.o
	g++ $(flags) $^ -o $@

testPrintPrimesBetween : testPrintPrimesBetweenOutput.cc testPrintPrimesBetweenCall
	g++ $(flags) $<
	./a.out

testLargestPrimeSequence.o : testLargestPrimeSequence.cc program2functions.h
	g++ -c $(flags) $<  -I .

testLargestPrimeSequence : testLargestPrimeSequence.o program2functions.o
	g++ $(flags) $^
	./a.out

testPrintAsDollarsAndCentsCall : testPrintAsDollarsAndCentsCall.cc program2functions.o
	g++ $(flags) $^ -o $@

testPrintAsDollarsAndCents : testPrintAsDollarsAndCentsOutput.cc testPrintAsDollarsAndCentsCall
	g++ $(flags) $<
	./a.out

testMakePurchase.o : testMakePurchase.cc program2functions.h
	g++ -c $(flags) $<  -I .

testMakePurchase : testMakePurchase.o program2functions.o
	g++ $(flags) $^
	./a.out

clean :
	rm *.o a.out testPrintPrimesBetweenCall testPrintAsDollarsAndCentsCall student-primes-output.txt student-money-output.txt

