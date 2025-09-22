// COMSC210 | Lab 12 | Tanmayee Chalamalasetti
// IDE Used: VS Code

#include <array>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Constants
const int playlist_size = 52;
const string filename = "songs.txt";

// Song struct that holds different attributes of a song
struct Song {
  std::string name;
  std::string genre;
  std::string artist;
  int weekNumber;
};

// Function prototypes
void readSongs(array<Song, playlist_size>& playlist, const string& songs);
void displaySongs(const array<Song, playlist_size>& playlist);
void analyzePlaylist(const array<Song, playlist_size>& playlist);

// Function: Loads song data from 'songs.txt' into the playlist array we
// initialized
// argument: playlist array reference, filename string
// returns: nothing
void readSongs(array<Song, playlist_size>& playlist, const string& songs) {
  ifstream file(songs);

  if (!file.is_open()) {
    cout << "Error: Could not open file '" << songs
         << "'. Please check the file name and try again.\n";
    return;
  }

  int num = 0;
  while (file && num < playlist.size()) {
    file >> playlist[num].name >> playlist[num].genre >> playlist[num].artist >>
        playlist[num].weekNumber;

    if (playlist[num].weekNumber < 1 ||
        playlist[num].weekNumber > playlist_size) {
      cout << "Invalid week number (" << playlist[num].weekNumber
           << ") at line " << num + 1 << ". Skipping entry. \n"
           << endl;
    }
    num++;
  }
  file.close();
}

// Function: Prints songs in the playlist
// argument: playlist array reference
// returns: nothing
void displaySongs(const array<Song, playlist_size>& playlist) {
  cout << "Weekly Playlist!\n";
  for (const auto& song : playlist) {
    if (!song.name.empty()) {
      cout << "Week" << song.weekNumber << ": " << song.name << "  by "
           << song.artist << " [" << song.genre << "]\n";
    }
  }
}

// Function: Analyze the playlist on certain measures while using the std:array
// member functions argument: playlist array reference returns: nothing
void analyzePlaylist(const array<Song, playlist_size>& playlist) {
  cout << "Playlist Wrapped:\n";

  // Uses a for loop to print each song per week. Uses a traditional for loop to
  // iterate week number as well
  int week = 1;
  for (const auto& song : playlist) {
    cout << "Week " << week << ":" << song.name << endl;
    week++;
  }
  cout << "Total capacity: " << playlist.size() << endl;
  cout << "Is playlist empty? ";
  if (playlist.empty()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  cout << "First song: " << playlist.front().name << endl;
  cout << "Last song: " << playlist.back().name << endl;
}

int main() {
  // initialized a playlist array
  array<Song, playlist_size> playlist{};
  // Passing playlist throught the functions
  readSongs(playlist, filename);
  displaySongs(playlist);
  analyzePlaylist(playlist);

  return 0;
}