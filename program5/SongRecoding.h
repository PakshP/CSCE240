// Copyright 2024 Paksh Patel
#include <iostream>
#include <string>

using std::string;

namespace csce240_programming_assignment_5 {
class SongRecording {
 private:
    string title;
    string * artist;
    int numOfArtists;
    int duration;
 
 public:
    SongRecording::SongRecording(string title, string * artist,
                                int duration, int numOfArtists);

};

}

// namespace csce240_programming_assignment_5
