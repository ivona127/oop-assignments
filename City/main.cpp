#include <iostream>
#include "City.h"
// В различните cpp файлове се инклудват различни от необходимото хедър файлове, за да не се получава предефиниране на enum-а в Cell

using std::cout;
using std::endl;

int main()
{
    try
    {
        City city(6, 8);
        Road r1;
        Road r2;
        Road r3;
        Road r4;
        Road r5;

        city.build(1, 3, &r1);
        city.build(2, 2, &r2);
        city.build(2, 3, &r3);
        city.build(2, 4, &r4);
        city.build(3, 3, &r5);

        Industrial li1(CellType::LightIndustrial);
        Industrial li2(CellType::LightIndustrial);
        Industrial di1(CellType::DenseIndustrial);
        Industrial di2(CellType::DenseIndustrial);

        city.build(0, 4, &li1);
        city.build(3, 1, &li2);
        city.build(1, 5, &di1);
        city.build(4, 3, &di2);

        Leisure mall(CellType::Mall);
        Leisure park(CellType::Park);

        city.build(2, 1, &mall);
        city.build(3, 5, &park);

        Residential lr1(CellType::LightResidential);
        Residential lr2(CellType::LightResidential);
        Residential mr1(CellType::MediumResidential);
        Residential mr2(CellType::MediumResidential);
        Residential dr1(CellType::DenseResidential);

        city.build(1, 2, &lr1);
        city.build(2, 5, &lr2);
        city.build(1, 4, &mr1);
        city.build(3, 2, &mr2);
        city.build(3, 4, &dr1);

        int MaintenanceCostcity = city.getMaintenanceCost();  // raboti  - 55   
        cout << "MaintenanceCost - " << MaintenanceCostcity << endl;

        int RequiredPower = city.getRequiredPower();  // raboti - 55   
        cout << "RequiredPower - " << RequiredPower << endl;

        int RoadLength = city.getRoadLength(); // raboti - 5
        cout << "RoadLength - " << RoadLength << endl;

        int Happiness = city.getHappiness(); // ne raboti = - 4
        cout << "Happiness - " << Happiness << endl;

        int ResidentCapacity = city.getResidentCapacity(); // raboti - 100   
        cout << "ResidentCapacity - " << ResidentCapacity << endl;
    }
    catch (invalidCoordinates &ex)
    {
        cout << "Exception caught: " << ex.what() << endl;
    }
    return 0;
}