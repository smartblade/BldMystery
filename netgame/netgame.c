
#include "netgame.h"

static PyObject* net_ServerChangeLevel(PyObject* self, PyObject* args);
static PyObject* net_SetLocalOptions(PyObject* self, PyObject* args);
static PyObject* net_RestartNet(PyObject* self, PyObject* args);
static PyObject* net_JoinSession(PyObject* self, PyObject* args);
static PyObject* net_GetBrowseResult(PyObject* self, PyObject* args);
static PyObject* net_BrowseSessions(PyObject* self, PyObject* args);
static PyObject* net_StartServer(PyObject* self, PyObject* args);
static PyObject* net_ServerInfoBlock(PyObject* self, PyObject* args);
static PyObject* net_CallEventSound(PyObject* self, PyObject* args);
static PyObject* net_SetSoundFunc(PyObject* self, PyObject* args);
static PyObject* net_SetMutilaFunc(PyObject* self, PyObject* args);
static PyObject* net_SetClientDamageFunc(PyObject* self, PyObject* args);
static PyObject* net_SendUnguaranteedUserString(PyObject* self, PyObject* args);
static PyObject* net_AddSoundToClient(PyObject* self, PyObject* args);
static PyObject* net_ClearPools(PyObject* self, PyObject* args);
static PyObject* net_GetClientId(PyObject* self, PyObject* args);
static PyObject* net_SetObjectState(PyObject* self, PyObject* args);
static PyObject* net_Bind(PyObject* self, PyObject* args);
static PyObject* net_AddPosition(PyObject* self, PyObject* args);
static PyObject* net_SetPersonView(PyObject* self, PyObject* args);
static PyObject* net_GetLocalOptions(PyObject* self, PyObject* args);
static PyObject* net_GetNextPosition(PyObject* self, PyObject* args);
static PyObject* net_SendUserString(PyObject* self, PyObject* args);
static PyObject* net_SetStringUserFunc(PyObject* self, PyObject* args);
static PyObject* net_SetByePlayerFunc(PyObject* self, PyObject* args);
static PyObject* net_GetPlayerData(PyObject* self, PyObject* args);
static PyObject* net_GetNetState(PyObject* self, PyObject* args);
static PyObject* net_SetJoinPlayerFunc(PyObject* self, PyObject* args);
static PyObject* net_CreateMainPlayer(PyObject* self, PyObject* args);
static PyObject* net_SetServerState(PyObject* self, PyObject* args);
static PyObject* net_GetTime(PyObject* self, PyObject* args);
static PyObject* net_SetPPS(PyObject* self, PyObject* args);
static PyObject* net_IsValidProtocol(PyObject* self, PyObject* args);
static PyObject* net_IsDedicated(PyObject* self, PyObject* args);
static PyObject* net_SetDedicated(PyObject* self, PyObject* args);
static PyObject* net_ChangeAnmSoundIndex(PyObject* self, PyObject* args);


