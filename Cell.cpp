//
// Created by Wynn Elease on 5/24/21.
//

#include "Cell.h"

Cell::Cell(int number, bool isBusy) : _number(number), _isBusy(isBusy) {};

Cell::Cell() : _number(0), _isBusy(false){}

void Cell::changeBusyness() { _isBusy = !_isBusy; }

int Cell::getNumber() const { return _number; }

bool Cell::isBusy() const { return _isBusy; }

bool Cell::operator==(const Cell &cell) { return _number == cell.getNumber(); }

std::ostream& operator<< (std::ostream &out, const Cell &cell){
    out << "Cell № " << cell.getNumber() << " (";
    if (cell.isBusy())
        out << "busy";
    else
        out << "not busy";
    out << ")" << std::endl;
return out;
}