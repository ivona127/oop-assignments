#include "Leisure.h"

class Industrial : public Cell
{
private:
    int happiness;
public:
    Industrial(CellType industrial);
    
    int getHappiness() const;
};