static PyMethodDef methods[] = {
    { "CreateMainPlayer",               net_CreateMainPlayer,               METH_VARARGS, "CreateMainPlayer() \n  Crea el jugador principal si es cliente o servidor\n  Se llama 'Player1' y esta funcion se llama solo una vez\n  Retorna verdadero si se creo con exito \n  Usese como un bucle while(not)" },
    { "SetServerState",                 net_SetServerState,                 METH_VARARGS, "SetServerState(boolean) \n  Si envia el valor 1, el servidor pondra a los objetos que se creen, en la red\n  En caso contrario, no lo pondra como objetos de red\n" },
    { "SetJoinPlayerFunc",              net_SetJoinPlayerFunc,              METH_VARARGS, "SetJoinPlayerFunc(func) \n  Activa la funcion Callback de creacion de objetos personaje\n  la funcion recibe un entero y cinco cadenas :\n    I- Identificador del jugador \n    S- Nombre de la entidad \n    S- Nombre del jugador \n    S- Tipo de raza \n    S- Arma deseada \n    S- escudo deseado \n  Cuando esta funcion es llamada ya esta creado el personaje\n  Mas no sus armas\n  En el caso del cliente, la funcion llamada solo tiene : ('Nombre de la entidad','raza')\n" },
    { "GetNetState",                    net_GetNetState,                    METH_VARARGS, "GetNetState() \n  Retorna \n\t\t0 : SinglePlayer \n       1 : Server \n       2 : Client \n" },
    { "GetPlayerData",                  net_GetPlayerData,                  METH_VARARGS, "GetPlayerData(entityname) \n  Retorna \n\t\t(energy,life)\n" },
    { "SetByePlayerFunc",               net_SetByePlayerFunc,               METH_VARARGS, "SetByePlayerFunc(func) \n  Activa la funcion Callback de desconeccion de usuario\n  la funcion recibe un entero y una cadena :\n    I- Identificador del jugador\n    S- Identificador del jugador\n" },
    { "SetStringUserFunc",              net_SetStringUserFunc,              METH_VARARGS, "SetStringUserFunc(func) \n  Activa la funcion Callback de recepcion de cadenas de usuario\n  la funcion recibe dos enteros y una cadena :\n    I- Identificador del jugador    I- Tipo de cadena    S- Cadena de caracteres" },
    { "SendUserString",                 net_SendUserString,                 METH_VARARGS, "SendUserString(int,string) \n  Envia una cadena:    - Al servidor si cliente\n    - A todos si servidor\n  Los valores que se envian, son el tipo de cadena y\n   la cadena en cuestion" },
    { "GetNextPosition",                net_GetNextPosition,                METH_VARARGS, "GetNextPosition() \n  Retorna la posicion proxima en la lista de salidas" },
    { "GetLocalOptions",                net_GetLocalOptions,                METH_VARARGS, "GetLocalOptions() \n  Retorna (nombre,raza,arma,escudo) elegidos para la red" },
    { "SetPersonView",                  net_SetPersonView,                  METH_VARARGS, "SetPersonView(entityname) \n  Hace que la camara apunte a alguna entidad de red" },
    { "AddPosition",                    net_AddPosition,                    METH_VARARGS, "AddPosition(x,y,z) \n  Agrega una posicion nueva a la lista." },
    { "Bind",                           net_Bind,                           METH_VARARGS, "Bind('accion',funcion,SeIgnoraEnHost) \n  La funcion debe recibir un parametro, el nombre de jugador.\n  SeIgnoraEnHost implica que solo se ejecutara la operacion de\nlos clientes, el funcionamiento local no sera modificado ." },
    { "SetObjectState",                 net_SetObjectState,                 METH_VARARGS, "SetObjectState('entidad',Enviar) \n  Activa y desactiva el trafico de la red para una entidad determinada." },
    { "GetClientId",                    net_GetClientId,                    METH_VARARGS, "GetClientId() \n  Solo para clientes:\n     obtiene el nombre de su entidad en el servidor \n" },
    { "ClearPools",                     net_ClearPools,                     METH_VARARGS, "ClearPools() \n  Para todos:\n     Limpia la sangre \n" },
    { "AddSoundToClient",               net_AddSoundToClient,               METH_VARARGS, "AddSoundToClient(EntityName,AnimationName,SoundObject) \n  Para el cliente:\n     Agrega un sonido a los eventos del cliente.\n" },
    { "SendUnguaranteedUserString",     net_SendUnguaranteedUserString,     METH_VARARGS, "SendUnguaranteedUserString(int,string) \n  Envia una cadena:    - Al servidor si cliente\n    - A todos si servidor\n  Los valores que se envian, son el tipo de cadena y\n   la cadena en cuestion" },
    { "SetClientDamageFunc",            net_SetClientDamageFunc,            METH_VARARGS, "SetClientDamageFunc(func) \n  Activa la funcion Callback de da\xf1o del cliente\n  la funcion recibe una cadena :\n    S- Identificador del jugador\n" },
    { "SetMutilaFunc",                  net_SetMutilaFunc,                  METH_VARARGS, "SetMutilaFunc(func) \n  Activa la funcion Callback de mutilaciones del cliente\n  la funcion recibe:\n    S    - Identificador del jugador\n    S    - Identificador del miembro mutilado\n    X,Y,Z- Posicion\n    X,Y,Z- Velocidad\n    I    - Identificador del nodo mutilado\n" },
    { "SetSoundFunc",                   net_SetSoundFunc,                   METH_VARARGS, "SetSoundFunc(func) \n  Activa la funcion Callback de sonidos del cliente\n  la funcion recibe:\n    S    - Identificador del objeto\n    i    - Identificador del miembro mutilado\n" },
    { "CallEventSound",                 net_CallEventSound,                 METH_VARARGS, "CallEventSound(entityname,id) \n  Sevidor indica un sonido a los clientes\n" },
    { "ServerInfoBlock",                net_ServerInfoBlock,                METH_VARARGS, "ServerInfoBlock() \n  Retorna estadisticas de la red para el servidor\n" },
    { "StartServer",                    net_StartServer,                    METH_VARARGS, "StartServer(GameName,PlayerName,MaxPlayers,TCP) \n  Inicia los protocolos del el servidor\n" },
    { "BrowseSessions",                 net_BrowseSessions,                 METH_VARARGS, "BrowseSessions([direccion IP]) \n  Busca en una direccion IP especifica. Si se omite busca en la red IPX\n" },
    { "GetBrowseResult",                net_GetBrowseResult,                METH_VARARGS, "GetBrowseResult(indice del servidor) \n  retorna (nombre,jugadores,maximo) o None \n" },
    { "JoinSession",                    net_JoinSession,                    METH_VARARGS, "JoinSession(indice del servidor,nombre del jugador) \n" },
    { "RestartNet",                     net_RestartNet,                     METH_VARARGS, "RestartNet() \n Reinicia la red en offline \n" },
    { "SetLocalOptions",                net_SetLocalOptions,                METH_VARARGS, "SetLocalOptions(name,kind,weapon,shield,map) \n" },
    { "ServerChangeLevel",              net_ServerChangeLevel,              METH_VARARGS, "ServerChangeLevel(LevelName) \n  Cambia de nivel si es servidor \n" },
    { "GetTime",                        net_GetTime,                        METH_VARARGS, "GetTime() \n  Obtiene el estado del tiempo de red \n  Si es cliente, obtiene el tiempo del servidor\n  Si es servidor, obtiene el tiempo actual\n" },
    { "SetPPS",                         net_SetPPS,                         METH_VARARGS, "SetPPS(i) \n  Cambia el numero de paquetes por segundo \n  Los valores validos van de 1 a 60 \n  0 es para que se procese una vez por frame \n" },
    { "IsValidProtocol",                net_IsValidProtocol,                METH_VARARGS, "IsValidProtocol(TCP) \n  Devuelve verdadero si un protocolo esta disponible.\n  0 : Para IPX/SPX \n  1 : Para TCP/IP  \n" },
    { "IsDedicated",                    net_IsDedicated,                    METH_VARARGS, "IsDedicated() \n  Devuelve verdadero si el servidor arrancara como dedicado.\n" },
    { "SetDedicated",                   net_SetDedicated,                   METH_VARARGS, "SetDedicated(ds) \n  Activa/desactiva el flag de servidor dedicado.\n" },
    { "ChangeAnmSoundIndex",            net_ChangeAnmSoundIndex,            METH_VARARGS, "ChangeAnmSoundIndex(PersonName,Index) \n   Cambia el indice del de la animacion del sonido que se enviara por red\n(*)Este valor suele usarse solo para servidor dedicado.\n" },
    { NULL,                             NULL,                               0,            NULL },
};


