#ifndef HOUSE_H
#define HOUSE_H

#include <string>

class House {
private:
    int window;
    int wall;
    int ceiling;

public:
    void setWindow(int window);
    void setWall(int wall);
    void setCeiling(int ceiling);
    void showHouse();
};

#endif