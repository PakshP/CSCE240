// Copyright 2024 CSCE240-003
// Define a Textbook class as a child of the Book class
#include"Book.h"
#include<iostream>
using std::ostream;

#ifndef _TEXTBOOK_H_
#define _TEXTBOOK_H_

namespace csce240_003_book_project {

class Textbook : public Book {
  // overloading the << operator
  friend ostream& operator << (ostream&, const Textbook&);

 public:
  Textbook();  // default constructor
  // our class has a pointer as a data member so we need to implement a
  // destructor, copy constructor, and assignment =
  ~Textbook() {
    // NOTE: derived class destructor is called before base class destructor
    //  std::cout << "In ~Textbook()" << std::endl;
    delete [] _has_problem_set;
  }

  Textbook& operator = (const Textbook& right);
  Textbook(const Textbook& to_copy);

  // the version of this function in the Book class doesn't do exactly what we
  // need it to do for a Textbook object, so we are REDEFINING it here
  void SetNumberOfChapters(int num);

  void SetChapterHasProblemSet(int ch, bool val = true);

 private:
  // true/false for each chapter in the textbook
  bool * _has_problem_set;
};  // end Textbook class definition

}  // end namespace csce240_003_book_project

#endif
