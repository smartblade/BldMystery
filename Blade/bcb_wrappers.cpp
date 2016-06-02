
#include <bld_system.h>
#include <bld_python.h>
#include "bld_ext_funcs.h"


#define DEFINE_BCB_METHOD_WRAPPER(object, offset) {\
        static void *espPtr;\
        static void *retPtr;\
        _asm { mov eax, object }\
        _asm { mov edx, [eax] }\
        _asm { mov eax, [edx] }\
        _asm { mov ecx, [esp] }\
        _asm { mov retPtr, ecx }\
        _asm { mov ecx, edx }\
        _asm { mov espPtr, esp }\
        _asm { add esp, 0x08 }\
        _asm { call [eax + offset] }\
        _asm { mov esp, espPtr }\
        _asm { mov ecx, retPtr }\
        _asm { mov [esp], ecx }\
        _asm { ret }\
}

#define DEFINE_BCB_METHOD_WRAPPER_RET(object, offset, ret_value) {\
        DEFINE_BCB_METHOD_WRAPPER(object, offset)\
        return ret_value;\
}

class bcb_net : public bld_abstract_net
{
        virtual void unknown000() {}
        virtual int unknown004() {return 0;}
        virtual bool is_net_game();
        virtual bool is_server();
        virtual void unknown010() {}
        virtual long send_message(
                unsigned long idTo, void *lpData, unsigned long wDataSize) {return -1;}
        virtual long send_guaranteed_message(
                unsigned long idTo, void *lpData, unsigned long wDataSize
        ) { return -1;}
        virtual bool start_server(
                const char *game_name, const char *player_name, int max_players,
                bool TCP
        );
        virtual bool browse_sessions(const char *ip_address);
        virtual bool get_browse_result(int index, bld_server_info *info);
        virtual bool join_session(int index, const char *player_name);
        virtual bool is_valid_protocol(bool tcp);
        virtual ~bcb_net() {}
};

__declspec(naked) bool bcb_net::is_net_game()
        DEFINE_BCB_METHOD_WRAPPER_RET(net_data_ptr, 0x08, false)

__declspec(naked) bool bcb_net::is_server()
        DEFINE_BCB_METHOD_WRAPPER_RET(net_data_ptr, 0x0C, false)

__declspec(naked) bool bcb_net::start_server(
        const char *game_name, const char *player_name, int max_players,
        bool TCP
)
        DEFINE_BCB_METHOD_WRAPPER_RET(net_data_ptr, 0x1C, false)

__declspec(naked) bool bcb_net::browse_sessions(const char *ip_address)
        DEFINE_BCB_METHOD_WRAPPER_RET(net_data_ptr, 0x20, false)

__declspec(naked) bool bcb_net::get_browse_result(int index, bld_server_info *info)
        DEFINE_BCB_METHOD_WRAPPER_RET(net_data_ptr, 0x24, false)

__declspec(naked) bool bcb_net::join_session(int index, const char *player_name)
        DEFINE_BCB_METHOD_WRAPPER_RET(net_data_ptr, 0x28, false)

__declspec(naked) bool bcb_net::is_valid_protocol(bool tcp)
        DEFINE_BCB_METHOD_WRAPPER_RET(net_data_ptr, 0x2C, false)

void create_bcb_wrappers()
{
        net = new bcb_net();
}