// TODO implement
// address: 0x10001000
PyObject* net_ServerChangeLevel(PyObject* self, PyObject* args) {
        assert("net_ServerChangeLevel" == NULL);
        return NULL;
}


/*
* Module:                 netgame.dll
* Entry point:            0x10001041
*/

PyObject *net_SetLocalOptions(PyObject *self, PyObject *args) {
        const char *name, *kind, *weapon, *shield, *map;

        if (!PyArg_ParseTuple(
                args, "sssss", &name, &kind, &weapon, &shield, &map
        ))
                return NULL;

        SetLocalOptions(name, kind, weapon, shield, map);

        return Py_BuildValue("");
}


/*
* Module:                 netgame.dll
* Entry point:            0x100010A4
*/

PyObject *net_RestartNet(PyObject *self, PyObject *args) {


        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        RestartNet();

        return Py_BuildValue("");
}


/*
* Module:                 netgame.dll
* Entry point:            0x100010D7
*/

PyObject *net_JoinSession(PyObject *self, PyObject *args) {
        int index;
        const char *player_name;
        int status;

        if (!PyArg_ParseTuple(args, "is", &index, &player_name))
                return NULL;

        status = JoinSession(index, player_name);

        return Py_BuildValue("i", status);
}


/*
* Module:                 netgame.dll
* Entry point:            0x1000112E
*/

PyObject *net_GetBrowseResult(PyObject *self, PyObject *args) {
        int index;
        bld_server_info info;

        if (!PyArg_ParseTuple(args, "i", &index))
                return NULL;

        if (GetBrowseResult(index, &info))
                return Py_BuildValue(
                        "sii", info.name, info.num_players, info.max_players
                );
        else
                return Py_BuildValue("");
}


/*
* Module:                 netgame.dll
* Entry point:            0x100011A3
*/

