#include <exception>
#include <string>
#include "Residential.h"

using std::exception;
using std::string;

class invalidCoordinates : public exception
{
private:
    string message;

public:
    invalidCoordinates()
    {
        this->message = "The coordinates are outside the matrix!";
    }

    const char *what()
    {
        return this->message.c_str();
    }
};

class City
{
private:
    Cell **matrix;
    unsigned int rows;
    unsigned int cols;
    int cityHappiness;

public:
    City(int rows, int cols);
    ~City();

    float getMaintenanceCost() const;
    int getRoadLength() const;
    int getResidentCapacity() const;
    float getRequiredPower() const;
    int getHappiness() const;
    void build(unsigned int x, unsigned int y, Cell *cell);
};