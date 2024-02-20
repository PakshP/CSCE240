// Copyright 2024 Paksh Patel

#include <iostream>
#include <iomanip>

#include "program3functions.h"
#include "p3compares.h"

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
