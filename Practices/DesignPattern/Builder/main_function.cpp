#include <iostream>

#include "header_files/director.h"
#include "header_files/house.h"
#include "header_files/i_builder.h"
#include "header_files/stone_builder.h"

int main() {
    // 建造 stone house 的全过程
    Director* director = new Director();
    IBuilder* stoneBuilder = new StoneBuilder();
    director->construct(stoneBuilder);
    House* stoneHouse = stoneBuilder->getResult();
    stoneHouse->showHouse();
}