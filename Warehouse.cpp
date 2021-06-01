//
// Created by Wynn Elease on 5/30/21.
//
#include "Warehouse.h"

Warehouse::Warehouse(std::string & name) : _name(name) {};

void Warehouse::addSectionAfter(int numAfter, int num) {
    auto i = _sections.find(Section(numAfter));
    _sections.insert(++i, Section(num));
}

void Warehouse::addSectionBefore(int numBefore, int num) {
    if (_sections.empty()) {
        _sections.push_front(Section(num));
        return;
    }
    auto i = _sections.find(Section(numBefore));
    if (i == _sections.end()) std::cout << RED << "No such element in warehouse" << DEFAULT << std::endl;
    else if (i == _sections.begin()) _sections.push_front(Section(num));
    else _sections.insert(i, Section(num));
}

void Warehouse::popSection(int num) { _sections.erase(_sections.find(Section(num))); }

void Warehouse::popSectionAfter(int num) { _sections.erase(++_sections.find(Section(num))); }

void Warehouse::popSectionBefore(int num) { _sections.erase(--_sections.find(Section(num))); }

Section *Warehouse::findSection(int num) { return &*_sections.find(Section(num)); }

void Warehouse::printWarehousesData() {
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "           WAREHOUSE: " << _name << "         " << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    for (auto i = _sections.begin(); i != _sections.end(); ++i) {
        i->printCells();
        std::cout << "-----------------------------------------------" << std::endl;
    }
}

int Warehouse::getCountOfSections() { return static_cast<int>(_sections.size()); }

void Warehouse::addCellToSectionAfter(int numOfSec, int numAfter, int num) {
    Section section(numOfSec);
    (_sections.find(section))->pushCellAfter(numAfter, num);
}

void Warehouse::addCellToSectionBefore(int numOfSec, int numBefore, int num) {
    Section section(numOfSec);
    (_sections.find(section))->pushCellBefore(numBefore, num);
}


void Warehouse::popFromSection(int numOfSec, int num) {
    Section section(numOfSec);
    _sections.find(section)->popCell(num);
}

void Warehouse::popFromSectionAfter(int numOfSec, int num) {
    Section section(numOfSec);
    _sections.find(section)->popCellAfter(num);
}

void Warehouse::popFromSectionBefore(int numOfSec, int num) {
    Section section(numOfSec);
    _sections.find(section)->popCellBefore(num);
}

void Warehouse::printSectionsData(int numOfSec) {
    Section section(numOfSec);
    _sections.find(section)->printCells();
}

int Warehouse::getCountOfCellsInSection(int numOfSec) {
    Section section(numOfSec);
    return (_sections.find(section)->getCountOfCells());
}

Cell *Warehouse::findCellInSection(int numOfSec, int num) {
    Section *sec = findSection(numOfSec);
    return sec->findCell(num);
}

void Warehouse::changeBusy(int numOfSec, int num) {
    Section section(numOfSec);
    _sections.find(section)->changeBusy(num);
}

bool Warehouse::checkPromLine(std::string &str) {
    size_t tmp;
    tmp = str.find('\n');
    if (tmp == 0) return true;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != '-')
            return false;
    }
    return true;
}

int  Warehouse::parseSectionNum(std::string &str, int prevSec) {
    size_t ind = str.find("Section");
    int num = prevSec;
    std::string tmp;
    if (ind != str.npos) {
        tmp = str.substr(ind + 12, str.length());
        num = std::stoi(tmp);
        addSectionBack(num);
    }
    return num;
}

void Warehouse::addSectionBack(int num) {
    _sections.push_back(Section(num));
}

void Warehouse::parseCellNum(std::string &str, int secNum) {
    size_t ind = str.find("Cell");
    int num;
    std::string tmp;
    if (ind != str.npos) {
        tmp = str.substr(ind + 9, str.length());
        num = std::stoi(tmp);
        _sections.find(Section(secNum))->pushBackCell(num);
        if ((ind = str.find('(')) != str.npos) {
            tmp = str.substr(ind , ind + 5);
            if (tmp == "(busy)")
                changeBusy(secNum, num);
        }
    }
}

void Warehouse::parseFilesData(std::ifstream &in) {
    std::string line;
    int curSection;
    while (getline(in, line)) {
        if (line.find(':') != line.npos) {
            _name = line.substr(line.find(':') + 2, line.length());
            std::cout << _name << std::endl;
        }
        if (checkPromLine(line)) continue;
        curSection = parseSectionNum(line, curSection);
        parseCellNum(line, curSection);
    }
    curSection = 0;
}