#include "Industrial.h"

class Residential : public Cell
{
protected:
    int inhabitants;

public:
    Residential(CellType type);
    
    int getResidentCapacity() const;
};
