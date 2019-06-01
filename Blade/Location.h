#ifndef LOCATION_H

#define LOCATION_H

#include "game_state.h"

class location_t
{
public:
    void setPosition(const point_t &pos);
    void setOrientation(const point_t &orientation);
private:
    point_t position;
};

#endif