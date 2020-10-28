#ifndef SIMPLEACT_H

#define SIMPLEACT_H

class B_PersonStatus
{
public:
    B_PersonStatus(int);
    void Reset();

    char unknown_fields[0x7C];
    int jumpActivated;
    char unknown_fields80[0x52];
};

#endif /* SIMPLEACT_H */
