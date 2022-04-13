#include "headFiles/rp0.h"

#include <iostream>
using std::cout;

RatedPlayer::RatedPlayer(const string &fn, const string &ln, bool ht, unsigned int r)
    : TableTennisPlayer(fn, ln, ht), rating(r) {
    cout << "RatedPlayer constrector..." << std::endl;
}

unsigned int RatedPlayer::getRating() const { return rating; }

void RatedPlayer::ResultRat(int r) { rating = r; }
