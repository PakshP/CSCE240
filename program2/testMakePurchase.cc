// Copyright 2024 bhipp
// initial tests for MakePurchase
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include"./program2functions.h"

int main() {
  int twenties = 1, tens = 1, fives = 2, ones = 12, quarters = 0, dimes = 3,
      nickels = 0, pennies = 0;
  bool returned_value = MakePurchase(1782, twenties, tens, fives, ones,
                                     quarters, dimes, nickels, pennies);
  if ( returned_value && twenties == 0 && tens == 1 && fives == 2 && ones == 14
       && quarters == 0 && dimes == 4 && nickels == 1 && pennies == 3 ) {
    cout << "Passed MakePurchase test 1" << endl;
  } else {
    cout << "Failed MakePurchase test 1:\n\treturned value = "
         << (returned_value ? "true" : "false") << ", expected true"
         << "\n\tsecond argument's ending value = " << twenties
         << ", expected 0"
         << "\n\tthird argument's ending value = " << tens
         << ", expected 1"
         << "\n\tfourth argument's ending value = " << fives
         << ", expected 2"
         << "\n\tfifth argument's ending value = " << ones
         << ", expected 14"
         << "\n\tsixth argument's ending value = " << quarters
         << ", expected 0"
         << "\n\tseventh argument's ending value = " << dimes
         << ", expected 4"
         << "\n\teighth argument's ending value = " << nickels
         << ", expected 1"
         << "\n\tninth argument's ending value = " << pennies
         << ", expected 3" << endl;
  }

  twenties = 3;
  tens = 4;
  fives = 5;
  ones = 6;
  quarters = 7;
  dimes = 8;
  nickels = 9;
  pennies = 1;
  returned_value = MakePurchase(807, twenties, tens, fives, ones,
                                     quarters, dimes, nickels, pennies);
  if ( returned_value && twenties == 3 && tens == 3 && fives == 5 && ones == 7
       && quarters == 10 && dimes == 9 && nickels == 10 && pennies == 4 ) {
    cout << "Passed MakePurchase test 2" << endl;
  } else {
    cout << "Failed MakePurchase test 2:\n\treturned value = "
         << (returned_value ? "true" : "false") << ", expected true"
         << "\n\tsecond argument's ending value = " << twenties
         << ", expected 3"
         << "\n\tthird argument's ending value = " << tens
         << ", expected 3"
         << "\n\tfourth argument's ending value = " << fives
         << ", expected 5"
         << "\n\tfifth argument's ending value = " << ones
         << ", expected 7"
         << "\n\tsixth argument's ending value = " << quarters
         << ", expected 10"
         << "\n\tseventh argument's ending value = " << dimes
         << ", expected 9"
         << "\n\teighth argument's ending value = " << nickels
         << ", expected 10"
         << "\n\tninth argument's ending value = " << pennies
         << ", expected 4" << endl;
  }

  twenties = 0;
  tens = 0;
  fives = 1;
  ones = 2;
  quarters = 3;
  dimes = 4;
  nickels = 5;
  pennies = 6;
  returned_value = MakePurchase(807, twenties, tens, fives, ones,
                                     quarters, dimes, nickels, pennies);
  if ( returned_value && twenties == 0 && tens == 0 && fives == 0 && ones == 0
       && quarters == 0 && dimes == 1 && nickels == 4 && pennies == 9 ) {
    cout << "Passed MakePurchase test 3" << endl;
  } else {
    cout << "Failed MakePurchase test 3:\n\treturned value = "
         << (returned_value ? "true" : "false") << ", expected true"
         << "\n\tsecond argument's ending value = " << twenties
         << ", expected 0"
         << "\n\tthird argument's ending value = " << tens
         << ", expected 0"
         << "\n\tfourth argument's ending value = " << fives
         << ", expected 0"
         << "\n\tfifth argument's ending value = " << ones
         << ", expected 0"
         << "\n\tsixth argument's ending value = " << quarters
         << ", expected 0"
         << "\n\tseventh argument's ending value = " << dimes
         << ", expected 1"
         << "\n\teighth argument's ending value = " << nickels
         << ", expected 4"
         << "\n\tninth argument's ending value = " << pennies
         << ", expected 9" << endl;
  }

  twenties = 5;
  tens = 4;
  fives = 3;
  ones = 2;
  quarters = 1;
  dimes = 6;
  nickels = 7;
  pennies = 0;
  returned_value = MakePurchase(6495, twenties, tens, fives, ones,
                                     quarters, dimes, nickels, pennies);
  if ( returned_value && twenties == 2 && tens == 4 && fives == 2 && ones == 2
       && quarters == 1 && dimes == 6 && nickels == 8 && pennies == 0 ) {
    cout << "Passed MakePurchase test 4" << endl;
  } else {
    cout << "Failed MakePurchase test 4:\n\treturned value = "
         << (returned_value ? "true" : "false") << ", expected true"
         << "\n\tsecond argument's ending value = " << twenties
         << ", expected 2"
         << "\n\tthird argument's ending value = " << tens
         << ", expected 4"
         << "\n\tfourth argument's ending value = " << fives
         << ", expected 2"
         << "\n\tfifth argument's ending value = " << ones
         << ", expected 2"
         << "\n\tsixth argument's ending value = " << quarters
         << ", expected 1"
         << "\n\tseventh argument's ending value = " << dimes
         << ", expected 6"
         << "\n\teighth argument's ending value = " << nickels
         << ", expected 8"
         << "\n\tninth argument's ending value = " << pennies
         << ", expected 0" << endl;
  }

  twenties = 2;
  tens = 1;
  fives = 0;
  ones = 8;
  quarters = 5;
  dimes = 1;
  nickels = 2;
  pennies = 7;
  returned_value = MakePurchase(6495, twenties, tens, fives, ones,
                                     quarters, dimes, nickels, pennies);
  if ( !returned_value && twenties == 2 && tens == 1 && fives == 0 && ones == 8
       && quarters == 5 && dimes == 1 && nickels == 2 && pennies == 7 ) {
    cout << "Passed MakePurchase test 5" << endl;
  } else {
    cout << "Failed MakePurchase test 5:\n\treturned value = "
         << (returned_value ? "true" : "false") << ", expected false"
         << "\n\tsecond argument's ending value = " << twenties
         << ", expected 2"
         << "\n\tthird argument's ending value = " << tens
         << ", expected 1"
         << "\n\tfourth argument's ending value = " << fives
         << ", expected 0"
         << "\n\tfifth argument's ending value = " << ones
         << ", expected 8"
         << "\n\tsixth argument's ending value = " << quarters
         << ", expected 5"
         << "\n\tseventh argument's ending value = " << dimes
         << ", expected 1"
         << "\n\teighth argument's ending value = " << nickels
         << ", expected 2"
         << "\n\tninth argument's ending value = " << pennies
         << ", expected 7" << endl;
  }

  return 0;
}
