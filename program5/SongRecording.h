// Copyright 2024 Paksh Patel
#ifndef PROGRAM5_SONGRECORDING_H_
#define PROGRAM5_SONGRECORDING_H_

#include <iostream>
#include <string>
using std::string;

namespace csce240_programming_assignment_5 {

class SongRecording {
 private:
    string title;
    int trackLength;
    int numArtists;
    string* artistNames;

 public:
  SongRecording(const string& title = "untitled",
                const string& primaryArtist = "unknown",
                int trackLength = 0,
                int numArtists = 1);

  // Copy constructor
  SongRecording(const SongRecording &other);
  // Assignment operator
  SongRecording &operator=(const SongRecording &other);
  // Destructor
  ~SongRecording();

  string GetTitle() const;
  void SetTitle(const string &title);

  int GetNumArtists() const;
  void SetNumArtists(int numArtists);

  void SetArtist(const string &name, int index = 1);
  string GetArtist(int index = 1) const;

  int GetTrackLength() const;
  void SetTrackLength(int length);
};

}  //  namespace csce240_programming_assignment_5

#endif  // PROGRAM5_SONGRECORDING_H_
