
#ifndef BMAP_H

#define BMAP_H

#include <array.h>
#include <BBLibc.h>
#include "sector.h"

extern "C"
{

extern B_IDataFile * read_sectors(B_IDataFile *file, B_PtrArray<B_Sector> *sectors);

}

#endif /* BMAP_H */
