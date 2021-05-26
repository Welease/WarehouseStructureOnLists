#include <iostream>
#include "Warehouse.h"

int main() {
    std::string input;
    std::string tmp;
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
        if (inptut == "1") {

        }

        else if (input == "0") {
            std::cout << GREEN << "See you soon!" << DEFAULT << std::endl;
            exit(0);
        }
        else {
            std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
        }
    }
}
