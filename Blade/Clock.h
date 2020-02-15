
#ifndef B_CLOCK_H

#define B_CLOCK_H


class B_Clock
{
public:
    virtual void unknown000();
    virtual ~B_Clock();
    virtual void SetTimeSpeed(double speed);
    virtual double GetTimeSpeed();
    virtual double GetTime();
    virtual void SetTime(double time);
    virtual void unknown018();
    virtual void StopTime();
    virtual void RestartTime();

    bool isActive;
    double fUnknown08;
    double fUnknown10;
    double fUnknown18;
    char unknownFields2[36];
};

#endif /* B_CLOCK_H */

