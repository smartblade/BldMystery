#ifndef NETBLADE_INT_H

#define NETBLADE_INT_H

#include <dplobby.h>
#include <bld_system.h>
#include <bld_abstract_net.h>
#include <bld_net_cb.h>
#define BUILD_LIB
#include <export.h>

#define MAX_SESSIONS_NUM                                 32

typedef struct {
        LPDIRECTPLAY4A dp_interface;
        LPDIRECTPLAYLOBBY3A dp_lobby;
        HANDLE event;
        DPID dpid;
        int is_server;
} PLAYER_INFO;

typedef struct {
        DPSESSIONDESC2 desc;
        char session_name[128];
} SESSION_INFO;

class bld_net : public bld_abstract_net
{
private:
        bld_net_cb *cb;
public:
        bld_net(bld_net_cb *cb) {
                this->cb = cb;
        }
        virtual unsigned long get_session_player_dpid();
        virtual unsigned long get_all_players_id();
        virtual bool is_net_game();
        virtual bool is_server();
        virtual unsigned long get_player_dpid();
        virtual long send_message(
                unsigned long idTo, void *lpData, unsigned long wDataSize
        );
        virtual long send_guaranteed_message(
                unsigned long idTo, void *lpData, unsigned long wDataSize
        );
        virtual bool start_server(
                const char *game_name, const char *player_name, int max_players,
                bool TCP
        );
        virtual bool browse_sessions(const char *ip_address);
        virtual bool get_browse_result(int index, bld_server_info *info);
        virtual bool join_session(int index, const char *player_name);
        virtual bool is_valid_protocol(bool tcp);
        virtual ~bld_net();
        static void message_received(
                unsigned long idFrom, void *message, unsigned long messageSize
        );
        static void player_destroyed(unsigned long playerId);
        static void cb_unknown00C(int i1, int i2, int i3, const char *s);
        static void player_created(unsigned long playerId, const char *name);
};


extern bool is_server;
extern bool is_net_game;
extern PLAYER_INFO gbl_player_info;
extern HANDLE gbl_event;
extern HANDLE gbl_thread;
extern DWORD gbl_thread_id;
extern LPDIRECTPLAY4A gbl_dp_interface;
extern bool is_valid_ipx;
extern bool is_valid_tcp;
extern bld_net *gbl_net;


extern bool bld_is_server(void);
extern bool bld_is_net_game(void);
extern void bld_set_gbl_player_info(PLAYER_INFO *player_info);
extern DPID bld_get_player_dpid(void);
extern HRESULT bld_create_thread_by_module(HMODULE module);
extern HRESULT bld_get_player_name(
        LPDIRECTPLAY4A dp_interface, DPID dpid, LPDPNAME *lpdpname
);
extern int bld_destroy_handles(void);
extern void bld_shift_unknown_names(const char *name);
extern HRESULT bld_send_message(DPID idTo, LPVOID lpData, DWORD wDataSize);
extern HRESULT bld_send_guaranteed_message(
        DPID idTo, LPVOID lpData, DWORD wDataSize
);
extern HRESULT bld_create_thread(void);
extern HRESULT bld_update_player_data(void);

extern DPID bld_get_session_player_dpid(void);
extern HRESULT bld_show_connection_dialog(
        HMODULE module, PLAYER_INFO *player_info
);
extern void bld_enum_players(LPDIRECTPLAY4A dp_interface);

extern bool bld_start_server(
        const char *game_name, const char *player_name, int max_players,
        bool TCP
);
extern HRESULT bld_create_dp_interface(
        LPGUID dp_provider, LPDIRECTPLAY4A *dp_interface
);
extern HRESULT bld_destroy_dp_interface(LPDIRECTPLAY4A dp_interface);
extern bool bld_get_browse_result(int index, bld_server_info *info);
extern bool bld_browse_sessions(const char *ip_address);
extern bool bld_join_session(int index, const char *player_name);
extern bool bld_check_protocol(bool tcp);


#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP bld_abstract_net *GetNetInterface(bld_net_cb *cb, HMODULE module);
LIB_EXP void CloseConection(void);

#ifdef __cplusplus
}
#endif


#endif /* NETBLADE_INT_H */

