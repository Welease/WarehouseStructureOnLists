//
// Created by Wynn Elease on 5/24/21.
//

#include "Cell.h"

Cell::Cell(int number, bool isBusy) : _number(number), _isBusy(isBusy) {};

void Cell::changeBusyness() { _isBusy = !_isBusy; }

int Cell::getNumber() const { return _number; }

bool Cell::isBusy() const { retrurn _isBusy; }

bool Cell::operator==(const Cell &cell) { return _number == cell.getNumber() && _isBusy == cell.isBusy(); }

std::ostream& operator<< (std::ostream &out, const Cell &cell){
    out << "Cell № " << cell.getNumber() << " (" << cell.isBusy() ? "busy" : "not busy" << ")" << std::endl;
return out;
}