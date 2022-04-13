#include "../header_files/director.h"

void Director::construct(IBuilder* ibuilder) {
    // 1.建造窗户
    ibuilder->buildWindow();
    // 2.建造墙
    ibuilder->buildWall();
    // 3.建造窗户
    ibuilder->buildCeiling();
}