PyObject *net_BrowseSessions(PyObject *self, PyObject *args) {
        const char *ip_address = NULL;
        int status;

        if (!PyArg_ParseTuple(args, "s", &ip_address))
                return NULL;

        if (!strcmp(ip_address, "[ipx]"))
                ip_address = NULL;

        status = BrowseSessions(ip_address);

        return Py_BuildValue("i", status);
}


/*
* Module:                 netgame.dll
* Entry point:            0x10001217
*/

PyObject *net_StartServer(PyObject *self, PyObject *args) {
        const char *game_name, *player_name;
        int max_players, TCP, status;

        if (!PyArg_ParseTuple(args, "ssii", &game_name, &player_name, &max_players, &TCP))
                return NULL;

        status = StartServer(game_name, player_name, max_players, (TCP != 0));

        return Py_BuildValue("i", status);
}


// TODO implement
// address: 0x10001284
PyObject* net_ServerInfoBlock(PyObject* self, PyObject* args) {
        assert("net_ServerInfoBlock" == NULL);
        return NULL;
}


// TODO implement
// address: 0x100012b8
PyObject* net_CallEventSound(PyObject* self, PyObject* args) {
        assert("net_CallEventSound" == NULL);
        return NULL;
}


// TODO implement
// address: 0x10001303
PyObject* net_SetSoundFunc(PyObject* self, PyObject* args) {
        assert("net_SetSoundFunc" == NULL);
        return NULL;
}


// TODO implement
// address: 0x10001344
PyObject* net_SetMutilaFunc(PyObject* self, PyObject* args) {
        assert("net_SetMutilaFunc" == NULL);
        return NULL;
}


// TODO implement
// address: 0x10001385
PyObject* net_SetClientDamageFunc(PyObject* self, PyObject* args) {
        assert("net_SetClientDamageFunc" == NULL);
        return NULL;
}


// TODO implement
// address: 0x100013c6
PyObject* net_SendUnguaranteedUserString(PyObject* self, PyObject* args) {
        assert("net_SendUnguaranteedUserString" == NULL);
        return NULL;
}


// TODO implement
// address: 0x1000142a
PyObject* net_AddSoundToClient(PyObject* self, PyObject* args) {
        assert("net_AddSoundToClient" == NULL);
        return NULL;
}


// TODO implement
// address: 0x10001488
PyObject* net_ClearPools(PyObject* self, PyObject* args) {
        assert("net_ClearPools" == NULL);
        return NULL;
}


// TODO implement
// address: 0x100014bb
PyObject* net_GetClientId(PyObject* self, PyObject* args) {
        assert("net_GetClientId" == NULL);
        return NULL;
}


/*
* Module:                 netgame.dll
* Entry point:            0x100014EF
*/

PyObject *net_SetObjectState(PyObject *self, PyObject *args) {
        const char *entity_name;
        int state, status;

        if (!PyArg_ParseTuple(args, "si", &entity_name, &state))
                return NULL;

        status = NetSetObjectState(entity_name, (state != 0));

        return Py_BuildValue("i", status);
}


/*
* Module:                 netgame.dll
* Entry point:            0x1000154C
*/
 
PyObject *net_Bind(PyObject *self, PyObject *args) {
        const char *action;
        PyObject *func;
        int ignore_host;

        if (!PyArg_ParseTuple(args, "sOi", &action, &func, &ignore_host))
                return NULL;

        NetAddEventUserFunc(action, func, ignore_host);

        return Py_BuildValue("");
}


/*
* Module:                 netgame.dll
* Entry point:            0x1000159F
*/

PyObject *net_AddPosition(PyObject *self, PyObject *args) {
        double x, y, z;

        if (!PyArg_ParseTuple(args, "ddd", &x, &y, &z))
                return NULL;

        NetAddPosition(x, y, z);

        return Py_BuildValue("");
}


// TODO implement
// address: 0x100015fe
PyObject* net_SetPersonView(PyObject* self, PyObject* args) {
        assert("net_SetPersonView" == NULL);
        return NULL;
}


/*
* Module:                 netgame.dll
* Entry point:            0x1000163F
*/

PyObject *net_GetLocalOptions(PyObject *self, PyObject *args) {
        const char *name, *kind, *weapon, *shield;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        GetLocalOptionsNet(&name, &kind, &weapon, &shield);

        return Py_BuildValue("ssss", name, kind, weapon, shield);
}


/*
* Module:                 netgame.dll
* Entry point:            0x1000169A
*/

PyObject *net_GetNextPosition(PyObject *self, PyObject *args) {
        double x, y, z;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        GetNextPosition(&x, &y, &z);

        return Py_BuildValue("ddd", x, y, z);
}


