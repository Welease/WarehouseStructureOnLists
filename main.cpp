#include <iostream>
#include "Warehouse.h"

int checkInput() {
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << RED << "Incorrect input, please try again: " << DEFAULT;
    }
    return a;
}

void menuForSpecificSection(Warehouse & warehouse, std::string & input) {
    int secNum, tmp = 0, cellNum;
    Cell *cell;
    if (warehouse.getCountOfSections()) {
        std::cout << "Input number of section: ";
        secNum = checkInput();
        if (warehouse.findSection(secNum)) {
            if (input == "9") {
                if (warehouse.findSection(secNum)->getCountOfCells()) {
                    std::cout << "Input number of cell after which: ";
                    tmp = checkInput();
                }
                std::cout << "Input number of new cell: ";
                warehouse.addCellToSectionAfter(secNum, tmp, checkInput());
            } else if (input == "10") {
                if (warehouse.findSection(secNum)->getCountOfCells()) {
                    std::cout << "Input number of cell before which: ";
                    tmp = checkInput();
                }
                std::cout << "Input number of new cell: ";
                warehouse.addCellToSectionBefore(secNum, tmp, checkInput());
            } else if (input == "11") {
                std::cout << "Input number of cell: ";
                warehouse.popFromSection(secNum, checkInput());
            } else if (input == "12") {
                std::cout << "Input number of cell before which: ";
                warehouse.popFromSectionBefore(secNum, checkInput());
            } else if (input == "13") {
                std::cout << "Input number of cell after which: ";
                warehouse.popFromSectionAfter(secNum, checkInput());
            } else if (input == "14") warehouse.printSectionsData(secNum);
            else if (input == "15")
                std::cout << "In section " << secNum << ": " << warehouse.getCountOfCellsInSection(secNum) << " cells" << std::endl;
            else if (input == "16") {
                std::cout << "Input number of cell: ";
                cellNum = checkInput();
                if (!(cell = warehouse.findCellInSection(secNum, cellNum)))
                    std::cout << RED << "No such cell in this section" << DEFAULT << std::endl;
                else std::cout << *cell << std::endl;
            }
            else if (input == "17") {
                std::cout << "Input number of cell: ";
                warehouse.changeBusy(secNum, checkInput());
            }
        } else std::cout << RED << "No such section in warehouse" << DEFAULT << std::endl;
    } else std::cout << RED << "Warehouse is empty" << DEFAULT << std::endl;
}

void printWelcomeMessage() {
    std::cout << BLUE << "Choose option:\n" <<
              "1 - Add section before input section\n" <<
              "2 - Add section after input section\n" <<
              "3 - Delete section before input section\n" <<
              "4 - Delete section after input section\n" <<
              "5 - Delete input section\n" <<
              "6 - Get count of sections in warehouse\n" <<
              "7 - Print warehouses data\n" <<
              "8 - Find input section\n\n" <<

              "Work with specific section:\n"
              "9 - Add cell after input to specific section\n" <<
              "10 - Add cell before input to specific section\n" <<
              "11 - Delete cell from specific section\n" <<
              "12 - Delete cell before input cell from specific section\n" <<
              "13 - Delete cell after input cell from specific section\n" <<
              "14 - Print cells from specific section\n" <<
              "15 - Get count of cells in specific section\n" <<
              "16 - Find input cell in specific section\n" <<
              "17 - Change cell occupancy\n" <<
              "0 - exist\n====>" << DEFAULT << std::endl;
}


int main() {
    std::string input;
    int cellNum;
    Section * sec;
    std::cout << BLUE << "Input name of Warehouse: " << DEFAULT; std::cin >> input;
    Warehouse warehouse(input);
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
            std::cout << "Input number of section before which: ";
            warehouse.popSectionBefore(checkInput());
        }
        else if (input == "4") {
            std::cout << "Input number of section after which: ";
            warehouse.popSectionAfter(checkInput());
        }
        else if (input == "5") {
            std::cout << "Input number of section: ";
            warehouse.popSection(checkInput());
        }
        else if (input == "6") std::cout << "In warehouse " << warehouse.getCountOfSections() << " sections" << std::endl;
        else if (input == "7") warehouse.printWarehousesData();
        else if (input == "8") {
            std::cout << "Input number of section: ";
            if ((sec = warehouse.findSection(checkInput()))) sec->printCells();
            else std::cout << RED << "No such section in warehouse" << DEFAULT << std::endl;
        }
        else if (input == "9" || input == "10" || input == "11" || input == "12" ||
                input == "13" || input == "14" || input == "15" || input == "16" || input == "17") {
            menuForSpecificSection(warehouse, input);
        }
        else if (input == "0") {
            std::cout << GREEN << "See you soon!" << DEFAULT << std::endl;
            exit(0);
        }
        else std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
    }
}
