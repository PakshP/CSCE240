// Copyright 2024 Paksh Patel
#ifndef PROGRAM6_PIXELSHAPE_H_
#define PROGRAM6_PIXELSHAPE_H_

#include <string>

namespace CSCE240_Program6 {

class PixelShape {
private:
    std::string name_;
    char pixel_;

public:
    PixelShape(const std::string& name = "?", char pixel = '*');

    virtual ~PixelShape() {}

    void SetName(const std::string& name);
    void SetPixel(char pixel);

    std::string GetName() const { return name_; }
    char GetPixel() const { return pixel_; }

    virtual void Print(bool fill = true) const;

    // virtual PixelShape& operator*=(double factor) = 0;
};

} // namespace CSCE240_Program6

#endif // PROGRAM6_PIXELSHAPE_H_
