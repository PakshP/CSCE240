// Copyright 2024 Paksh Patel

#ifndef PROGRAM3_PROGRAM3FUNCTIONS_H_
#define PROGRAM3_PROGRAM3FUNCTIONS_H_

#include "p3compares.h"

void RemoveValues(int array[], int size, int valueToRemove);
void ShiftArray(int array[], int size, int positions);
bool IsAnagram(const char array1[], const char array2[],
                bool caseSensitive = false);
bool Replace1With2(char array[], int size, char findChar,
                    char replaceChar1, char replaceChar2);
void SwapRowsAndColumns(int array[][kSquareSize]);

#endif  // PROGRAM3_PROGRAM3FUNCTIONS_H_
