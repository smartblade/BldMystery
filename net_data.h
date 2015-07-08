#ifndef NET_DATA_H

#define NET_DATA_H

typedef struct {
        char unknownFields[8];
        int  (*is_net_game)(void);
        int  (*is_server)(void);
} net_data_methods_t;

typedef struct {
        net_data_methods_t *methods;
} net_data_t;

#ifndef BLD_EXT_FUNCS

extern int net_data_is_net_game(net_data_t *self);
extern int net_data_is_server(net_data_t *self);

#endif

#endif /* NET_DATA_H */

