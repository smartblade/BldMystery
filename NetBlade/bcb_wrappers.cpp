
#include "netblade_int.h"


#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP bld_abstract_net *bcb_GetNetInterface(bld_net_cb *cb, void *module);

#ifdef __cplusplus
}
#endif


#define DEFINE_VC2BCB_METHOD_WRAPPER(offset, argsize) {\
        _asm { mov eax, [ecx + 0x04] }\
        _asm { mov edx, [eax] }\
        _asm { sub esp, argsize }\
        _asm { mov edi, esp }\
        _asm { lea esi, esp + 0x04 + argsize }\
        _asm { mov ecx, argsize }\
        _asm { rep movsb }\
        _asm { push eax }\
        _asm { call [edx + offset] }\
        _asm { add esp, 0x04 }\
        _asm { add esp, argsize }\
        _asm { ret argsize}\
}

#define DEFINE_VC2BCB_METHOD_WRAPPER_RET(offset, argsize, ret_value) {\
        DEFINE_VC2BCB_METHOD_WRAPPER(offset, argsize)\
        return ret_value;\
}


class vc2bcb_net : public bld_abstract_net
{
private:
        bld_abstract_net *net;
public:
        vc2bcb_net(bld_abstract_net *net)
        {
                this->net = net;
        }
        virtual unsigned long get_session_player_dpid();
        virtual unsigned long get_all_players_id();
        virtual bool is_net_game();
        virtual bool is_server();
        virtual void unknown010();
        virtual long send_message(
                unsigned long idTo, void *lpData, unsigned long wDataSize);
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
};

__declspec(naked) unsigned long vc2bcb_net::get_session_player_dpid()
        DEFINE_VC2BCB_METHOD_WRAPPER_RET(0x00, 0x00, false)

__declspec(naked) unsigned long vc2bcb_net::get_all_players_id()
        DEFINE_VC2BCB_METHOD_WRAPPER_RET(0x04, 0x00, false)

__declspec(naked) bool vc2bcb_net::is_net_game()
        DEFINE_VC2BCB_METHOD_WRAPPER_RET(0x08, 0x00, false)

__declspec(naked) bool vc2bcb_net::is_server()
        DEFINE_VC2BCB_METHOD_WRAPPER_RET(0x0C, 0x00, false)

__declspec(naked) void vc2bcb_net::unknown010()
        DEFINE_VC2BCB_METHOD_WRAPPER_RET(0x10, 0x00, (void)false)

__declspec(naked) long vc2bcb_net::send_message(
        unsigned long idTo, void *lpData, unsigned long wDataSize)
        DEFINE_VC2BCB_METHOD_WRAPPER_RET(0x14, 0x0C, 0)

__declspec(naked) long vc2bcb_net::send_guaranteed_message(
                unsigned long idTo, void *lpData, unsigned long wDataSize
        )
        DEFINE_VC2BCB_METHOD_WRAPPER_RET(0x18, 0x0C, 0)

__declspec(naked) bool vc2bcb_net::start_server(
        const char *game_name, const char *player_name, int max_players,
        bool TCP
)
        DEFINE_VC2BCB_METHOD_WRAPPER_RET(0x1C, 0x10, false)

__declspec(naked) bool vc2bcb_net::browse_sessions(const char *ip_address)
        DEFINE_VC2BCB_METHOD_WRAPPER_RET(0x20, 0x04, false)

__declspec(naked) bool vc2bcb_net::get_browse_result(int index, bld_server_info *info)
        DEFINE_VC2BCB_METHOD_WRAPPER_RET(0x24, 0x08, false)

__declspec(naked) bool vc2bcb_net::join_session(int index, const char *player_name)
        DEFINE_VC2BCB_METHOD_WRAPPER_RET(0x28, 0x08, false)

__declspec(naked) bool vc2bcb_net::is_valid_protocol(bool tcp)
        DEFINE_VC2BCB_METHOD_WRAPPER_RET(0x2C, 0x04, false)


bld_abstract_net *bcb_GetNetInterface(bld_net_cb *cb, void *module) {
        bld_abstract_net *net = GetNetInterface(cb, module);
        return new vc2bcb_net(net);
}
