
#include "netblade_int.h"


#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP bld_abstract_net *bcb_GetNetInterface(bld_net_cb *cb, void *module);

#ifdef __cplusplus
}
#endif


#define DEFINE_VC2BC_METHOD_WRAPPER(offset, argsize) {\
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

#define DEFINE_VC2BC_METHOD_WRAPPER_RET(offset, argsize, ret_value) {\
        DEFINE_VC2BC_METHOD_WRAPPER(offset, argsize)\
        return ret_value;\
}

#define DEFINE_BC2VC_METHOD_WRAPPER(offset, argsize) {\
        _asm { mov ecx, [esp + 0x04] }\
        _asm { mov eax, [ecx + 0x04] }\
        _asm { mov edx, [eax] }\
        _asm { sub esp, argsize }\
        _asm { mov edi, esp }\
        _asm { lea esi, esp + 0x08 + argsize }\
        _asm { mov ecx, argsize }\
        _asm { rep movsb }\
        _asm { mov ecx, eax }\
        _asm { call [edx + offset] }\
        _asm { ret }\
}


class vc2bc_net : public bld_abstract_net
{
private:
        bld_abstract_net *net;
public:
        vc2bc_net(bld_abstract_net *net)
        {
                this->net = net;
        }
        virtual unsigned long get_session_player_dpid();
        virtual unsigned long get_all_players_id();
        virtual bool is_net_game();
        virtual bool is_server();
        virtual unsigned long get_player_dpid();
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

__declspec(naked) unsigned long vc2bc_net::get_session_player_dpid()
        DEFINE_VC2BC_METHOD_WRAPPER_RET(0x00, 0x00, false)

__declspec(naked) unsigned long vc2bc_net::get_all_players_id()
        DEFINE_VC2BC_METHOD_WRAPPER_RET(0x04, 0x00, false)

__declspec(naked) bool vc2bc_net::is_net_game()
        DEFINE_VC2BC_METHOD_WRAPPER_RET(0x08, 0x00, false)

__declspec(naked) bool vc2bc_net::is_server()
        DEFINE_VC2BC_METHOD_WRAPPER_RET(0x0C, 0x00, false)

__declspec(naked) unsigned long vc2bc_net::get_player_dpid()
        DEFINE_VC2BC_METHOD_WRAPPER_RET(0x10, 0x00, false)

__declspec(naked) long vc2bc_net::send_message(
        unsigned long idTo, void *lpData, unsigned long wDataSize)
        DEFINE_VC2BC_METHOD_WRAPPER_RET(0x14, 0x0C, 0)

__declspec(naked) long vc2bc_net::send_guaranteed_message(
                unsigned long idTo, void *lpData, unsigned long wDataSize
        )
        DEFINE_VC2BC_METHOD_WRAPPER_RET(0x18, 0x0C, 0)

__declspec(naked) bool vc2bc_net::start_server(
        const char *game_name, const char *player_name, int max_players,
        bool TCP
)
        DEFINE_VC2BC_METHOD_WRAPPER_RET(0x1C, 0x10, false)

__declspec(naked) bool vc2bc_net::browse_sessions(const char *ip_address)
        DEFINE_VC2BC_METHOD_WRAPPER_RET(0x20, 0x04, false)

__declspec(naked) bool vc2bc_net::get_browse_result(int index, bld_server_info *info)
        DEFINE_VC2BC_METHOD_WRAPPER_RET(0x24, 0x08, false)

__declspec(naked) bool vc2bc_net::join_session(int index, const char *player_name)
        DEFINE_VC2BC_METHOD_WRAPPER_RET(0x28, 0x08, false)

__declspec(naked) bool vc2bc_net::is_valid_protocol(bool tcp)
        DEFINE_VC2BC_METHOD_WRAPPER_RET(0x2C, 0x04, false)


class bc2vc_net_cb : public bld_net_cb
{
private:
        bld_net_cb *cb;
public:
        bc2vc_net_cb(bld_net_cb *cb)
        {
                this->cb = cb;
        }
        virtual void message_received(
                unsigned long idFrom, void *message, unsigned long messageSize
        );
        virtual void player_destroyed(unsigned long playerId);
        virtual void player_created(
                unsigned long playerId, const char *name
        );
        virtual void unknown00C(int i1, int i2, int i3, const char *s);
};

__declspec(naked) void bc2vc_net_cb::message_received(
        unsigned long idFrom, void *message, unsigned long messageSize
)
        DEFINE_BC2VC_METHOD_WRAPPER(0x00, 0x0C)

__declspec(naked) void bc2vc_net_cb::player_destroyed(unsigned long playerId)
        DEFINE_BC2VC_METHOD_WRAPPER(0x04, 0x04)

__declspec(naked) void bc2vc_net_cb::player_created(
        unsigned long playerId, const char *name
)
        DEFINE_BC2VC_METHOD_WRAPPER(0x08, 0x08)

__declspec(naked) void bc2vc_net_cb::unknown00C(
        int i1, int i2, int i3, const char *s
)
        DEFINE_BC2VC_METHOD_WRAPPER(0x0C, 0x10)


bld_abstract_net *bcb_GetNetInterface(bld_net_cb *cb, void *module) {
        bc2vc_net_cb *bc2vc_cb = new bc2vc_net_cb(cb);
        bld_abstract_net *net = GetNetInterface(bc2vc_cb, module);
        return new vc2bc_net(net);
}
