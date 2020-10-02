#ifndef CHAR_TYPE_H

#define CHAR_TYPE_H

#include <BBLibc.h>


class B_BipedData;

class B_CharType : public B_NamedObj
{
public:
    char unknown_fields[0x1A58];
    B_BipedData *biped;
};

#endif /* CHAR_TYPE_H */
