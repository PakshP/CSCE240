// Copyright 2024 Paksh Patel
#include <iostream>
#include <string>
using std::string;

#include "SongRecording.h"

namespace csce240_programming_assignment_5 {

SongRecording::SongRecording(const string& title, const string& primaryArtist,
                             int trackLength, int numArtists)
    : title(title), trackLength(trackLength >= 0 ?
      trackLength : 0), numArtists(numArtists > 0 ? numArtists : 1) {
  artistNames = new string[this->numArtists];
  artistNames[0] = primaryArtist;  // Assigning the primary artist
  for (int i = 1; i < this->numArtists; ++i) {
    artistNames[i] = "unknown";  // Fill remaining slots with "unknown"
  }
}

SongRecording::SongRecording(const SongRecording& other)
    : title(other.title), numArtists(other.numArtists),
      trackLength(other.trackLength) {
  artistNames = new string[numArtists];
  for (int i = 0; i < numArtists; ++i) {
    artistNames[i] = other.artistNames[i];
  }
}

SongRecording& SongRecording::operator=(const SongRecording& other) {
  if (this != &other) {
    string* newArtistNames = new string[other.numArtists];
    for (int i = 0; i < other.numArtists; ++i) {
      newArtistNames[i] = other.artistNames[i];
    }

    delete[] artistNames;  // Free existing memory
    artistNames = newArtistNames;

    title = other.title;
    numArtists = other.numArtists;
    trackLength = other.trackLength;
  }
  return *this;
}

SongRecording::~SongRecording() {
  delete[] artistNames;
}

string SongRecording::GetTitle() const {
  return title;
}

void SongRecording::SetTitle(const string& title) {
  if (!title.empty()) {
    this->title = title;
  }
}

int SongRecording::GetNumArtists() const {
  return numArtists;
}

void SongRecording::SetNumArtists(int newNumArtists) {
  if (newNumArtists > 0 && newNumArtists != this->numArtists) {
    string* newArtists = new string[newNumArtists];
    int copyCount = this->numArtists < newNumArtists ?
                    this->numArtists : newNumArtists;
    for (int i = 0; i < copyCount; ++i) {
      newArtists[i] = artistNames[i];
    }
    for (int i = this->numArtists; i < newNumArtists; ++i) {
      newArtists[i] = "unknown";
    }
    delete[] artistNames;
    artistNames = newArtists;
    this->numArtists = newNumArtists;
  }
}

void SongRecording::SetArtist(const string& name, int index) {
  if (!name.empty() && index > 0 && index <= numArtists) {
    artistNames[index - 1] = name;
  }
}

string SongRecording::GetArtist(int index) const {
  if (index > 0 && index <= numArtists) {
    return artistNames[index - 1].empty() ? "unknown" : artistNames[index - 1];
  }
  return "out of bounds";
}

int SongRecording::GetTrackLength() const {
  return trackLength;
}

void SongRecording::SetTrackLength(int length) {
  if (length >= 0) {
    trackLength = length;
  }
}

}  // namespace csce240_programming_assignment_5
