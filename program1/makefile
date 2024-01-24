style : program1.cc
	cpplint program1.cc

program1.o : program1.cc
	g++ -Wall -std=c++17 -c program1.cc

compile : program1.o


program1 : program1.o
	g++ -Wall -std=c++17 program1.o -o program1

link : program1
	

checkit : checkit.cc
	g++ -Wall -std=c++17 checkit.cc -o checkit

test1 : program1 checkit sample-input1.txt expected-output1.txt
	./program1 < sample-input1.txt > student-output1.txt
	./checkit 0

test2 : program1 checkit sample-input2.txt expected-output2.txt
	./program1 < sample-input2.txt > student-output2.txt
	./checkit 1

test3 : program1 checkit sample-input3.txt expected-output3.txt
	./program1 < sample-input3.txt > student-output3.txt
	./checkit 2

test4 : program1 checkit sample-input4.txt expected-output4.txt
	./program1 < sample-input4.txt > student-output4.txt
	./checkit 3

test5 : link program1 checkit sample-input5.txt expected-output5.txt
	./program1 < sample-input5.txt > student-output5.txt
	./checkit 4

test6 : program1 checkit sample-input6.txt expected-output6.txt
	./program1 < sample-input6.txt > student-output6.txt
	./checkit 5

test7 : program1 checkit sample-input7.txt expected-output7.txt
	./program1 < sample-input7.txt > student-output7.txt
	./checkit 6

clean :
	rm student* program1.o checkit program1
