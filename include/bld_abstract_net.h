#ifndef BLD_ABSTRACT_NET_H

#define BLD_ABSTRACT_NET_H


#include <bld_server_info.h>


class bld_abstract_net {
public:
        virtual void unknown000() = 0;
        virtual void unknown004() = 0;
        virtual bool is_net_game() = 0;
        virtual bool is_server() = 0;
        virtual void unknown010() = 0;
        virtual void unknown014() = 0;
        virtual void unknown018() = 0;
        virtual bool start_server(
                const char *game_name, const char *player_name, int max_players,
                bool TCP
        ) = 0;
        virtual bool browse_sessions(const char *ip_address) = 0;
        virtual bool get_browse_result(int index, bld_server_info *info) = 0;
        virtual bool join_session(int index, const char *player_name) = 0;
        virtual bool is_valid_protocol(bool tcp) = 0;
        virtual void unknown030() = 0;
};

#endif /* BLD_ABSTRACT_NET_H */
