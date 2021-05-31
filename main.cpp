#include <iostream>
#include "Warehouse.h"

int main() {
    std::string input;
    std::string tmp, temp;
    std::cout << BLUE << "Input name of Warehouse: " << DEFAULT; std::cin >> input;
    Warehouse warehouse(input);
    while (1) {
        std::cout << BLUE << "Choose option:\n" <<
                             "1 - Add section back\n" <<
                             "2 - Add section front\n" <<
                             "3 - Add section before input section\n" <<
                             "4 - Add section after input section\n" <<
                             "5 - Delete section back\n" <<
                             "6 - Delete section front\n" <<
                             "7 - Delete section before input section\n" <<
                             "8 - Delete section after input section\n" <<
                             "9 - Delete input section\n" <<
                             "10 - Get count of sections in warehouse\n" <<
                             "d - Print warehouses data\n" <<
                             "11 - Find input section\n\n" <<

                             "Work with specific section:\n"
                             "12 - Add cell back to input section\n" <<
                             "13 - Add cell front to input section\n" <<
                             "14 - Add cell after input to specific section\n" <<
                             "15 - Add cell before input to specific section\n" <<
                             "16 - Delete cell from specific section\n" <<
                             "17 - Delete cell back from specific section\n" <<
                             "18 - Delete cell front from specific section\n" <<
                             "19 - Delete cell before input cell from specific section\n" <<
                             "20 - Delete cell after input cell from specific section\n" <<
                             "21 - Print cells from specific section\n" <<
                             "0 - exist\n====>" << DEFAULT << std::endl;
        std::cin >> input;
        if (input == "1") {
            std::cout << "Input number of new section: "; std::cin >> input;
            warehouse.addSectionBack(std::stoi(input));
        }
        else if (input == "2") {
            std::cout << "Input number of new section: "; std::cin >> input;
            warehouse.addSectionFront(std::stoi(input));
        }
        else if (input == "3") {
            std::cout << "Input number of new section: "; std::cin >> input;
            std::cout << "Input number of section before which: "; std::cin >> tmp;
            warehouse.addSectionBefore(std::stoi(tmp), std::stoi(input));
        }
        else if (input == "4") {
            std::cout << "Input number of new section: "; std::cin >> input;
            std::cout << "Input number of section after which: "; std::cin >> tmp;
            warehouse.addSectionAfter(std::stoi(tmp), std::stoi(input));
        }
        else if (input == "5") warehouse.popSectionBack();
        else if (input == "6") warehouse.popSectionFront();
        else if (input == "7") {
            std::cout << "Input number of section before which: "; std::cin >> tmp;
            warehouse.popSectionBefore(std::stoi(tmp));
        }
        else if (input == "8") {
            std::cout << "Input number of section after which: "; std::cin >> tmp;
            warehouse.popSectionAfter(std::stoi(tmp));
        }
        else if (input == "9") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            warehouse.popSection(std::stoi(tmp));
        }
        else if (input == "10") std::cout << "In warehouse " << warehouse.getCountOfSections() << " sections" << std::endl;
        else if (input == "d") warehouse.printWarehousesData();
        else if (input == "11") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            warehouse.findSection(std::stoi(tmp)).printCells();
        }
        else if (input == "12") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            std::cout << "Input number of cell: "; std::cin >> input;
            warehouse.addCellToSectionBack(std::stoi(tmp), std::stoi(input));
        }
        else if (input == "13") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            std::cout << "Input number of cell: "; std::cin >> input;
            warehouse.addCellToSectionFront(std::stoi(tmp), std::stoi(input));
        }
        else if (input == "14") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            std::cout << "Input number of new cell: "; std::cin >> input;
            std::cout << "Input number of cell after which: "; std::cin >> temp;
            warehouse.addCellToSectionAfter(std::stoi(tmp), std::stoi(temp), std::stoi(input));
        }
        else if (input == "15") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            std::cout << "Input number of new cell: "; std::cin >> input;
            std::cout << "Input number of cell before which: "; std::cin >> temp;
            warehouse.addCellToSectionBefore(std::stoi(tmp), std::stoi(temp), std::stoi(input));
        }
        else if (input == "16") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            std::cout << "Input number of cell: "; std::cin >> input;
            warehouse.popFromSection(std::stoi(tmp), std::stoi(input));
        }
        else if (input == "17") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            warehouse.popFromSectionBack(std::stoi(tmp));
        }
        else if (input == "18") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            warehouse.popFromSectionFront(std::stoi(tmp));
        }
        else if (input == "19") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            warehouse.popFromSectionFront(std::stoi(tmp));
        }
        else if (input == "20") {
            std::cout << "Input number of section: "; std::cin >> tmp;
            warehouse.popFromSectionFront(std::stoi(tmp));
        }
        else if (input == "21") {
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
