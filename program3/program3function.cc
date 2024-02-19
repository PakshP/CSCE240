// Copyright 2024 Paksh Patel

#include <iostream>
#include <iomanip>

#include "./p3compares.h"
#include "./program3functions.h"

void RemoveValues(int array[], int size, int valueToRemove) {
  int index = 0;
  for (int i = 0; i < size; i++) {
    if (array[i] != valueToRemove) {
      array[index] = array[i];
      index++;
    }
  }
  for (int i = index; i < size; i++) {
    array[i] = 0;
  }
}

void ShiftArray(int array[], int size, int positions) {
  int temp;
  for (int i = 0; i < positions; i++) {
    temp = array[size - 1];
    for (int j = size - 1; j > 0; j--) {
      array[j] = array[j - 1];
    }
    array[0] = temp;
  }
}

bool IsAnagram(const char array1[], const char array2[],
                bool caseSensitive = false) {
  int count1[256] = {0};
  int count2[256] = {0};
  int i;
  for (i = 0; array1[i] && array2[i]; i++) {
    if (caseSensitive) {
      count1[array1[i]]++;
      count2[array2[i]]++;
    } else {
      count1[tolower(array1[i])]++;
      count2[tolower(array2[i])]++;
    }
  }
  if (array1[i] || array2[i]) {
    return false;
  }
  for (i = 0; i < 256; i++) {
    if (count1[i] != count2[i]) {
      return false;
    }
  }
  return true;
}

bool Replace1With2(char array[], int size, char findChar,
                    char replaceChar1, char replaceChar2) {
  bool found = false;
  for (int i = 0; i < size; i++) {
    if (array[i] == findChar) {
      if (found) {
        array[i] = replaceChar2;
      } else {
        array[i] = replaceChar1;
      }
      found = !found;
    }
  }
  return found;
}

void SwapRowsAndColumns(int array[][kSquareSize], int size) {
  int temp;
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      temp = array[i][j];
      array[i][j] = array[j][i];
      array[j][i] = temp;
    }
  }
}
