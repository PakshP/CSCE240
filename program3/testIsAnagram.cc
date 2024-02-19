// Copyright 2024 bhipp
#include<iostream>
using std::cout;
using std::endl;
#include"program3functions.h"
#include"p3compares.h"

int main() {
  if ( !IsAnagram("abcdd", "abcdc") ) {
    cout << "Passed test 1\n" << endl;
  } else {
    cout << "Failed test 1\n" << endl;
  }

  if ( IsAnagram("e f g l m n QQq", "qmnl qgef q") ) {
    cout << "Passed test 2\n" << endl;
  } else {
    cout << "Failed test 2\n" << endl;
  }

  if ( !IsAnagram("e f g l m n QQq", "qmnl qgef q", true) ) {
    cout << "Passed test 3\n" << endl;
  } else {
    cout << "Failed test 3\n" << endl;
  }

  if ( IsAnagram("A decimal point.", "I'm a dot in place!") ) {
    cout << "Passed test 4\n" << endl;
  } else {
    cout << "Failed test 4\n" << endl;
  }

  if ( !IsAnagram("A decimal point.", "I'm a dot in place!", true) ) {
    cout << "Passed test 5\n" << endl;
  } else {
    cout << "Failed test 5\n" << endl;
  }

  if ( IsAnagram("William Shakespeare", "i am a Weakish Speller", true) ) {
    cout << "Passed test 6\n" << endl;
  } else {
    cout << "Failed test 6\n" << endl;
  }


  return 0;
}
