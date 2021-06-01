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
        std::cout << BLUE << "Input name of Warehouse: " << DEFAULT;
        std::cin >> input;
        Warehouse warehouse(input);
        warehouse.parseFilesData(fileIn);
        menuForWarehouse(warehouse, fileOut);
    } else std::cout << RED << "usage: ./kursach <input_file_with_info> <output_file>" << DEFAULT << std::endl;
}
