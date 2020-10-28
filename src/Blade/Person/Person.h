#ifndef PERSON_H

#define PERSON_H

#include <BBLibc.h>
#include <enemies/Combos_Stuff.h>
#include <Person/simpleact.h>


class B_CharType;

class B_Person
{
public:
    void LaunchAnimation(const char *animationName, double time);

    char unknownFields1224[0x50];
    B_Name animName;
    char unknownFields1278[0x8B0];
    B_CharType *charType;
    char unknownFields1B30[0x3C];
    B_Combos combos;
    char unknownFields1BD8[0x38];
    B_PersonStatus status1;
    char unknownFields1CE4[0xF0];
};

#endif /* PERSON_H */
