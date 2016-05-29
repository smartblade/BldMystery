
#ifndef BLD_NET_CB_H

#define BLD_NET_CB_H

class bld_net_cb {
public:
        virtual void unknown000() = 0;
        virtual void unknown004() = 0;
        virtual void unknown008() = 0;
        virtual void unknown00C(int i1, int i2, int i3, const char *s) = 0;
};

#endif /* BLD_NET_CB_H */
