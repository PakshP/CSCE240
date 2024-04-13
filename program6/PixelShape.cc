// Copyright 2024 Paksh Patel
#include "PixelShape.h"
#include <iostream>

namespace CSCE240_Program6 {

PixelShape::PixelShape(const std::string& name, char pixel)
  : name_((name.empty() ? "?" : name)), pixel_(pixel) {
}

void PixelShape::SetName(const std::string& name) {
    if (!name.empty()) {
        name_ = name;
    }
}

void PixelShape::SetPixel(char pixel) {
    if (pixel >= 33 && pixel <= 126) {
        pixel_ = pixel;
    }
}

void PixelShape::Print(bool fill) const {
    std::cout << name_ << std::endl;
}

} // namespace CSCE240_Program6
