#include <iostream>
#include "Warehouse.h"

int main() {
    std::string input;
    std::string tmp, temp;
    std::cout << BLUE << "Input name of Warehouse: " << DEFAULT; std::cin >> input;
    Warehouse warehouse(input);
    while (1) {
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
                             "0 - exist\n====>" << DEFAULT << std::endl;
        std::cin >> input;
        if (input == "1") {
            std::cout << "Input number of new section: "; std::cin >> input; tmp = "1";
            if (warehouse.getCountOfSections() != 0) {
                std::cout << "Input number of section before which: ";
                std::cin >> tmp;
            }
            warehouse.addSectionBefore(std::stoi(tmp), std::stoi(input));
        }
        else if (input == "2") {
            std::cout << "Input number of new section: "; std::cin >> input;
            std::cout << "Input number of section after which: "; std::cin >> tmp;
            warehouse.addSectionAfter(std::stoi(tmp), std::stoi(input));
        }
        else if (input == "3") {
            std::cout << "Input number of section before which: "; std::cin >> tmp;
            warehouse.popSectionBefore(std::stoi(tmp));
        }
        else if (input == "4") {
            std::cout << "Input number of section after which: "; std::cin >> tmp;
            warehouse.popSectionAfter(std::stoi(tmp));
        }
        else if (input == "5") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            warehouse.popSection(std::stoi(tmp));
        }
        else if (input == "6") std::cout << "In warehouse " << warehouse.getCountOfSections() << " sections" << std::endl;
        else if (input == "7") warehouse.printWarehousesData();
        else if (input == "8") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            warehouse.findSection(std::stoi(tmp)).printCells();
        }
        else if (input == "9") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            std::cout << "Input number of new cell: "; std::cin >> input;
            std::cout << "Input number of cell after which: "; std::cin >> temp;
            warehouse.addCellToSectionAfter(std::stoi(tmp), std::stoi(temp), std::stoi(input));
        }
        else if (input == "10") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            std::cout << "Input number of new cell: "; std::cin >> input;
            std::cout << "Input number of cell before which: "; std::cin >> temp;
            warehouse.addCellToSectionBefore(std::stoi(tmp), std::stoi(temp), std::stoi(input));
        }
        else if (input == "11") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            std::cout << "Input number of cell: "; std::cin >> input;
            warehouse.popFromSection(std::stoi(tmp), std::stoi(input));
        }
        else if (input == "12") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            std::cout << "Input number of cell before which: "; std::cin >> temp;
            warehouse.popFromSectionBefore(std::stoi(tmp), std::stoi(temp));
        }
        else if (input == "13") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            std::cout << "Input number of cell after which: "; std::cin >> temp;
            warehouse.popFromSectionAfter(std::stoi(tmp), std::stoi(temp));
        }
        else if (input == "14") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            warehouse.printSectionsData(std::stoi(tmp));
        }
        else if (input == "0") {
            std::cout << GREEN << "See you soon!" << DEFAULT << std::endl;
            exit(0);
        }
        else std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
    }
}
