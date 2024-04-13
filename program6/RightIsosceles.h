// Copyright 2024 Paksh Patel
#ifndef PROGRAM6_RIGHTISOSCELES_H_
#define PROGRAM6_RIGHTISOSCELES_H_

#include "PixelShape.h"

namespace CSCE240_Program6 {
class RightIsosceles : public PixelShape {
 private:
  int legLength;
 public:
  explicit RightIsosceles(int legLength = 2, char pixel = '*');
  virtual ~RightIsosceles();
  void SetLeg(int length);
  int GetLeg() const;
  RightIsosceles& operator*=(double factor);
  void Print(bool fill = true) const override;
};

}  // namespace CSCE240_Program6

#endif  // PROGRAM6_RIGHTISOSCELES_H_
