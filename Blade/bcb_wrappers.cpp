
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
        _asm { mov ecx, [esp + 0x04] }\
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
        virtual void unknown004() {}
        virtual bool is_net_game() {return TRUE;}
        virtual bool is_server() {return TRUE;}
        virtual void unknown010() {}
        virtual void unknown014() {}
        virtual void unknown018() {}
        virtual bool start_server(
                const char *game_name, const char *player_name, int max_players,
                bool TCP
        ) {return TRUE;}
        virtual bool browse_sessions(const char *ip_address) {return TRUE;}
        virtual bool get_browse_result(int index, bld_server_info *info) {return TRUE;}
        virtual bool join_session(int index, const char *player_name) {return TRUE;}
        virtual bool is_valid_protocol(bool tcp);
        virtual void unknown030() {}
};

__declspec(naked) bool bcb_net::is_valid_protocol(bool tcp)
        DEFINE_BCB_METHOD_WRAPPER_RET(net_data_ptr, 0x2C, false)

void create_bcb_wrappers()
{
        net = new bcb_net();
}

