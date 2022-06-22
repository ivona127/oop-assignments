#include "Road.h"

class Leisure : public Cell
{
private:
    int happiness;
public:
    Leisure(CellType leisure);
    Leisure(int happiness);

    int getHappiness() const;
};