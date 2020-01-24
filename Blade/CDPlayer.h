
#ifndef CD_PLAYER_H

#define CD_PLAYER_H

class CDPlayer
{
public:
    virtual void unknown0000();
    virtual int PlayCDTrack(int ntrack);
};

extern "C"
{

/*
* Module:                 Blade.exe
* Data address:           0x007C91B0
*/
extern CDPlayer *cdPlayer;

}

#endif /* CD_PLAYER_H */
