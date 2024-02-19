// Copyright 2024 bhipp
#include<iostream>
using std::cout;
using std::endl;
#include"program3functions.h"
#include"p3compares.h"

int main() {
  const int kSize1 = 10;
  int array1[kSize1] = {7, 3, 6, 7, 8, 1, 2, 7, 3, 7};
  const int correct_array1[kSize1] = {3, 6, 8, 1, 2, 3, -999, -999, -999, -999};

  RemoveValues(array1, kSize1, 7);
  cout << "Test 1\n";
  cout << PercentMatch(correct_array1, array1, kSize1) << "% match\n" << endl;

  const int kSize2 = 14;
  int array2[kSize2] = {1, 2, 3, 4, 5, 6, 7, 7, 6, 5, 4, 3, 2, 1};
  const int correct_array2[kSize2] = {1, 2, 3, 4, 5, 6, 7, 7, 6, 5, 4, 3, 2, 1};

  RemoveValues(array2, kSize2, 11);
  cout << "Test 2\n";
  cout << PercentMatch(correct_array2, array2, kSize2) << "% match\n" << endl;
  return 0;
}
