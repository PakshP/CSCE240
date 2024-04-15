flags = -std=c++17 -Wall -I .

PixelShape.o : PixelShape.cc PixelShape.h
	g++ $(flags) -c $< -I .

testPixelShapeName : testPixelShapeName.cc PixelShape.o
	g++ $(flags) $^
	./a.out

testPixelShapePixel : testPixelShapePixel.cc PixelShape.o
	g++ $(flags) $^
	./a.out

RightIsosceles.o : RightIsosceles.cc RightIsosceles.h PixelShape.h
	g++ $(flags) -c $< -I .

testRightIsoscelesName : testRightIsoscelesName.cc RightIsosceles.o PixelShape.o
	g++ $(flags) $^
	./a.out

testRightIsoscelesLeg : testRightIsoscelesLeg.cc RightIsosceles.o PixelShape.o
	g++ $(flags) $^
	./a.out

testRightIsoscelesTimesEquals : testRightIsoscelesTimesEquals.cc RightIsosceles.o PixelShape.o
	g++ $(flags) $^
	./a.out

Rectangle.o : Rectangle.cc Rectangle.h PixelShape.h
	g++ $(flags) -c $< -I .

testRectangleName : testRectangleName.cc Rectangle.o PixelShape.o
	g++ $(flags) $^
	./a.out

testRectangleSides : testRectangleSides.cc Rectangle.o PixelShape.o
	g++ $(flags) $^
	./a.out

testRectangleTimesEquals : testRectangleTimesEquals.cc Rectangle.o PixelShape.o
	g++ $(flags) $^
	./a.out

checkit : checkit.cc
	g++ $(flags) $^ -o $@

testVirtualPrints : testVirtualPrints.cc Rectangle.o RightIsosceles.o PixelShape.o
	g++ $(flags) $^ -o $@

testPrint1 : testVirtualPrints checkit
	./testVirtualPrints 2 true < sampleinput.txt > studentoutput1.txt
	rm testVirtualPrints
	./checkit 0

testPrint2 : testVirtualPrints checkit
	./testVirtualPrints 0.5 true < sampleinput.txt > studentoutput2.txt
	rm testVirtualPrints
	./checkit 1

testPrint3 : testVirtualPrints checkit
	./testVirtualPrints 2 false < sampleinput.txt > studentoutput3.txt
	rm testVirtualPrints
	./checkit 2

testPrint4 : testVirtualPrints checkit
	./testVirtualPrints 0.5 false < sampleinput.txt > studentoutput4.txt
	rm testVirtualPrints
	./checkit 3

clean :
	rm  *.out *.o testVirtualPrints checkit studentoutput*.txt

