// Copyright 2024 Paksh Patel
#include <iostream>
#include <string>

#include "StreamingTrack.h"

namespace csce240_programming_assignment_5 {

StreamingTrack::StreamingTrack(const std::string& title,
                               const std::string& primaryArtist,
                               int trackLength,
                               int numArtists,
                               const std::string& primaryGenre,
                               int numStreams)
    : SongRecording(title, primaryArtist, trackLength, numArtists),
                      numStreams(numStreams), numGenres(1) {
  genres = new std::string[numGenres];
  genres[0] = primaryGenre;
}

StreamingTrack::StreamingTrack(const StreamingTrack& other)
    : SongRecording(other), numStreams(other.numStreams),
                            numGenres(other.numGenres) {
  genres = new std::string[numGenres];
  for (int i = 0; i < numGenres; ++i) {
    genres[i] = other.genres[i];
  }
}

StreamingTrack::StreamingTrack(const SongRecording& song, const std::string&
                               primaryGenre, int numStreams)
    : SongRecording(song), numStreams(numStreams), numGenres(1) {
  genres = new std::string[numGenres];
  genres[0] = primaryGenre;
}

StreamingTrack& StreamingTrack::operator=(const StreamingTrack& other) {
  if (this != &other) {
    SongRecording::operator=(other);  // Handle base class assignment
    delete[] genres;  // Free existing memory

    numStreams = other.numStreams;
    numGenres = other.numGenres;

    genres = new std::string[numGenres];
    for (int i = 0; i < numGenres; ++i) {
      genres[i] = other.genres[i];
    }
  }
  return *this;
}

StreamingTrack::~StreamingTrack() {
  delete[] genres;
}

int StreamingTrack::GetStreams() const {
  return numStreams;
}

void StreamingTrack::SetStreams(int streams) {
  if (streams >= 0) {
    numStreams = streams;
  }
}

void StreamingTrack::AddStreams(int streams) {
  if (streams >= 0) {
    numStreams += streams;
  }
}

int StreamingTrack::GetNumGenres() const {
  return numGenres;
}

std::string StreamingTrack::GetGenre(int index) const {
  if (index > 0 && index <= numGenres) {
    return genres[index - 1];
  } else {
    return "out of bounds";
  }
}

bool StreamingTrack::IsGenre(const std::string& genre) const {
  for (int i = 0; i < numGenres; ++i) {
    if (genres[i] == genre) {
      return true;
    }
  }
  return false;
}

void StreamingTrack::AddGenre(const std::string& genre) {
  if (!IsGenre(genre)) {
    std::string* newGenres = new std::string[numGenres + 1];
    for (int i = 0; i < numGenres; ++i) {
      newGenres[i] = genres[i];
    }
    newGenres[numGenres] = genre;
    delete[] genres;
    genres = newGenres;
    ++numGenres;
  }
}

void StreamingTrack::RemoveGenre(const std::string& genre) {
  if (IsGenre(genre)) {
    std::string* newGenres = new std::string[numGenres - 1];
    for (int i = 0, j = 0; i < numGenres; ++i) {
      if (genres[i] != genre) {
        newGenres[j++] = genres[i];
      }
    }
    delete[] genres;
    genres = newGenres;
    --numGenres;
  }
}

}  // namespace csce240_programming_assignment_5
