//
// Created by Wynn Elease on 5/24/21.
//

#include <fstream>
#include "Section.h"

Section::Section(int sectionNum) : _sectionNum(sectionNum) {};

Cell *Section::findCell(int num) {
    Cell cell(num, false);
    return (cells.findElement(cell));
}

int Section::getCountOfCells() {
    return cells.size();
}

void Section::pushBackCell(int num) {
    cells.pushBack(Cell(num, false));
}

void Section::pushCellBefore(int numBefore, int num) {
    Cell cellBef(numBefore, false);
    Cell cell(num, false);
    cells.pushBefore(cellBef, cell);
}

void Section::pushCellAfter(int numAfter, int num) {
    Cell cellAfter(numAfter, false);
    Cell cell(num, false);
    cells.pushAfter(cellAfter, cell);
}

void Section::printCells(std::ostream & outFile) {
    outFile << " Section № " << _sectionNum;
    if (cells.isEmpty())
        outFile << std::endl;
    cells.printListsData(outFile);
}

void Section::popCell(int num) {
    Cell cell(num, false);
    cells.popElement(cell);
}

void Section::changeBusy(int num) {
    Cell cell(num, false);
    Cell *c = cells.findElement(cell);
    if (!c) std::cout << RED << "No such cell" << DEFAULT << std::endl;
    else c->changeBusyness();
}

bool Section::operator==(Section &section) const {
    return section.getNum() == _sectionNum;
}

int Section::getNum() { return _sectionNum; }