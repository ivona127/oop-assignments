
#include "City.h"
#include <iostream>

using namespace std;

City::City(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->cityHappiness = 0;

    matrix = new Cell *[rows];

    for (int row = 0; row < rows; row++)
    {
        matrix[row] = new Cell[cols];

        for (int col = 0; col < cols; col++)
        {
            matrix[row][col] = Cell();
        }
    }
}

City::~City()
{
    for (unsigned int row = 0; row < rows; row++)
    {
        delete[] matrix[row];
    }
    delete[] matrix;
}

float City::getMaintenanceCost() const
{
    int sum = 0;

    for (unsigned int row = 0; row < rows; row++)
    {
        for (unsigned int col = 0; col < cols; col++)
        {
            sum += matrix[row][col].getMaintenanceCost();
        }
    }

    return sum;
}

int City::getRoadLength() const
{
    int sum = 0;

    for (unsigned int row = 0; row < rows; row++)
    {
        for (unsigned int col = 0; col < cols; col++)
        {

            if (matrix[row][col].getType() == CellType::Road)
            {
                sum++;
            }
        }
    }

    return sum;
}

int City::getResidentCapacity() const
{
    int sum = 0;

    for (unsigned int row = 0; row < rows; row++)
    {
        for (unsigned int col = 0; col < cols; col++)
        {
            if (matrix[row][col].getType() == CellType::LightResidential ||
                matrix[row][col].getType() == CellType::MediumResidential ||
                matrix[row][col].getType() == CellType::DenseResidential)
            {

                Residential r(matrix[row][col].getType());
                sum += r.getResidentCapacity();
            }
        }
    }

    return sum;
}

float City::getRequiredPower() const
{
    int sum = 0;

    for (unsigned int row = 0; row < rows; row++)
    {
        for (unsigned int col = 0; col < cols; col++)
        {
            sum += matrix[row][col].getElectricity();
        }
    }
    return sum;
}

int City::getHappiness() const
{
    return this->cityHappiness;
}

