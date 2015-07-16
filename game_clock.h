
#ifndef GAME_CLOCK_H

#define GAME_CLOCK_H


typedef struct {
        void *unknownFuncs[6];
        void (*unknown18)(void); /*0x004CC360*/
        void (*unknown1C)(void); /*0x004CC3A0*/
} game_clock_methods_t;

typedef struct {
        game_clock_methods_t *methods;
        boolean bUnknown04;
        double fUnknown08;
        double fUnknown10;
        double fUnknown18;
        char unknownFields2[36];
} game_clock_t;



#endif /* GAME_CLOCK_H */

