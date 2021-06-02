#include <iostream>
#include "Warehouse.h"
#include "menuUtils.h"

std::ifstream fileIn;
std::ofstream  fileOut;


int main(int argc, char** argv) {
    if (argc == 3) {
        fileIn = std::ifstream (argv[1]);
        fileOut = std::ofstream(argv[2]);
        if (!fileIn.is_open() || !fileOut.is_open()) {
            std::cout << RED << "Incorrect files" << DEFAULT << std::endl;
            return 0;
        }
        std::string input;
        while (1) {
            std::cout << BLUE << "Read data from file? (y - yes) (n - no): " << DEFAULT;
            std::cin >> input;
            if (input == "n") {
                std::cout << BLUE << "Input name of Warehouse: " << DEFAULT;
                std::cin >> input;
                Warehouse warehouse(input);
                menuForWarehouse(warehouse, fileOut);
                break;
            } else if (input == "y") {
                Warehouse warehouse(input);
                warehouse.parseFilesData(fileIn);
                menuForWarehouse(warehouse, fileOut);
                break;
            } else continue;
        }
    } else std::cout << RED << "usage: ./kursach <input_file_with_info> <output_file>" << DEFAULT << std::endl;
}
