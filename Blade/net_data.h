#ifndef NET_DATA_H

#define NET_DATA_H

typedef struct {
        char unknownFields[8];
        boolean (*is_net_game)(void);
        boolean (*is_server)(void);
} net_data_methods_t;

typedef struct {
        net_data_methods_t *methods;
} net_data_t;

#ifndef BLD_EXT_FUNCS

extern boolean net_data_is_net_game(net_data_t *self);
extern boolean net_data_is_server(net_data_t *self);

#endif

#endif /* NET_DATA_H */

