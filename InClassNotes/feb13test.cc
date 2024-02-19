// Copyright 2024 Paksh Patel

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>

int LinearSearch(const int a[], int count, int lookin4) {
    int found_position = -1;
    for (int i = 0; i < count && found_position == -1; i++) {
        if (a[i] == lookin4) {
            found_position = i;
        }
    }
}
