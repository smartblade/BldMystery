
#ifndef GAME_CLOCK_H

#define GAME_CLOCK_H


class game_clock_t
{
public:
        virtual void unknown000();
        virtual void unknown004();
        virtual void unknown008();
        virtual void unknown00C();
        virtual void unknown010();
        virtual void unknown014();
        virtual void unknown018();
        virtual void unknown01C();
        virtual void unknown020();

        boolean bUnknown04;
        double fUnknown08;
        double fUnknown10;
        double fUnknown18;
        char unknownFields2[36];
};

#endif /* GAME_CLOCK_H */

