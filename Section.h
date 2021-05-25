//
// Created by Wynn Elease on 5/24/21.
//

#ifndef KURSACH_SECTION_H
#define KURSACH_SECTION_H
#include "StaticList.h"
#include "Cell.h"

class Section {
private:
    int _sectionNum;
    StaticList<Cell> cells;

public:
    Section(int sectionNum) : _sectionNum(sectionNum) {}
    
};


#endif //KURSACH_SECTION_H
