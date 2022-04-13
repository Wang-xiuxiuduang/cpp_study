#include "../header_files/stone_builder.h"

using namespace std;

void StoneBuilder::buildWindow() { house->setWindow(12); }

void StoneBuilder::buildWall() { house->setWall(24); }

void StoneBuilder::buildCeiling() { house->setCeiling(32); }