//
// Created by Wynn Elease on 5/24/21.
//

#ifndef KURSACH_WAREHOUSE_H
#define KURSACH_WAREHOUSE_H

#include "List.h"
#include "Section.h"
#include <fstream>


class Warehouse {
private:
    std::string _name;
    list<Section> _sections;

public:
    explicit Warehouse(std::string & name);

    //work with sections
    void addSectionAfter(int numAfter, int num);
    void addSectionBefore(int numBefore, int num);
    void popSectionBefore(int num);
    void popSectionAfter(int num);
    void popSection(int num);
    Section *findSection(int num);
    void printWarehousesData(std::ostream & outFile);
    int  getCountOfSections();

    //work with specific section in warehouse
    void addCellToSectionAfter(int numOfSec, int numAfter, int num);
    void addCellToSectionBefore(int numOfSec, int numBefore, int num);
    void popFromSectionBefore(int numOfSec, int num);
    void popFromSectionAfter(int numOfSec, int num);
    void popFromSection(int numOfSec, int num);
    void printSectionsData(int numOfSec, std::ostream & outfile);
    int  getCountOfCellsInSection(int numOfSec);
    Cell *findCellInSection(int numOfSec, int num);
    void changeBusy(int numOfSec, int num);

    //work with files
    void parseFilesData(std::ifstream & in);

private:
    bool checkPromLine(std::string & str);
    int  parseSectionNum(std::string & str, int prevSec);
    void parseCellNum(std::string & str, int secNum);
    void addSectionBack(int num);

};


#endif //KURSACH_WAREHOUSE_H
