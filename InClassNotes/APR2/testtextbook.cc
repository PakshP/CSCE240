// Copyright 2024 CSCE240-003
#include<iostream>
using std::cout;
using std::endl;
#include"Textbook.h"

// cpplint will complain about the line, we're going
// to ignore it because we're going to work with everything
// in this namespace
using namespace csce240_003_book_project;

int main() {
  Textbook t, t2;
  cout << t << endl;
  t.SetTitle("Absolute C++");
  t.SetNumberOfChapters(5);
  t.SetChapterHasProblemSet(3);
  t2 = t;  // use our overloaded assignment operator
  t2.SetNumberOfChapters(2);
  t2.SetChapterTitle(2, "Look at this");
  t2.SetChapterHasProblemSet(2);
  cout << "t = " << t << "\nt2 = " << t2 << endl;
  Textbook t3 = t2;  // t3(t2);
  t3.SetTitle("Another One");
  t3.SetChapterHasProblemSet(1);
  cout << "\n\nt2 = " << t2 << "\n\nt3 = " << t3 << endl;

  return 0;
}
