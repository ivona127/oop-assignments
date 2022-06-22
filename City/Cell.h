enum class CellType
{
    Empty,
    Road,
    LightResidential,
    MediumResidential,
    DenseResidential,
    Mall,
    Park,
    LightIndustrial,
    DenseIndustrial
};

class Cell
{
protected:
    bool counted;
    float maintenanceCost;
    float electricity;
    CellType cell;

public:
    Cell();
    Cell(Cell *cell);
    Cell(Cell *cell, bool counted);

    float getMaintenanceCost() const;
    float getElectricity() const;
    bool getIsCounted() const;
    CellType getType() const;
};