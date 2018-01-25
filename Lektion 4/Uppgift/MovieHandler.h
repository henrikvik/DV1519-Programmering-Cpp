#pragma once

#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

class MovieHandler 
{
public:
    MovieHandler();
    ~MovieHandler();

    void addMovie(string name, int year);
    bool removeMovie(string name, int year);
    void clear();

    int  getMovieCount() const;
    void getMoviesAsString(string movieStrings[], int movieStringsSize) const;

private:

};