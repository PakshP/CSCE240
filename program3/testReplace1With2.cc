// Copyright 2024 bhipp
#include<iostream>
using std::cout;
using std::endl;
#include"program3functions.h"
#include"p3compares.h"

int main() {
  bool returned_value;
  double match_value;

  const int kSize1 = 30;
  char array1[kSize1] = "math band lad a";
  const char correct_array1[kSize1] = "mouth bound loud ou";

  cout << "Test 1\n";
  returned_value = Replace1With2(array1, kSize1, 'a', 'o', 'u');
  match_value = PercentMatch(correct_array1, array1);
  if ( returned_value && match_value == 100 ) {
    cout << "Match!\n" << endl;
  } else {
    cout << "returned " << (returned_value ? "true" : "false")
         << " (true expected). " << match_value << "% array match\n" << endl;
  }

  const int kSize2 = 11;
  char array2[kSize2] = "graf fase";
  const char correct_array2[kSize2] = "graf fase";

  cout << "Test 2\n";
  returned_value = Replace1With2(array2, kSize2, 'f', 'p', 'h');
  match_value = PercentMatch(correct_array2, array2);
  if ( !returned_value && match_value == 100 ) {
    cout << "Match!\n" << endl;
  } else {
    cout << "returned " << (returned_value ? "true" : "false")
         << " (false expected). " << match_value << "% array match\n" << endl;
  }

  const int kSize3 = 12;
  char array3[kSize3] = "graf fase";
  const char correct_array3[kSize3] = "graph phase";

  cout << "Test 3\n";
  returned_value = Replace1With2(array3, kSize3, 'f', 'p', 'h');
  match_value = PercentMatch(correct_array3, array3);
  if ( returned_value && match_value == 100 ) {
    cout << "Match!\n" << endl;
  } else {
    cout << "returned " << (returned_value ? "true" : "false")
         << " (true expected). " << match_value << "% array match\n" << endl;
  }

  return 0;
}
