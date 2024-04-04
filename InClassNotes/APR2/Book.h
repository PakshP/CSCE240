// Copyright 2024 CSCE240-003
// Define a Book class
#ifndef _BOOK_H_
#define _BOOK_H_

#include<string>
using std::string;
#include<iostream>
using std::ostream;

namespace csce240_003_book_project {

class Book {
  friend ostream& operator << (ostream&, const Book&);

 public:
  explicit Book(string title = "unknown", int year = 2024, int num = 0);
  string GetTitle() const { return _title; }
  void SetTitle(string title);
  int GetYear() const { return _year_published; }
  void SetYear(int year);
  int GetNumberOfChapters() const { return _number_of_chapters; }
  void SetNumberOfChapters(int num);
  string GetChapterTitle(int chapter_number) const;
  void SetChapterTitle(int chapter_number, string chapter_title);

  // when we have a pointer as a data member we must overload the assignment
  // operator so that after assigning one object to another the data members
  // for two objects aren't pointing to the same location
  // since the left operand is a Book, we can overload this as a member
  // x = y
  Book& operator = (const Book& right);
  // we also must implement a copy constructor when we have pointers as data
  // members
  Book(const Book& to_copy);
  // and we need a destructor
  ~Book() {
     //  std::cout << "In ~Book()" << std::endl;
     delete [] _chapter_title;
  }

 private:
  string _title;
  int _year_published;
  int _number_of_chapters;
  string * _chapter_title;
};

}  // end namespace csce240_003_book_project

#endif

