
#ifndef GAME_NET_H

#define GAME_NET_H

extern "C"
{

extern void OnEvent(int a, int b);
extern void ResetClientMapName(void);
extern const char *GetNetMap(const char *map);
extern void SendPlayerName();

}

#endif /* GAME_NET_H */
