#include "Playlist.h"
#include "StringHelper.h"
#include "Song.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

Playlist::Playlist()
{
    
}

string Playlist::mode = "N";
int Playlist::playCnt = 0;


void Playlist::setMode(string m)
{
    mode = m;
}

void Playlist::addSong(Song h)
{
    songList.push_back(h);
    
}

void Playlist::clearList()
{
    songList.clear();
}

void Playlist::deleteSong(Song h)
{
    int i = 0;
    bool searched, dank;
    dank = false;
    while(i < songList.size())
    {
        searched = false;
        //search for the song to be deleted, if found, set searched and dank to true
        if(songList[i] == h)
        {
            searched = true;
            dank = true;
        }
        
        //if search is true, delete that song from the list every time it is found
        if(searched == true)
        {
            songList.erase(songList.begin() + i);
        }
        
        i++; //increment counter AFTER everything has occurred
    }
    cout << "YEP THIS HAPPEN" << endl;
    
    if(dank == true)//if dank is true or false print these messages
    {
        cout << "Song successfully deleted" << endl;
    }
    else if(dank == false)
    {
        cout << "No such song exists" << endl;
    }
}

void Playlist::play()
{
    if(mode == "N")//Normal mode
    {
        cout << endl << "NOW PLAYING: \n";
        if(playCnt < songList.size()) //as long as playCnt is less than the songList size, play the song
        {                 
            cout << songList[playCnt] << endl;
            playCnt++; //increase playCnt so the next song plays next time around
        }
        else
        {
            cout << "END OF PLAYLIST\n" << endl; //print if playCnt is larger than songList
        }
        
        
    }
    
    if(mode == "R")//Repeat mode
    {
        cout << endl << "NOW PLAYING: \n";
        if(playCnt < songList.size())
        {
            cout << songList[playCnt] << endl;
        }
        else
        {
            cout << songList[(playCnt - 1)];
        }
    }
    
    if(mode == "L")//Loop mode
    {
        cout << endl << "NOW PLAYING: \n";
        if(playCnt < songList.size())
        {
            cout << songList[playCnt] << endl;
            playCnt++; //increase playCnt so the next song plays next time around
        }
        else
        {
            playCnt = 0; //set playCnt to 0 so it goes to the beginning of the playlist
            cout << songList[playCnt] << endl; //play the first song again
            playCnt++; //increment playCnt so that the first song doesn't repeat
            
        }
    }
}

Playlist Playlist::intersect(Playlist &h)
{
    bool searched;
    int i, j, size1, size2;
    Playlist n;
    
    i = 0;
    while(i < songList.size())
    {
        j = 0;
        while(j < songList.size())
        {
            if(songList[i] == h.songList[j])
            {
                searched = true; //the song was found in both playlists   
                n.songList.push_back(songList[i]);
            }
            j++;
        }
        i++;
    }
    
    return n;
    
}

/**************************************************************
	 *                  operator+                                 *
	 *                                                            *
	 * Passed   : 2 arguments: Playlist and Song object           *
	 * Purpose  : Add song to playlist                            *
	 * Returns  : Playlist object                                 *
	 **************************************************************/
Playlist operator+(Playlist& lhs, Song& rhs)
{
    lhs.songList.push_back(rhs);
    return lhs;
    
}

/**************************************************************
	 *                  operator+                                 *
	 *                                                            *
	 * Passed   : 2 arguments: Playlist objects                   *
	 * Purpose  : Merge two playlists                             *
	 * Returns  : Playlist object                                 *
	 **************************************************************/
Playlist operator+(Playlist& lhs, Playlist& rhs)
{
    Playlist newOne;
    for(int i = 0; i < lhs.songList.size(); i++)
    {
        newOne.songList.push_back(lhs.songList[i]);
    }
    
    for(int i = 0; i < rhs.songList.size(); i++)
    {
        newOne.songList.push_back(rhs.songList[i]);
    }
    
    return newOne;
    
}


/**************************************************************
	 *                  operator-                                 *
	 *                                                            *
	 * Passed   : 2 arguments: Playlist and Song object           *
	 * Purpose  : Remove song from playlist                       *
	 * Returns  : Playlist object                                 *
	 **************************************************************/
Playlist operator-(Playlist& lhs, Song& rhs)
{
    int i = 0;
    bool searched, dank; 
    dank = false; //set dank to false 
    while(i < lhs.songList.size())
    {
        searched = false;
        //search for the song to be deleted, if found, set searched and dank to true
        if(lhs.songList[i] == rhs)
        {
            searched = true;
            dank = true;
        }
        
        
        
        //if search is true, delete that song from the list every time it is found
        if(searched == true)
        {
            lhs.songList.erase(lhs.songList.begin() + i);
        }
        
        i++; //increment counter AFTER everything has occurred
        
    }
    
    if(dank == true) //if dank is true or false, print these messages
    {
        cout << "Song successfully deleted" << endl;
    }
    else if(dank == false)
    {
        cout << "No such song exists" << endl;
    }
    return lhs;
    
}

/**************************************************************
	 *                 ostream operator<<                         *
	 *                                                            *
	 * Passed   : 2 arguments: ofstream and Playlist object       *
	 * Purpose  : Print playlist to console                       *
	 * Returns  : ofstream                                        *
	 **************************************************************/
ostream& operator<<(ostream& os, const Playlist& prnt)
{
//     os << prnt.songList.size() << endl; //this was just to see if this was working, kept in for later use
    
    for(int i = 0; i < prnt.songList.size(); i++)
    {
        os << prnt.songList[i] << endl;
    }
    
    
    return os;
}


/**************************************************************
	 *                 ofstream operator<<                        *
	 *                                                            *
	 * Passed   : 2 arguments: ofstream and Playlist object       *
	 * Purpose  : Print playlist to file                          *
	 * Returns  : ofstream                                        *
	 **************************************************************/
ofstream& operator<<(ofstream& os, const Playlist& prnt)
{
    for(int i = 0; i < prnt.songList.size(); i++)
    {
        os << prnt.songList[i];
    }
}
