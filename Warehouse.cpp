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

Section *Warehouse::findSection(int num) { return &*_sections.find(Section(num)); }

void Warehouse::printWarehousesData(std::ostream & outFile) {
    outFile << "-----------------------------------------------" << std::endl;
    outFile << "           WAREHOUSE: " << _name << "         " << std::endl;
    outFile << "-----------------------------------------------" << std::endl;
    for (auto i = _sections.begin(); i != _sections.end(); ++i) {
        i->printCells(outFile);
        outFile << "-----------------------------------------------" << std::endl;
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

void Warehouse::printSectionsData(int numOfSec, std::ostream & outfile) {
    Section section(numOfSec);
    _sections.find(section)->printCells(outfile);
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
        try {
            num = std::stoi(tmp);
        } catch (std::exception & ex) {
            std::cout << RED << "Incorrect data in input file" << DEFAULT << std::endl;
            exit(0);
        }
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
        try {
            num = std::stoi(tmp);
        } catch (std::exception & ex) {
            std::cout << RED << "Incorrect data in input file" << DEFAULT << std::endl;
            exit(0);
        }
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