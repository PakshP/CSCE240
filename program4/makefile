# comments
# $@ = the target
# $< = the first prerequisite
# $^ = all prerequisites

flags = -std=c++17 -Wall -I .
compile = g++ $(flags) -c
link = g++ $(flags)

MonetaryUnit.o : MonetaryUnit.cc MonetaryUnit.h
	$(compile) $<

testMonetaryUnitConstructor : testMonetaryUnitConstructor.cc MonetaryUnit.o
	$(link) $^
	./a.out

testMonetaryUnitName : testMonetaryUnitName.cc MonetaryUnit.o
	$(link) $^
	./a.out

testMonetaryUnitSymbol : testMonetaryUnitSymbol.cc MonetaryUnit.o
	$(link) $^
	./a.out

testMonetaryUnitAmountEquivalentTo1Dollar : testMonetaryUnitAmountEquivalentTo1Dollar.cc MonetaryUnit.o
	$(link) $^
	./a.out

testMonetaryUnitEquivalent : testMonetaryUnitEquivalent.cc MonetaryUnit.o
	$(link) $^
	./a.out

MonetaryAmount.o : MonetaryAmount.cc MonetaryAmount.h MonetaryUnit.h
	$(compile) $<

testMonetaryAmountConstructor : testMonetaryAmountConstructor.cc MonetaryAmount.o MonetaryUnit.o
	$(link) $^
	./a.out

testMonetaryAmountConvertToUnit : testMonetaryAmountConvertToUnit.cc MonetaryAmount.o MonetaryUnit.o
	$(link) $^
	./a.out

testMonetaryAmountEquivalent : testMonetaryAmountEquivalent.cc MonetaryAmount.o MonetaryUnit.o
	$(link) $^
	./a.out

testMonetaryAmountLessThan : testMonetaryAmountLessThan.cc MonetaryAmount.o MonetaryUnit.o
	$(link) $^
	./a.out

testMonetaryAmountGreaterThan : testMonetaryAmountGreaterThan.cc MonetaryAmount.o MonetaryUnit.o
	$(link) $^
	./a.out

testMonetaryAmountAddition : testMonetaryAmountAddition.cc MonetaryAmount.o MonetaryUnit.o
	$(link) $^
	./a.out

testMonetaryAmountCreateOutput : testMonetaryAmountCreateOutput.cc MonetaryAmount.o MonetaryUnit.o
	$(link) $^
	./a.out > studentoutput.txt

testMonetaryAmountOutputTest : testMonetaryAmountOutputTest.cc MonetaryAmount.o MonetaryUnit.o 
	$(link) $^
	./a.out

testMonetaryAmountOutput : testMonetaryAmountCreateOutput testMonetaryAmountOutputTest
	

clean :
	rm *.o a.out studentoutput.txt

