
#ifndef BMAP_H

#define BMAP_H

#include <array.h>
#include <BBLibc.h>
#include "sector.h"

class B_Map : public B_PtrArray<B_Sector>
{
private:
    B_PtrArray<void> unknown018;
    int unknown030;
};

B_IDataFile &operator >>(B_IDataFile &file, B_Map &map);

#endif /* BMAP_H */
