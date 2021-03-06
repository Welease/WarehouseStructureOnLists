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
    Section(int sectionNum);
    ~Section() = default;

    Cell *findCell(int num);
    void pushBackCell(int num);
    int  getCountOfCells();
    void pushCellBefore(int numBefore, int num);
    void pushCellAfter(int numAfter, int num);
    void printCells(std::ostream & outFile);
    void printCellsReverse(std::ostream & outFile);
    void popCell(int num);
    void changeBusy(int num);

    bool operator==(Section & section) const;
    int getNum();
};


#endif //KURSACH_SECTION_H
