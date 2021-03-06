//
// Created by Wynn Elease on 5/24/21.
//

#ifndef KURSACH_STATICLIST_H
#define KURSACH_STATICLIST_H


#include <iostream>
#include <fstream>

#define SIZE 10
#include "Colors.h"

template<typename T>
class StaticList {
private:
    T list[SIZE];
    int _countOfElements;

public:
    StaticList() {
        _countOfElements = 0;
    }

    ~StaticList() = default;

    bool isEmpty() { return _countOfElements == 0; }

    bool isFull() { return _countOfElements == SIZE; }

    int size() { return _countOfElements; }

    T *findElement(T toFind) {
       int ind = findElementsIndex(toFind);
       if (ind == -1) return nullptr;
       return &list[ind];
    }

    int findElementsIndex(T toFind) {
        int i = 0;
        while (i < _countOfElements) {
            if (list[i] == toFind)
                return (i);
            i++;
        }
        return (-1);
    }

    void pushBack(T data) {
        if (isFull()) {
            std::cout << RED << "List is full" << DEFAULT << std::endl;
            return;
        }
        else {
            list[_countOfElements] = data;
            _countOfElements++;
        }
    }

    void pushBefore(T beforeWhich, T data) {
        if (isFull()) {
            std::cout << RED << "List is full" << DEFAULT << std::endl;
            return;
        }
        if (!_countOfElements) {
            pushBack(data);
            return;
        }
        int i = findElementsIndex(beforeWhich);
        if (i == -1) {
            std::cout << RED << "Element not found :(" << DEFAULT << std::endl;
            return;
        }
        for (int j = _countOfElements; j >= i; j--) {
            list[j] = list[j - 1];
        }
        list[i] = data;
        _countOfElements++;
    }

    void pushAfter(T afterWhich, T data) {
        if (isFull()) {
            std::cout << RED << "List is full" << DEFAULT << std::endl;
            return;
        }
        int i = findElementsIndex(afterWhich);
        if (i++ == -1 && _countOfElements > 0) {
            std::cout << RED << "Element not found :(" << DEFAULT << std::endl;
            return;
        }
        for (int j = _countOfElements; j >= i; j--) {
            list[j] = list[j - 1];
        }
        list[i] = data;
        _countOfElements++;
    }

    void	printListsData(std::ostream & outFile) {
        for (int i = 0; i < _countOfElements; i++) {
            if (i > 0)
                outFile << "            ";
            outFile << "           " << list[i] << std::endl;
        }
    }

    void printReverseListsData(std::ostream & outFile) {
        for (int i = _countOfElements - 1; i >= 0; --i) {
            if (i < _countOfElements - 1)
                outFile << "            ";
            outFile << "           " << list[i] << std::endl;
        }
    }

    void popElement(T elem) {
        if (isEmpty()) {
            std::cout << RED << "List is empty" << DEFAULT << std::endl;
            return;
        }
        int i = findElementsIndex(elem);
        if (i == -1) {
            std::cout << RED << "Element not found :(" << DEFAULT << std::endl;
            return;
        }
        for (; i < _countOfElements; i++)
            list[i] = list[i + 1];
        _countOfElements--;
    }
};

#endif //KURSACH_STATICLIST_H
