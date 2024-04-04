// Copyright 2024 CSCE240-003
// Implement the functionality of our Book class
#include"Book.h"
#include<string>
using std::string;

namespace csce240_003_book_project {

ostream& operator << (ostream& where, const Book& what) {
  where << "\nTitle: " << what._title << "\nYear Published: "
        << what._year_published;
  // output the chapter titles
  for ( int i = 0; i < what._number_of_chapters; ++i ) {
    where << "\n\tChapter " << i + 1 << ": " << what._chapter_title[i];
  }
  return where;
}


Book::Book(string title, int year, int num) : _title("unknown"),
     _year_published(2024), _number_of_chapters(0), _chapter_title(nullptr) {
  SetTitle(title);
  SetYear(year);
  SetNumberOfChapters(num);
}

string Book::GetChapterTitle(int chapter_number) const {
  if ( chapter_number >= 1 && chapter_number <= _number_of_chapters )
    return _chapter_title[chapter_number - 1];
  return "invalid chapter number";
}

void Book::SetChapterTitle(int chapter_number, string title) {
  if ( chapter_number >= 1 && chapter_number <= _number_of_chapters )
    _chapter_title[chapter_number - 1] = title;
}

void Book::SetNumberOfChapters(int num) {
  if ( num >= 0 && num != _number_of_chapters ) {
    // need to update _chapter_title - Come back to this NEXT!!
    if ( _chapter_title != nullptr )
      delete [] _chapter_title;
    _chapter_title = new string[num];
    for ( int i = 0; i < num; ++i )
      _chapter_title[i] = "chapter";
    _number_of_chapters = num;
  }
}

Book& Book::operator = (const Book& right) {
  _title = right._title;
  _year_published = right._year_published;
  SetNumberOfChapters(right._number_of_chapters);
  for ( int i = 0; i < _number_of_chapters; ++i )
    _chapter_title[i] = right._chapter_title[i];
  return *this;
}

Book::Book(const Book& b) : _title(b._title),
                            _year_published(b._year_published),
                            _number_of_chapters(0), _chapter_title(nullptr) {
  SetNumberOfChapters(b._number_of_chapters);
  for ( int i = 0; i < _number_of_chapters; ++i )
    _chapter_title[i] = b._chapter_title[i];
}


void Book::SetYear(int year) {
  _year_published = year;
}

void Book::SetTitle(string title) {
  if ( title.length() > 0 )
    _title = title;
}

}  // csce240_003_book_project
