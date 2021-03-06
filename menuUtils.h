//
// Created by Wynn Elease on 6/1/21.
//

#ifndef WAREHOUSESTRUCTUREONLISTS_MENUUTILS_H
#define WAREHOUSESTRUCTUREONLISTS_MENUUTILS_H

#include <iostream>
#include "Colors.h"
#include "Warehouse.h"

int checkInput();
void menuForSpecificSection(Warehouse & warehouse, std::string & input, std::ostream & of);
void printWelcomeMessage();
void menuForWarehouse(Warehouse & warehouse, std::ostream & outFile);

#endif //WAREHOUSESTRUCTUREONLISTS_MENUUTILS_H
