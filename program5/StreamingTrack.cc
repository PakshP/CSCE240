// Copyright 2024 Paksh Patel
#include <iostream>
#include <string>

#include "StreamingTrack.h"
#include "SongRecording.h"

namespace csce240_programming_assignment_5 {

StreamingTrack::StreamingTrack(const std::string& title,
                               const std::string& primaryArtist,
                               int trackLength,
                               int numArtists,
                               const std::string& primaryGenre,
                               int numStreams) :
                               SongRecording(title, primaryArtist,
                                             trackLength, numArtists,
                                             primaryGenre) {
  numStreams = numStreams;
  numGenres = 0;
  genres = new std::string[1];
}

StreamingTrack::StreamingTrack(const StreamingTrack& other) :
                               SongRecording(other) {
  numStreams = other.numStreams;
  numGenres = other.numGenres;
  genres = new std::string[numGenres];
  for (int i = 0; i < numGenres; ++i)
    genres[i] = other.genres[i];
}

StreamingTrack::StreamingTrack(const SongRecording& song,
                               const std::string& primaryGenre,
                               int numStreams) : SongRecording(song) {
  numStreams = numStreams;
  numGenres = 0;
  genres = new std::string[1];
}

StreamingTrack& StreamingTrack::operator=(const StreamingTrack& other) {
  if (this == &other)
    return *this;

  SongRecording::operator=(other);

  numStreams = other.numStreams;
  numGenres = other.numGenres;
  genres = new std::string[numGenres];
  for (int i = 0; i < numGenres; ++i)
    genres[i] = other.genres[i];

  return *this;
}

StreamingTrack::~StreamingTrack() {
  delete[] genres;
}

int StreamingTrack::GetStreams() const {
  return numStreams;
}

void StreamingTrack::SetStreams(int streams) {
  numStreams = streams;
}

void StreamingTrack::AddStreams(int streams) {
  numStreams += streams;
}

int StreamingTrack::GetNumGenres() const {
  return numGenres;
}

std::string StreamingTrack::GetGenre(int index) const {
  if (index < 0 || index >= numGenres)
    return "";
  return genres[index];
}

bool StreamingTrack::IsGenre(const std::string& genre) const {
  for (int i = 0; i < numGenres; ++i)
    if (genres[i] == genre)
      return true;
  return false;
}

void StreamingTrack::AddGenre(const std::string& genre) {
  std::string* temp = new std::string[numGenres + 1];
  for (int i = 0; i < numGenres; ++i)
    temp[i] = genres[i];
  temp[numGenres] = genre;
  delete[] genres;
  genres = temp;
  ++numGenres;
}

void StreamingTrack::RemoveGenre(const std::string& genre) {
  int index = -1;
  for (int i = 0; i < numGenres; ++i)
    if (genres[i] == genre) {
      index = i;
      break;
    }
  if (index == -1)
    return;

  std::string* temp = new std::string[numGenres - 1];
  for (int i = 0; i < index; ++i)
    temp[i] = genres[i];
  for (int i = index + 1; i < numGenres; ++i)
    temp[i - 1] = genres[i];
  delete[] genres;
  genres = temp;
  --numGenres;
}

}  // namespace csce240_programming_assignment_5
