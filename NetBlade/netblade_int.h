#ifndef NETBLADE_INT_H

#define NETBLADE_INT_H

#include <dplobby.h>
#include <bld_system.h>
#include <bld_abstract_net.h>
#include <bld_net_cb.h>
#define BUILD_LIB
#include <export.h>

typedef struct {
        LPDIRECTPLAY4A dp_interface;
        void *unknown04;
        HANDLE event;
        DPID dpid;
        int unknown10;
} PLAYER_INFO;


extern bool is_net_game;
extern PLAYER_INFO gbl_player_info;
extern LPDIRECTPLAYLOBBY3A gbl_dp_lobby;
extern LPDIRECTPLAY4A gbl_dp_interface;
extern bool is_valid_ipx;
extern bool is_valid_tcp;
extern bld_abstract_net *gbl_net;


extern bool bld_is_server(void);
extern bool bld_is_net_game(void);
extern void bld_set_gbl_player_info(PLAYER_INFO *player_info);
extern DPID bld_get_player_dpid(void);
extern HRESULT bld_get_player_name(
        LPDIRECTPLAY4A dp_interface, DPID dpid, LPDPNAME *lpdpname
);
extern int bld_destroy_handles(void);
extern void bld_shift_unknown_names(const char *name);
extern HRESULT bld_create_thread(void);
extern HRESULT bld_update_player_data(void);

extern void bld_enum_players(LPDIRECTPLAY4A dp_interface);

extern bool bld_start_server(
        const char *game_name, const char *player_name, int max_players,
        bool TCP
);
extern HRESULT bld_create_dp_interface(
        LPGUID dp_provider, LPDIRECTPLAY4A *dp_interface
);
extern HRESULT bld_destroy_dp_interface(LPDIRECTPLAY4A dp_interface);
extern bool bld_check_protocol(bool tcp);


#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP bld_abstract_net *GetNetInterface(bld_net_cb *cb, void *module);
LIB_EXP void CloseConnection(void);

#ifdef __cplusplus
}
#endif


class bld_net : public bld_abstract_net
{
private:
        void *cb;
public:
        bld_net(void *cb) {
                this->cb = cb;
        }
        virtual void unknown000();
        virtual void unknown004();
        virtual bool is_net_game();
        virtual bool is_server();
        virtual void unknown010();
        virtual void unknown014();
        virtual void unknown018();
        virtual bool start_server(
                const char *game_name, const char *player_name, int max_players,
                bool TCP
        );
        virtual bool browse_sessions(const char *ip_address);
        virtual bool get_browse_result(int index, bld_server_info *info);
        virtual bool join_session(int index, const char *player_name);
        virtual bool is_valid_protocol(bool tcp);
        virtual ~bld_net();
};


#endif /* NETBLADE_INT_H */

