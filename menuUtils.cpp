//
// Created by Wynn Elease on 6/1/21.
//
#include "menuUtils.h"

int checkInput() {
    int a = -1;
    bool flag = false;
    while (a < 0) {
        if (flag)
            std::cout << RED << "Incorrect input, please try again: " << DEFAULT;
        while (!(std::cin >> a) || (std::cin.peek() != '\n')) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << RED << "Incorrect input, please try again: " << DEFAULT;
        }
        flag = true;
    }
    return a;
}

void menuForSpecificSection(Warehouse & warehouse, std::string & input, std::ostream & of) {
    int secNum, tmp = 0, cellNum;
    Cell *cell;
    if (warehouse.getCountOfSections()) {
        std::cout << "Input number of section: ";
        secNum = checkInput();
        if (warehouse.findSection(secNum)) {
            if (input == "8") {
                if (warehouse.findSection(secNum)->getCountOfCells()) {
                    std::cout << "Input number of cell after which: ";
                    tmp = checkInput();
                }
                std::cout << "Input number of new cell: ";
                warehouse.addCellToSectionAfter(secNum, tmp, checkInput());
            } else if (input == "9") {
                if (warehouse.findSection(secNum)->getCountOfCells()) {
                    std::cout << "Input number of cell before which: ";
                    tmp = checkInput();
                }
                std::cout << "Input number of new cell: ";
                warehouse.addCellToSectionBefore(secNum, tmp, checkInput());
            } else if (input == "10") {
                std::cout << "Input number of cell: ";
                warehouse.popFromSection(secNum, checkInput());
            } else if (input == "11") warehouse.printSectionsData(secNum, std::cout);
            else if (input == "12")
                std::cout << "In section " << secNum << ": " << warehouse.getCountOfCellsInSection(secNum) << " cells" << std::endl;
            else if (input == "13") {
                std::cout << "Input number of cell: ";
                cellNum = checkInput();
                if (!(cell = warehouse.findCellInSection(secNum, cellNum)))
                    std::cout << RED << "No such cell in this section" << DEFAULT << std::endl;
                else std::cout << *cell << std::endl;
            }
            else if (input == "14") {
                std::cout << "Input number of cell: ";
                warehouse.changeBusy(secNum, checkInput());
            }
            else if (input == "15") {
                warehouse.printSectionsDataReverse(secNum, std::cout);
            }
        } else std::cout << RED << "No such section in warehouse" << DEFAULT << std::endl;
    } else std::cout << RED << "Warehouse is empty" << DEFAULT << std::endl;
}

void printWelcomeMessage() {
    std::cout << BLUE << "Choose option:\n" <<
              "1 - Add section before input section\n" <<
              "2 - Add section after input section\n" <<
              "3 - Delete input section\n" <<
              "4 - Get count of sections in warehouse\n" <<
              "5 - Print warehouse's data\n" <<
              "6 - Find input section\n" <<
              "7 - Save in file\n" <<
              "r - Print warehouse's data in reverse order\n"

              "Work with specific section:\n"
              "8 - Add cell after input to specific section\n" <<
              "9 - Add cell before input to specific section\n" <<
              "10 - Delete cell from specific section\n" <<
              "11 - Print cells from specific section\n" <<
              "12 - Get count of cells in specific section\n" <<
              "13 - Find input cell in specific section\n" <<
              "14 - Change cell occupancy\n" <<
              "15 - Print cells from specific section in reverse order\n" <<
              "0 - exist\n====>" << DEFAULT << std::endl;
}


void menuForWarehouse(Warehouse & warehouse, std::ostream & outFile) {
    std::string input;
    int cellNum;
    Section * sec;
    while (1) {
        printWelcomeMessage();
        std::cin >> input;
        if (input == "1") {
            if (warehouse.getCountOfSections()) {
                std::cout << "Input number of section before which: ";
                cellNum = checkInput();
            }
            std::cout << "Input number of new section: ";
            warehouse.addSectionBefore(cellNum, checkInput());
        }
        else if (input == "2") {
            if (warehouse.getCountOfSections()) {
                std::cout << "Input number of section after which: ";
                cellNum = checkInput();
            }
            std::cout << "Input number of new section: ";
            warehouse.addSectionAfter(cellNum, checkInput());
        }
        else if (input == "3") {
            std::cout << "Input number of section: ";
            warehouse.popSection(checkInput());
        }
        else if (input == "4") std::cout << "In warehouse " << warehouse.getCountOfSections() << " sections" << std::endl;
        else if (input == "5") warehouse.printWarehousesData(std::cout);
        else if (input == "6") {
            std::cout << "Input number of section: ";
            if ((sec = warehouse.findSection(checkInput()))) sec->printCells(std::cout);
            else std::cout << RED << "No such section in warehouse" << DEFAULT << std::endl;
        }
        else if (input == "7") warehouse.printWarehousesData(outFile);
        else if (input == "r") warehouse.printWarehousesDataReverse(std::cout);
        else if (input == "8" || input == "9" || input == "10" || input == "11" ||
                 input == "12" || input == "13" || input == "14" || input == "15") {
            menuForSpecificSection(warehouse, input, outFile);
        }
        else if (input == "0") {
            std::cout << GREEN << "See you soon!" << DEFAULT << std::endl;
            exit(0);
        }
        else std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
    }
}