//
// Created by Wynn Elease on 5/24/21.
//

#ifndef KURSACH_STATICLIST_H
#define KURSACH_STATICLIST_H


#include <iostream>
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

    bool isEmpty() { return _countOfElements == 0; }

    bool isFull() { return _countOfElements == SIZE; }

    int size() { return _countOfElements; }

    void pushBack(T data) {
        if (isFull(list)) {
            std::cout << RED << "List is full" << DEFAULT << std::endl;
            return;
        }
        else {
            list->list[list->size] = data;
            list->size++;
        }
    }

    void pushFront(T data) {
        if (isFull()) {
            std::cout << RED << "List is full" << DEFAULT << std::endl;
            return;
        }
        if (isEmpty())
            list[_countOfElements++] = data;
        else {
            for (int i = _countOfElements; i > 0; i--)
                list->list[i] = list->list[i - 1];
            list->list[0] = data;
            _countOfElements++;
        }
    }

    void pushBefore(T beforeWhich, T data) {
        if (isFull()) {
            std::cout << RED << "List is full" << DEFAULT << std::endl;
            return;
        }
        int i = findElement(list, beforeWhich);
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
        int i = findElement(list, afterWhich);
        if (i++ == -1) {
            std::cout << RED << "Element not found :(" << DEFAULT << std::endl;
            return;
        }
        for (int j = _countOfElements; j >= i; j--) {
            list[j] = list[j - 1];
        }
        list[i] = data;
        _countOfElements++;
    }

    void	printListsData() {
        std::cout << GREEN << "Printing list's data..." << DEFAULT << std::endl;
        std::cout << BLUE << "List size: " << _countOfElements << DEFAULT << std::endl;

        for (int i = 0; i < _countOfElements; i++)
            std::cout << list[i] << ' ';
        std::cout << std::endl;
    }

    void popBack() {
        if (isEmpty()) {
            std::cout << RED << "List is empty" << DEFAULT << std::endl;
            return;
        }
        _countOfElements--;
    }

    void popFront() {
        if (isEmpty()) {
            std::cout << RED << "List is empty" << DEFAULT << std::endl;
            return;
        }
        for (int j = 0; j < _countOfElements; j++)
            list[j] = list[j + 1];
        _countOfElements--;
    }

    void popElement(T elem) {
        if (isEmpty()) {
            std::cout << RED << "List is empty" << DEFAULT << std::endl;
            return;
        }
        int i = findElement(elem);
        if (i == -1) {
            std::cout << RED << "Element not found :(" << DEFAULT << std::endl;
            return;
        }
        for (; i < _countOfElements; i++)
            list[i] = list[i + 1];
        _countOfElements--;
    }

    void popBefore(T beforeWhich) {
        if (isEmpty()) {
            std::cout << RED << "List is empty" << DEFAULT << std::endl;
            return;
        }
        int i = findElement(beforeWhich);
        if (i == -1) {
            std::cout << RED << "Element not found :(" << DEFAULT << std::endl;
            return;
        }
        if (i-- == 0) {
            std::cout << RED << "Can't push before head :(" << DEFAULT << std::endl;
            return;
        }
        for (; i < _countOfElements; i++)
            list[i] = list[i + 1];
        _countOfElements--;
    }

    void popAfter(T afterWhich) {
        if (isEmpty()) {
            std::cout << RED << "List is empty" << DEFAULT << std::endl;
            return;
        }
        int i = findElement(afterWhich);
        if (i == -1) {
            std::cout << RED << "Element not found :(" << DEFAULT << std::endl;
            return;
        }
        for (; i < _countOfElements; i++)
            list[i] = list[i + 1];
        _countOfElements--;
    }

    int findElement(T toFind) {
        int i = 0;
        while (i < _countOfElements) {
            if (list[i] == toFind)
                return (i);
            i++;
        }
        return (-1);
    }
};

#endif //KURSACH_STATICLIST_H
