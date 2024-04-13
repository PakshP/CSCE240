// Copyright 2024 Paksh Patel
#ifndef PROGRAM6_RECTANGLE_H_
#define PROGRAM6_RECTANGLE_H_

#include "PixelShape.h"

namespace CSCE240_Program6 {
class Rectangle : public PixelShape {
 private:
    int length, width;
 public:
    explicit Rectangle(int length = 2, int width = 1, char pixel = '*');
    virtual ~Rectangle();
    void SetLength(int length);
    void SetWidth(int width);
    int GetLength() const;
    int GetWidth() const;
    Rectangle& operator*=(double factor);
    void Print(bool fill = true) const override;
};

}  // namespace CSCE240_Program6

#endif  // PROGRAM6_RECTANGLE_H_
