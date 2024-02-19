// Copyright 2024 bhipp
#ifndef _P3COMPARES_H_
#define _P3COMPARES_H_

const int kSquareSize = 10;

// pre-conditions: the arguments are integer arrays of the same size
// post-condition: returns a double between 0 and 100 representing the percent
//                 of values in the second array that match the corresponding
//                 values in the first array
double PercentMatch(const int[], const int[], int size);

// preconditions: the arguments are character arrays of the same size
//                the first array contains a null character terminating
//                the cstring
// postcondition: returns a double between 0 and 100 representing the percent
//                of values in the second array that match the corresponding
//                values in the first array through the first null character
//                in the first array
double PercentMatch(const char[], const char[]);

// preconditions: the two arguments are square integer arrays with
//                kSquareSize rows and kSquareSize columns
// postcondition: returns a double between 0 and 100 representing the percent
//                of values in the second array that match the corresponding
//                values in the first array
double PercentMatch(const int[][kSquareSize], const int[][kSquareSize]);

#endif
