#ifndef SIMPLEACT_H

#define SIMPLEACT_H

class B_PersonStatus
{
public:
    B_PersonStatus(int);
    void Reset();
    void ProcessInputActions(double time);

    char unknown_fields[0x7C];
    int jumpActivated;
    char unknown_fields80[0x4];
    double unknown84;
    double unknown8C;
    double unknown94;
    double unknown9C;
    double unknownA4;
    double unknownAC;
    double unknownB4;
    char unknown_fieldsBC[0x18];
};

#endif /* SIMPLEACT_H */
