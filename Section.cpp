//
// Created by Wynn Elease on 5/24/21.
//

#include "Section.h"

Section::Section(int sectionNum) : _sectionNum(sectionNum) {};

void Section::pushBackCell(int num) {
    cells.pushBack(Cell(num, false));
}

void Section::pushFrontCell(int num) {
    cells.pushFront(Cell(num, false));
}

int Section::findCell(int num) {
    Cell cell(num, false);
    return (cells.findElement(cell));
}

int Section::getCountOfCells() {
    return cells.size();
}

void Section::pushCellBefore(int numBefore, int num) {
    Cell cellBef(numBefore, false);
    Cell cell(num, false);
    cells.pushBefore(cellBef, cell);
}

void Section::pushCellAfter(int numAfter, int num) {
    Cell cellAfter(numAfter, false);
    Cell cell(num, false);
    cells.pushBefore(cellAfter, cell);
}

void Section::printCells() {
    std::cout << "Section № " << _sectionNum << std::endl;
    cells.printListsData();
}

void Section::popCell(int num) {
    Cell cell(num, false);
    cells.popElement(cell);
}

void Section::popCellBack() {
    cells.popBack();
}

void Section::popCellFront() {
    cells.popFront();
}

void Section::popCellAfter(int num) {
    Cell cell(num, false);
    cells.popAfter(cell);
}

void Section::popCellBefore(int num) {
    Cell cell(num, false);
    cells.popBefore(cell);
}

bool Section::operator==(Section &section) {
    return section.getNum() == _sectionNum;
}

int Section::getNum() { return _sectionNum; }