#include "Leisure.h"

Leisure::Leisure(CellType leisure)
{
    switch (leisure)
    {
    case CellType::Mall:
        this->maintenanceCost = 8;
        this->electricity = 4;
        this->cell = CellType::Mall;
        this->happiness = 0;
        break;

    case CellType::Park:
        this->maintenanceCost = 4;
        this->electricity = 2;
        this->cell = CellType::Park;
        this->happiness = 0;
        break;

    default:
        break;
    }
}

Leisure::Leisure(int happiness)
{
    this->happiness = happiness;
}

int Leisure::getHappiness() const
{
    return this->happiness;
}