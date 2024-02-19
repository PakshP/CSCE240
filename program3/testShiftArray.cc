// Copyright 2024 bhipp
#include<iostream>
using std::cout;
using std::endl;
#include"program3functions.h"
#include"p3compares.h"

int main() {
  const int kSize1 = 10;
  int array1[kSize1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const int correct_array1[kSize1] = {4, 5, 6, 7, 8, 9, 0, 1, 2, 3};

  ShiftArray(array1, kSize1, 4);
  cout << "Test 1\n";
  cout << PercentMatch(correct_array1, array1, kSize1) << "% match\n" << endl;

  const int kSize2 = 14;
  int array2[kSize2] = {1, 8, 2, 9, 3, 10, 4, 11, 5, 12, 6, 13, 7, 14};
  const int correct_array2[kSize2] =
                       {12, 6, 13, 7, 14, 1, 8, 2, 9, 3, 10, 4, 11, 5};

  ShiftArray(array2, kSize2, -5);
  cout << "Test 2\n";
  cout << PercentMatch(correct_array2, array2, kSize2) << "% match\n" << endl;

  const int kSize3 = 7;
  int array3[kSize3] = {1, 2, 3, 4, 5, 6, 7};
  const int correct_array3[kSize3] = {6, 7, 1, 2, 3, 4, 5};

  ShiftArray(array3, kSize3, 12);
  cout << "Test 3\n";
  cout << PercentMatch(correct_array3, array3, kSize3) << "% match\n" << endl;
  return 0;
}
