//
// Created by Wynn Elease on 5/24/21.
//

#ifndef KURSACH_CELL_H
#define KURSACH_CELL_H
#include <iostream>

class Cell {
private:
    int     _number;
    bool    _isBusy;
public:
    Cell();
    Cell(int number, bool isBusy);

    void changeBusyness();
    int getNumber() const;
    bool isBusy() const;

    bool operator==(const Cell& cell);
    friend std::ostream& operator<< (std::ostream &out, const Cell &cell);
};

std::ostream& operator<< (std::ostream &out, const Cell &cell);

#endif //KURSACH_CELL_H
