//
// Created by Wynn Elease on 5/30/21.
//
#include "Warehouse.h"

Warehouse::Warehouse(std::string name) : _name(name) {};

void Warehouse::addSectionBack(int num) {
    _sections.push_back(Section(num));
}

void Warehouse::addSectionFront(int num) {
    _sections.push_front(Section(num));
}

void Warehouse::addSectionAfter(int numAfter, int num) {
    auto i = _sections.find(Section(numAfter));
    _sections.insert(i, Section(num));
}

void Warehouse::addSectionBefore(int numBefore, int num) {
    auto i = _sections.find(Section(numBefore));
    if (i == _sections.begin())
        _sections.push_front(Section(num));
    else
        _sections.insert(--i, Section(num));
}

void Warehouse::popSectionBack() {
    _sections.pop_back();
}

void Warehouse::popSectionFront() {
    _sections.pop_front();
}

void Warehouse::popSection(int num) {
    _sections.erase(_sections.find(Section(num)));
}

void Warehouse::popSectionAfter(int num) {
    _sections.erase(++_sections.find(Section(num)));
}

void Warehouse::popSectionBefore(int num) {
    _sections.erase(--_sections.find(Section(num)));
}

Section Warehouse::findSection(int num) {
    return *_sections.find(Section(num));
}

void Warehouse::printWarehousesData() {
    std::cout << "WAREHOUSE " << _name << std::endl;
    for (auto i = _sections.begin(); i != _sections.end(); ++i) {
        std::cout << "Section № " << *i->getNum() << "\n----------" << std::endl;
        *i->printCells();
    }
}

int Warehouse::getCountOfSections() { return _sections.size(); }


void Warehouse::addCellToSectionBack(int numOfSec, int num) {
    Section section(numOfSec);
    *_sections.find(section)->pushBackCell(num);
}

void Warehouse::addCellToSectionFront(int numOfSec, int num) {
    Section section(numOfSec);
    *_sections.find(section)->pushFrontCell(num);
}

void Warehouse::addCellToSectionAfter(int numOfSec, int numAfter, int num) {
    Section section(numOfSec);
    *(++_sections.find(section))->pushBackCell(num);
}

void Warehouse::addCellToSectionBefore(int numOfSec, int numBefore, int num) {
    Section section(numOfSec);
    *(--_sections.find(section))->pushBackCell(num);
}


void Warehouse::popFromSection(int numOfSec, int num) {
    Section section(numOfSec);
    *_sections.find(section)->popCell(num);
}

void Warehouse::popFromSectionFront(int numOfSec) {
    Section section(numOfSec);
    *_sections.find(section)->popCellFront(num);
}

void Warehouse::popFromSectionBack(int numOfSec) {
    Section section(numOfSec);
    *_sections.find(section)->popCellBack(num);
}

void Warehouse::popFromSectionAfter(int numOfSec, int num) {
    Section section(numOfSec);
    *_sections.find(section)->popCellBefore(num);
}

void Warehouse::popFromSectionAfter(int numOfSec, int num) {
    Section section(numOfSec);
    *_sections.find(section)->popCellAfter(num);
}

void Warehouse::printSectionsData(int numOfSec) {
    Section section(numOfSec);
    *_sections.find(section)->printCells();
}

int Warehouse::getCountOfCellsInSection(int numOfSec) {
    Section section(numOfSec);
    return (*_sections.find(section)->getCountOfCells());
}