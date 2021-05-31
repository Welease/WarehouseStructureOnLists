//
// Created by Wynn Elease on 5/24/21.
//

#ifndef KURSACH_WAREHOUSE_H
#define KURSACH_WAREHOUSE_H

#include "List.h"
#include "Section.h"

class Warehouse {
private:
    std::string _name;
    list<Section> _sections;

public:
    Warehouse(std::string & name);
    void addSectionBack(int num);
    void addSectionFront(int num);
    void addSectionAfter(int numAfter, int num);
    void addSectionBefore(int numBefore, int num);
    void popSectionBack();
    void popSectionFront();
    void popSectionBefore(int num);
    void popSectionAfter(int num);
    void popSection(int num);
    Section findSection(int num);
    void printWarehousesData();
    int  getCountOfSections();

    void addCellToSectionBack(int numOfSec, int num);
    void addCellToSectionFront(int numOfSec, int num);
    void addCellToSectionAfter(int numOfSec, int numAfter, int num);
    void addCellToSectionBefore(int numOfSec, int numBefore, int num);
    void popFromSectionBack(int numOfSec);
    void popFromSectionFront(int numOfSec);
    void popFromSectionBefore(int numOfSec, int num);
    void popFromSectionAfter(int numOfSec, int num);
    void popFromSection(int numOfSec, int num);
    void printSectionsData(int numOfSec);
    int  getCountOfCellsInSection(int numOfSec);
};


#endif //KURSACH_WAREHOUSE_H
