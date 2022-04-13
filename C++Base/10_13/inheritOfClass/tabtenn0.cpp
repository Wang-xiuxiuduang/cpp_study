#include "headFiles/tabtenn0.h"

#include <iostream>

using std::cout;

// constructors
TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht)
    : firstName(fn), lastName(ln), hasTable(ht) {
    cout << "TableTennisPlayer constrector..." << std::endl;
}

TableTennisPlayer::TableTennisPlayer() = default;

// other methods
bool TableTennisPlayer::HasTable() const { return hasTable; }

void TableTennisPlayer::getName() const { std::cout << lastName << " " << firstName << std::endl; }

void TableTennisPlayer::ResetTable(bool v) { hasTable = v; }
