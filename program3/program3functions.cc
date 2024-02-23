// Copyright 2024 Paksh Patel

#include <iostream>
#include <iomanip>

#include "program3functions.h"
#include "p3compares.h"

using std::cout;
using std::endl;


void RemoveValues(int array[], int size, int valueToRemove) {
    int shiftIndex = 0;

    for (int i = 0; i < size; ++i) {
        if (array[i] != valueToRemove) {
            array[shiftIndex] = array[i];
            shiftIndex++;
        }
    }

    for (int i = shiftIndex; i < size; ++i) {
        array[i] = -999;
    }
}

void ShiftArray(int array[], int size, int shiftAmount) {
    int kSize = size;
    int tempArray[kSize];
    for (int i = 0; i < size; ++i) {
        tempArray[i] = array[i];
    }

    for (int i = 0; i < size; ++i) {
        int shiftIndex = i + shiftAmount;
        while (shiftIndex < 0) {
            shiftIndex = size + shiftIndex;
        }
        while (shiftIndex >= size) {
            shiftIndex = shiftIndex - size;
        }
        array[i] = tempArray[shiftIndex];
    }
}

bool IsAnagram(const char array1[], const char array2[],
                bool caseSensitive) {
    int count[52] = {0};

    for (int i = 0; array1[i] != '\0'; i++) {
        char c = array1[i];
        if (!caseSensitive && c >= 'A' && c <= 'Z') {
            c += 32;
        }
        if (c >= 'a' && c <= 'z') {
            count[c - 'a']++;
        } else if (caseSensitive && c >= 'A' && c <= 'Z') {
            count[c - 'A' + 26]++;
        }
    }

    for (int i = 0; array2[i] != '\0'; i++) {
        char c = array2[i];
        if (!caseSensitive && c >= 'A' && c <= 'Z') {
            c += 32;
        }
        if (c >= 'a' && c <= 'z') {
            count[c - 'a']--;
        } else if (caseSensitive && c >= 'A' && c <= 'Z') {
            count[c - 'A' + 26]--;
        }
    }

    for (int i = 0; i < 52; ++i) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

bool Replace1With2(char array[], int size, char findChar,
                    char replaceChar1, char replaceChar2) {
    int length = 0;

    while (array[length] != '\0' && length < size) {
        ++length;
    }
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if (array[i] == findChar) {
            ++count;
        }
    }
    if (length + count > size - 1) {
        return false;
    }
    for (int i = length; i >= 0; --i) {
        if (array[i] == findChar) {
            for (int j = length; j > i; --j) {
                array[j + 1] = array[j];
            }
            array[i] = replaceChar1;
            array[i + 1] = replaceChar2;
            length++;
        }
    }
    array[length] = '\0';
    return true;
}

void SwapRowsAndColumns(int array[][kSquareSize]) {
    for (int i = 0; i < kSquareSize; ++i) {
        for (int j = i + 1; j < kSquareSize; ++j) {
            // Swap elements
            int temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }
}
