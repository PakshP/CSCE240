// Copyright 2024 Paksh Patel
#ifndef PROGRAM5_SONGRECORDING_H_
#define PROGRAM5_SONGRECORDING_H_

#include <iostream>
#include <string>

namespace csce240_programming_assignment_5 {

class SongRecording {
 private:
    std::string title;
    std::string *artistNames;
    int numArtists;
    int trackLength;

 public:
  SongRecording(const std::string &title = "untitled",
                const std::string &primaryArtist = "unknown",
                int trackLength = 0,
                int numArtists = 1);

  // Copy constructor
  SongRecording(const SongRecording &other);
  // Assignment operator
  SongRecording &operator=(const SongRecording &other);
  // Destructor
  ~SongRecording();

  std::string GetTitle() const;
  void SetTitle(const std::string &title);

  int GetNumArtists() const;
  void SetNumArtists(int numArtists);

  void SetArtist(const std::string &name, int index = 1);
  std::string GetArtist(int index = 1) const;

  int GetTrackLength() const;
  void SetTrackLength(int length);
};

}  //  namespace csce240_programming_assignment_5

#endif  // PROGRAM5_SONGRECORDING_H_
