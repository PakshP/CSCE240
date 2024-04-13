// Copyright 2024 Paksh Patel
#include "RightIsosceles.h"
#include <iostream>

namespace CSCE240_Program6 {
    RightIsosceles::RightIsosceles(int legLength, char pixel)
        : PixelShape("right isosceles triangle", pixel),
          legLength((legLength >= 2) ? legLength : 2) {}

    RightIsosceles::~RightIsosceles() {}

    void RightIsosceles::SetLeg(int length) {
        if (length >= 1) {
            legLength = length;
        }
    }

    int RightIsosceles::GetLeg() const {
        return legLength;
    }

    RightIsosceles& RightIsosceles::operator*=(double factor) {
        int newLength = static_cast<int>(legLength * factor);
        if (newLength >= 2) {
            legLength = newLength;
        }
        return *this;
    }

    void RightIsosceles::Print(bool fill) const {
    std::cout << GetName() << std::endl;
    if (fill) {
        for (int i = 1; i <= legLength; ++i) {
            for (int j = 1; j <= i; ++j) {
                std::cout << GetPixel() << " ";
            }
            std::cout << std::endl;
        }
    } else {
        for (int i = 1; i <= legLength; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (j == 1 || j == i || i == legLength) {
                    std::cout << GetPixel() << " ";
                } else {
                    std::cout << "  ";
                }
            }
            std::cout << std::endl;
        }
    }
    }
}  // namespace CSCE240_Program6
