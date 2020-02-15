
#ifndef GAME_CLOCK_H

#define GAME_CLOCK_H


class game_clock_t
{
public:
        virtual void unknown000();
        virtual ~game_clock_t();
        virtual void unknown008();
        virtual void unknown00C();
        virtual void unknown010();
        virtual void SetTime(double time);
        virtual void unknown018();
        virtual void StopTime();
        virtual void RestartTime();

        boolean bUnknown04;
        double fUnknown08;
        double fUnknown10;
        double fUnknown18;
        char unknownFields2[36];
};

#endif /* GAME_CLOCK_H */

