#include "Residential.h"

Residential::Residential(CellType type)
{
    switch (type)
    {
    case CellType::LightResidential:
        this->maintenanceCost = 2;
        this->electricity = 2;
        this->cell = CellType::LightResidential;
        this->inhabitants = 5;
        break;

    case CellType::MediumResidential:
        this->maintenanceCost = 4;
        this->electricity = 4;
        this->cell = CellType::MediumResidential;
        this->inhabitants = 20;
        break;

    case CellType::DenseResidential:
        this->maintenanceCost = 6;
        this->electricity = 8;
        this->cell = CellType::DenseResidential;
        this->inhabitants = 50;
        break;
    
    default:
        break;
    }
}

int Residential::getResidentCapacity() const
{
    return this->inhabitants;
}
