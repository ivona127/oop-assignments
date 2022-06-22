#include "Industrial.h"

Industrial::Industrial(CellType industrial)
{
    switch (industrial)
    {
    case CellType::LightIndustrial:
        this->maintenanceCost = 4;
        this->electricity = 4;
        this->happiness = 0;
        this->cell = CellType::LightIndustrial;
        break;

    case CellType::DenseIndustrial:
        this->maintenanceCost = 6;
        this->electricity = 8;
        this->happiness = 0;
        this->cell = CellType::DenseIndustrial;
        break;
        
    default:
        break;
    }
}

int Industrial::getHappiness() const 
{
    return this->happiness;
}