void City::build(unsigned int x, unsigned int y, Cell *cell)
{

    if ((x < rows && x >= 0) && (y < cols && y >= 0) && matrix[x][y].getType() == CellType::Empty)
    {
        CellType type = cell->getType();
        int count;
        int road;
        int leisure;
        int inside;

        switch (type)
        {
        case CellType::Road:
            matrix[x][y] = Cell(cell);
            break;

        case CellType::LightResidential:
            inside = 0;

            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    if ((x + row < rows && x + row >= 0) && (y + col < cols && y + col >= 0))
                    {
                        if ((matrix[x + row][y + col].getType() == CellType::Park || matrix[x + row][y + col].getType() == CellType::Mall) && (matrix[x + row][y + col].getIsCounted() == false))
                        {
                            this->cityHappiness += 1;
                            matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                        }

                        if (matrix[x + row][y + col].getType() == CellType::LightIndustrial && (matrix[x + row][y + col].getIsCounted() == false))
                        {
                            this->cityHappiness -= 1;
                            matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                        }

                        if (matrix[x + row][y + col].getType() == CellType::DenseIndustrial && (matrix[x + row][y + col].getIsCounted() == false))
                        {
                            this->cityHappiness -= 2;
                            matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                        }

                        if ((matrix[x + row][y + col].getType() == CellType::Road) && inside != 1)
                        {
                            matrix[x][y] = Cell(cell);
                        }
                    }
                }
            }
            break;

        case CellType::MediumResidential:
            inside = 0;

            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    if ((x + row < rows && x + row >= 0) && (y + col < cols && y + col >= 0))
                    {
                        if ((matrix[x + row][y + col].getType() == CellType::Park) && (matrix[x + row][y + col].getIsCounted() == false))
                        {
                            this->cityHappiness += 2;
                            matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                        }

                        if ((matrix[x + row][y + col].getType() == CellType::Mall && (matrix[x + row][y + col].getIsCounted() == false)))
                        {
                            this->cityHappiness += 1;
                            matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                        }

                        if ((matrix[x + row][y + col].getType() == CellType::LightIndustrial) && (matrix[x + row][y + col].getIsCounted() == false))
                        {
                            this->cityHappiness -= 1;
                            matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                        }

                        if ((matrix[x + row][y + col].getType() == CellType::DenseIndustrial) && (matrix[x + row][y + col].getIsCounted() == false))
                        {
                            this->cityHappiness -= 2;
                            matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                        }

                        if ((matrix[x + row][y + col].getType() == CellType::Road) && inside != 1)
                        {
                            matrix[x][y] = Cell(cell);
                            inside = 1;
                        }
                    }
                }
            }
            break;

        case CellType::DenseResidential:
            road = 0;
            leisure = 0;

            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {

                    if ((x + row < rows && x + row >= 0) && (y + col < cols && y + col >= 0) && (matrix[x + row][y + col].getType() == CellType::Road))
                    {
                        road = 1;
                    }

                    if ((x + row < rows && x + row >= 0) && (y + col < cols && y + col >= 0) && ((matrix[x + row][y + col].getType() == CellType::Mall)))
                    {
                        if ((matrix[x + row][y + col].getIsCounted() == false)){
                            this->cityHappiness += 1;
                            matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                        }

                        leisure++;
                    }

                    if ((x + row < rows && x + row >= 0) && (y + col < cols && y + col >= 0) && (matrix[x + row][y + col].getType() == CellType::Park))
                    {
                        if ((matrix[x + row][y + col].getIsCounted() == false))
                        {
                            this->cityHappiness += 3;
                            matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                        }
                        leisure++;
                    }
                }
            }

            if (leisure > 0 && road > 0)
            {
                matrix[x][y] = Cell(cell);
            }
            break;

        case CellType::Mall:
            count = 0;

            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    if ((x + row < rows && x + row >= 0) && (y + col < cols && y + col >= 0))
                    {
                        if (((matrix[x + row][y + col].getType() == CellType::LightResidential) || (matrix[x + row][y + col].getType() == CellType::MediumResidential) || (matrix[x + row][y + col].getType() == CellType::DenseResidential)) && (matrix[x + row][y + col].getIsCounted() == false))
                        {
                            matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                            count++;
                        }
                    }
                }
            }

            matrix[x][y] = Cell(cell);
            this->cityHappiness += count;
            break;

        case CellType::Park:
            count = 0;

            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    CellType type = matrix[x + row][y + col].getType();

                    if ((x + row < rows && x + row >= 0) && (y + col < cols && y + col >= 0) && ((type == CellType::LightResidential) || (type == CellType::MediumResidential) || (type == CellType::DenseResidential)) && (matrix[x + row][y + col].getIsCounted() == false))
                    {
                        switch (type)
                        {
                        case CellType::LightResidential:
                            count += 1;
                            matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                            break;
                        case CellType::MediumResidential:
                            count += 2;
                            matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                            break;
                        case CellType::DenseResidential:
                            count += 3;
                            matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                            break;
                        default:
                            break;
                        }
                    }
                }
            }

            matrix[x][y] = Cell(cell);
            this->cityHappiness += count;
            break;

        case CellType::LightIndustrial:
            count = 0;

            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    if ((x + row < rows && x + row >= 0) && (y + col < cols && y + col >= 0))
                    {
                        CellType type = matrix[x + row][y + col].getType();
                        if (((type == CellType::LightResidential) || (type == CellType::MediumResidential) || (type == CellType::DenseResidential)) && (matrix[x + row][y + col].getIsCounted() == false))
                        {
                            count -= 1;
                            matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                        }
                    }
                }
            }

            matrix[x][y] = Cell(cell);
            this->cityHappiness += count;
            break;

        case CellType::DenseIndustrial:
            count = 0;

            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    CellType type = matrix[x + row][y + col].getType();
                    if ((x + row < rows && x + row >= 0) && (y + col < cols && y + col >= 0) && ((type == CellType::LightResidential) || (type == CellType::MediumResidential) || (type == CellType::DenseResidential) || (type == CellType::Mall) || (type == CellType::Park)) && (matrix[x + row][y + col].getIsCounted() == false))
                    {
                        count -= 2;
                        matrix[x + row][y + col] = Cell(&matrix[x + row][y + col], true);
                    }
                }
            }
            matrix[x][y] = Cell(cell);
            this->cityHappiness += count;
            break;

        default:
            break;
        }
    }
    else
    {
        throw invalidCoordinates();
    }
}
