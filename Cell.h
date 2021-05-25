//
// Created by Wynn Elease on 5/24/21.
//

#ifndef KURSACH_CELL_H
#define KURSACH_CELL_H


class Cell {
private:
    int     _number;
    bool    _isBusy;
public:
    Cell(int number, bool isBusy) : _number(number), _isBusy(isBusy) {}

    void changeBusyness() { _isBusy = !_isBusy; }

    int getNumber() const { return _number; }

    bool isBusy() const { return _isBusy; }
};


#endif //KURSACH_CELL_H
