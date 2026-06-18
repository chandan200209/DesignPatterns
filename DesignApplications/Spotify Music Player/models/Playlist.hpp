#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Song.hpp"
using namespace std;

class Playlist
{
private:
    vector<Song *> songList;
    string playlistName;

public:
    Playlist(string name)
    {
        playlistName = name;
    }
    string getPlaylistName()
    {
        return playlistName;
    }
    const vector<Song *> getSongs()
    {
        return songList;
    }
    int getSize()
    {
        return (int)songList.size();
    }
    void addSongsToPlaylist(Song *song)
    {
        if (song == nullptr)
        {
            throw runtime_error("Cannot add NULL song to playlist.");
        }
        songList.push_back(song);
    }
};