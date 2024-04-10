// Copyright 2024 Paksh Patel
#ifndef PROGRAM5_STREAMINGTRACK_H_
#define PROGRAM5_STREAMINGTRACK_H_

#include "SongRecording.h"
#include <iostream>
#include <string>

namespace csce240_programming_assignment_5 {

class StreamingTrack : public SongRecording {
 private:
  int numStreams;
  std::string* genres;
  int numGenres;

 public:
  StreamingTrack(const std::string& title = "untitled",
                 const std::string& primaryArtist = "unknown",
                 int trackLength = 0,
                 int numArtists = 1,
                 const std::string& primaryGenre = "pop",
                 int numStreams = 0);
  // Copy constructor
  StreamingTrack(const StreamingTrack& other);
  // Additional constructor
  StreamingTrack(const SongRecording& song, const std::string&
                 primaryGenre = "pop", int numStreams = 0);
  // Assignment operator
  StreamingTrack& operator=(const StreamingTrack& other);
  // Destructor
  ~StreamingTrack();

  int GetStreams() const;
  void SetStreams(int streams);
  void AddStreams(int streams);

  int GetNumGenres() const;

  std::string GetGenre(int index = 1) const;
  bool IsGenre(const std::string& genre) const;
  void AddGenre(const std::string& genre);
  void RemoveGenre(const std::string& genre);
};

}  // namespace csce240_programming_assignment_5


#endif  // PROGRAM5_STREAMINGTRACK_H_
