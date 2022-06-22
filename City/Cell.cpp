#include "Cell.h"

Cell::Cell()
{
    this->maintenanceCost = 0;
    this->electricity = 0;
    this->counted = false;
    this->cell = CellType::Empty;
}

Cell::Cell(Cell *cell)
{
    this->electricity = cell->electricity;
    this->maintenanceCost = cell->maintenanceCost;
    this->counted = cell->counted;
    this->cell = cell->cell;
}

Cell::Cell(Cell *cell, bool counted)
{
    this->electricity = cell->electricity;
    this->maintenanceCost = cell->maintenanceCost;
    this->counted = counted;
    this->cell = cell->cell;
}

float Cell::getMaintenanceCost() const
{
    return this->maintenanceCost;
}

float Cell::getElectricity() const
{
    return this->electricity;
}

CellType Cell::getType() const
{
    return this->cell;
}

bool Cell::getIsCounted() const
{
    return this->counted;
}