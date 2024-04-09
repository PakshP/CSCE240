// Copyright 2024 Paksh Patel
#include <iostream>
#include <string>

#include "SongRecording.h"

namespace csce240_programming_assignment_5 {

SongRecording::SongRecording(const std::string& title,
                             const std::string& primaryArtist,
                             int trackLength,
                             int numArtists)
    : title(title), trackLength(trackLength),
      numArtists(numArtists > 0 ? numArtists : 1) {
  artistNames = new std::string[this->numArtists];
  artistNames[0] = primaryArtist;  // Assigning the primary artist
  for (int i = 1; i < this->numArtists; ++i) {
    artistNames[i] = "unknown";  // Fill remaining slots with "unknown"
  }
}

SongRecording::SongRecording(const SongRecording& other)
    : title(other.title), numArtists(other.numArtists),
      trackLength(other.trackLength) {
  artistNames = new std::string[numArtists];
  for (int i = 0; i < numArtists; ++i) {
    artistNames[i] = other.artistNames[i];
  }
}

SongRecording& SongRecording::operator=(const SongRecording& other) {
  if (this != &other) {
    delete[] artistNames;  // Free existing memory

    title = other.title;
    numArtists = other.numArtists;
    trackLength = other.trackLength;

    artistNames = new std::string[numArtists];
    for (int i = 0; i < numArtists; ++i) {
      artistNames[i] = other.artistNames[i];
    }
  }
  return *this;
}

SongRecording::~SongRecording() {
  delete[] artistNames;
}

std::string SongRecording::GetTitle() const {
  return title;
}

void SongRecording::SetTitle(const std::string& title) {
  if (!title.empty()) {
    this->title = title;
  }
}

int SongRecording::GetNumArtists() const {
  return numArtists;
}

void SongRecording::SetNumArtists(int numArtists) {
  if (numArtists > 0 && numArtists != this->numArtists) {
    std::string* newArtists = new std::string[numArtists];
    int minArtists = (numArtists < this->numArtists) ?
                      numArtists : this->numArtists;
    for (int i = 0; i < minArtists; ++i) {
      newArtists[i] = artistNames[i];
    }
    for (int i = this->numArtists; i < numArtists; ++i) {
      newArtists[i] = "unknown";
    }
    delete[] artistNames;
    artistNames = newArtists;
    this->numArtists = numArtists;
  }
}

void SongRecording::SetArtist(const std::string& name, int index) {
  if (index > 0 && index <= numArtists) {
    artistNames[index - 1] = name.empty() ? "unknown" : name;
  } else {
    artistNames[0] = "unknown";
  }
}

std::string SongRecording::GetArtist(int index) const {
  if (index > 0 && index <= numArtists) {
    return artistNames[index - 1].empty() ? "unknown" : artistNames[index - 1];
  } else {
    return "unknown";
  }
}

int SongRecording::GetTrackLength() const {
  if (trackLength < 0) {
    return 0;
  }
  return trackLength;
}

void SongRecording::SetTrackLength(int length) {
  if (length >= 0) {
    trackLength = length;
  }
}

}  // namespace csce240_programming_assignment_5
