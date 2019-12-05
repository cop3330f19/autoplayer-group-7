#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Song.h"
#include "StringHelper.h"

using namespace std;

Song::Song()
{

}

Song::Song(string title, string artist, string album, int length, int year)
{
    this -> title = title;
    this -> artist = artist;
    this -> album = album;
    this -> length = length;
    this -> year = year;
}


/**************************************************************
	 *                 ofstream operator<<                        *
	 *                                                            *
	 * Passed   : 2 arguments: ofstream and Song object           *
	 * Purpose  : Print song to file                              *
	 * Returns  : ofstream                                        *
	 **************************************************************/
ofstream & operator<<(ofstream& os, const Song& song)
{
    os << song.title << "," << song.artist << "," << song.album << "," << song.year << "," << song.length;
    return os;
}

/**************************************************************
	 *                 ostream operator<<                         *
	 *                                                            *
	 * Passed   : 2 arguments: ofstream and Song object           *
	 * Purpose  : Print song to console                           *
	 * Returns  : ofstream                                        *
	 **************************************************************/
ostream & operator<<(ostream& os, const Song& song)
{
    os << song.title << endl << song.artist << endl << song.album << " (" << song.year << ")" << endl;
    os << "Play Time: " << (song.length/60) << ":" << setfill('0') << setw(2) << (song.length%60) << endl;
    return os;
}

/**************************************************************
	 *                 ifstream operator>>                        *
	 *                                                            *
	 * Passed   : 2 arguments: ifstream and Song object           *
	 * Purpose  : Input song from file                            *
	 * Returns  : ifstream                                        *
	 **************************************************************/
ifstream& operator>>(ifstream& is, Song& song)
{
    
    getline(is, song.title, ',');
    getline(is, song.artist, ',');
    getline(is, song.album, ',');
    is >> song.year;
    is.ignore();
    is >> song.length;
    return is;
}

/**************************************************************
	 *                 istream operator>>                        *
	 *                                                           *
	 * Passed   : 2 arguments: istream and Song object           *
	 * Purpose  : Input song from console                        *
	 * Returns  : istream                                        *
	 **************************************************************/
istream& operator>>(istream& is, Song& song)
{
    cout << "Title: ";
    cin.ignore();
    getline(is, song.title);
    cout << "Artist: ";
    getline(is, song.artist);
    cout << "Album: ";
    getline(is, song.album);
    cout << "Year: ";
    is >> song.year;
    cout << "Length: ";
    is >> song.length;
    
    return is;
}

/**************************************************************
	 *                 bool operator==                            *
	 *                                                            *
	 * Passed   : 2 arguments: Two Song objects                   *
	 * Purpose  : Compare two songs                               *
	 * Returns  : 1, 0                                            *
	 **************************************************************/
bool operator==(const Song& lhs, const Song& rhs)
{
    

    if ((StringHelper::toUpper(lhs.title) == StringHelper::toUpper(rhs.title)) && 
        (StringHelper::toUpper(lhs.artist) == StringHelper::toUpper(rhs.artist)))
        return 1;
    return 0;

}

void Song::set(string title, string artist, string album, int length, int year)
{
    this -> title = title;
    this -> artist = artist;
    this -> album = album;
    this -> length = length;
    this -> year = year;
}