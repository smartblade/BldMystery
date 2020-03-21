
#ifndef LIB_NET_H

#define LIB_NET_H

extern "C"
{

extern void SetDedicatedServer(bool isDedicated);
extern bool IsDedicatedServer();
extern void LoadNetModule(char *fileName);
extern bool FreeNetData(bool freeNetLibrary);

}

#endif /* LIB_NET_H */
