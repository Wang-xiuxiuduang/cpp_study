#ifndef RATEDPLAYER
#define RATEDPLAYER
#include "tabtenn0.h"

class RatedPlayer : public TableTennisPlayer {
private:
    unsigned int rating;  // 派生类增加的私有成员

public:
    // constructor
    RatedPlayer(const string &fn = "none", const string &ln = "none", bool ht = false,
                unsigned int r = 0);

    // deconstructor
    ~RatedPlayer() { std::cout << "RatedPlayer deconstructor..." << std::endl; };

    // other methods
    unsigned int getRating() const;
    void ResultRat(int);
};

#endif