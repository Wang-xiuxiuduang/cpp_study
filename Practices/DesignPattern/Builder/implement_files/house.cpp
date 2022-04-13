#include "../header_files/house.h"

#include <iostream>

void House::setWindow(int window) { this->window = window; }
void House::setWall(int wall) { this->wall = wall; }
void House::setCeiling(int ceiling) { this->ceiling = ceiling; }
void House::showHouse() {
    std::cout << window << " " << wall << " " << ceiling << std::endl;
}