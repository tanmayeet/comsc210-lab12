// COMSC210 | Lab 12 | Tanmayee Chalamalasetti
// IDE Used: VS Code

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Constants

struct Song {
  std::string name;
  std::string genre;
  std::string artist;
  int weekNumber;
}

void readSongs(array<Song, 52>& playlist, const string& songs) {
  if (!songs.is_open()) {
    cout << "Error: Could not open file '" << songs
         << "'. Please check the file name and try again.\n";
    return;
  }
  ifstream file(songs);
  int num = 0;
  while (file && num < playlist.size()) {
    file >> playlist[num].name >> playlist[num].genre >> playlist[num].artist >>
        playlist[num].weekNumber;
    num++;
  }
  file.close();
}

void displaySongs(const array<Song, 52>& playlist) {
  cout << "Weekly Playlist!\n";
  for (const auto& song : playlist) {
    if (!song.name.empty()) {
      cout << "Week" << song.weekNumber << ": " << song.name << "  by "
           << song.artist << " [" << song.genre << "]\n";
    }
  }
}

void analyzePlaylist(const array<Song, 52>& playlist) {
  cout << "Playlist Wrapped:\n";
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
  array<Song, 52> playlist{};
  readSongs(playlist, "songs.txt");
  displaySongs(playlist);
  analyzePlaylist(playlist);

  return 0;
}