/*
* Module:                 netgame.dll
* Entry point:            0x100016F9
*/

PyObject *net_SendUserString(PyObject *self, PyObject *args) {
        int kind;
        const char *str = NULL;
        const char *unknown_str = NULL;

        if (!PyArg_ParseTuple(args, "is|s", &kind, &str, &unknown_str))
                return NULL;

        SendNetUserString(kind, str, 1, unknown_str);

        return Py_BuildValue("");
}


/*
* Module:                 netgame.dll
* Entry point:            0x1000175D
*/

PyObject *net_SetStringUserFunc(PyObject *self, PyObject *args) {
        PyObject *func;

        if (!PyArg_ParseTuple(args, "O", &func))
                return NULL;

        ServerSetPyGetUserString(func);

        return Py_BuildValue("");
}


/*
* Module:                 netgame.dll
* Entry point:            0x1000179E
*/

PyObject *net_SetByePlayerFunc(PyObject *self, PyObject *args) {
        PyObject *func;

        if (!PyArg_ParseTuple(args, "O", &func))
                return NULL;

        ServerSetPyByePlayerFunc(func);

        return Py_BuildValue("");
}


/*
* Module:                 netgame.dll
* Entry point:            0x100017DF
*/

PyObject *net_GetPlayerData(PyObject *self, PyObject *args) {
        const char *entity_name;
        int energy, life;

        if (!PyArg_ParseTuple(args, "s", &entity_name))
                return NULL;

        GetLifeAndLevel(entity_name, &energy, &life);

        return Py_BuildValue("ii", energy, life);
}


/*
* Module:                 netgame.dll
* Entry point:            0x10001832
*/

PyObject *net_GetNetState(PyObject *self, PyObject *args) {
        int net_state;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        net_state = GetNetState();

        return Py_BuildValue("i", net_state);
}


/*
* Module:                 netgame.dll
* Entry point:            0x1000186F
*/

PyObject *net_SetJoinPlayerFunc(PyObject *self, PyObject *args) {
        PyObject *func;

        if (!PyArg_ParseTuple(args, "O", &func))
                return NULL;

        ServerSetPyCreatePlayerFunc(func);

        return Py_BuildValue("");
}


/*
* Module:                 netgame.dll
* Entry point:            0x100018B0
*/

PyObject *net_CreateMainPlayer(PyObject *self, PyObject *args) {
        int status;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        status = ClientStartMainChar();

        return Py_BuildValue("i", status);
}


/*
* Module:                 netgame.dll
* Entry point:            0x100018F2
*/

PyObject *net_SetServerState(PyObject *self, PyObject *args) {
        int state, status;

        if (!PyArg_ParseTuple(args, "i", &state))
                return NULL;

        status = ServerSetSendDataState(state);

        return Py_BuildValue("i", status);
}


// TODO implement
// address: 0x1000193a
PyObject* net_GetTime(PyObject* self, PyObject* args) {
        assert("net_GetTime" == NULL);
        return NULL;
}


/*
* Module:                 netgame.dll
* Entry point:            0x10001979
*/

PyObject *net_SetPPS(PyObject *self, PyObject *args) {
        int PPS, status;

        if (!PyArg_ParseTuple(args, "i", &PPS))
                return NULL;

        status = NetSetPPS(PPS);

        return Py_BuildValue("i", status);
}


/*
* Module:                 netgame.dll
* Entry point:            0x100019C1
*/

PyObject *net_IsValidProtocol(PyObject *self, PyObject *args) {
        int protocol, is_valid;

        if (!PyArg_ParseTuple(args, "i", &protocol))
                return NULL;

        is_valid = IsValidProtocol(protocol);

        return Py_BuildValue("i", is_valid);
}


/*
* Module:                 netgame.dll
* Entry point:            0x10001A09
*/

PyObject *net_IsDedicated(PyObject *self, PyObject *args) {
        int dedicated_state;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        dedicated_state = GetDedicatedServerState();

        return Py_BuildValue("i", dedicated_state);
}


// TODO implement
// address: 0x10001a46
PyObject* net_SetDedicated(PyObject* self, PyObject* args) {
        assert("net_SetDedicated" == NULL);
        return NULL;
}


// TODO implement
// address: 0x10001a87
PyObject* net_ChangeAnmSoundIndex(PyObject* self, PyObject* args) {
        assert("net_ChangeAnmSoundIndex" == NULL);
        return NULL;
}


/*
* Module:                 netgame.dll
* Entry point:            0x10001AD2
*/

INIT_PY_MODULE_FUNC initnetgame() {
        Py_InitModule("netgame", methods);
}

