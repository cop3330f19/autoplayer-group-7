#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>


class Playlist
{
    private:
        int sizeOfVect;
        std::vector<Song> songList;
        static std::string mode;
        static int playCnt;
        
        
        
    public:
        Playlist();
        friend Playlist operator+(Playlist& lhs, Song& rhs);
        friend Playlist operator+(Playlist& lhs, Playlist& rhs);
        friend Playlist operator-(Playlist& lhs, Song& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Playlist& prnt);
        friend std::ofstream& operator<<(std::ofstream& os, const Playlist& prnt);
        void addSong(Song);
        void deleteSong(Song);
        Playlist intersect(Playlist&);
        void play();
        void clearList();
        static void setMode(std::string);
 
    
};





#endif