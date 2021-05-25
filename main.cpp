#include <iostream>
#include "StaticList.h"


int main() {
    StaticList<int> list;
    std::string input;
    std::string tmp;
    while (1) {
        std::cout << BLUE << "Choose option:\n" <<
                             "1 - push element back\n" <<
                             "2 - push element front\n" <<
                             "3 - push element before...\n" <<
                             "4 - push element after...\n" <<
                             "5 - pop element back\n" <<
                             "6 - pop element front\n" <<
                             "7 - pop element\n" <<
                             "8 - pop element before\n" <<
                             "9 - pop element after\n" <<
                             "10 - print all list's data\n" <<
                             "11 - check empty list or not\n" <<
                             "12 - check full list or not\n" <<
                             "13 - get index of element\n" <<
                             "0 - exist\n====>" << DEFAULT << std::endl;
        std::cin >> input;
        if (input == "1") {
            std::cout << "Input data: ";
            std::cin >> input;
            list.pushBack(std::stoi(input));
        }
        else if (input == "2") {
            std::cout << "Input data: ";
            std::cin >> input;
            list.pushFront(std::stoi(input));
        }
        else if (input == "3") {
            std::cout << "Input data: ";
            std::cin >> input;
            std::cout << "Input element: ";
            std::cin >> tmp;
            list.pushBefore(std::stoi(tmp), std::stoi(input));
        }
        else if (input == "4") {
            std::cout << "Input data: ";
            std::cin >> input;
            std::cout << "Input element: ";
            std::cin >> tmp;
            list.pushAfter(std::stoi(tmp), std::stoi(input));
        }
        else if (input == "5")
            list.popBack();
        else if (input == "6")
            list.popFront();
        else if (input == "7") {
            std::cout << "Input element: ";
            std::cin >> input;
            list.popElement(std::stoi(input));
        }
        else if (input == "8") {
            std::cout << "Input element: ";
            std::cin >> tmp;
            list.popBefore(std::stoi(tmp));
        }
        else if (input == "9") {
            std::cout << "Input element: ";
            std::cin >> tmp;
            list.popAfter(std::stoi(tmp));
        }
        else if (input == "10")
            list.printListsData();
        else if (input == "11")
            std::cout << "List is empty? " << list.isEmpty() << std::endl;
        else if (input == "12")
            std::cout << "List is full? " << list.isFull() << std::endl;
        else if (input == "13") {
            std::cout << "Input element: ";
            std::cin >> tmp;
            list.findElement(std::stoi(tmp));
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
