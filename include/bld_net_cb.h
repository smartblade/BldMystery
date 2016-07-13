
#ifndef BLD_NET_CB_H

#define BLD_NET_CB_H

class bld_net_cb {
public:
        virtual void message_received(
                unsigned long idFrom, unsigned int messageSize,
                unsigned long idTo
        ) = 0;
        virtual void player_destroyed(unsigned long playerId) = 0;
        virtual void player_created(
                unsigned long playerId, const char *name
        ) = 0;
        virtual void unknown00C(int i1, int i2, int i3, const char *s) = 0;
};

#endif /* BLD_NET_CB_H */
