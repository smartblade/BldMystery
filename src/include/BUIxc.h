#ifndef BUIXC_H

#define BUIXC_H

#include <BBLibc/NamedObj.h>
#include <export.h>

class LIB_EXP B_Widget
{
public:
    virtual void unknown000() = 0;
    virtual unsigned int SetSize(float w, float h);
    virtual void unknown008() = 0;
    virtual void unknown00C() = 0;
    virtual void Draw(int x, int y, float time);
};


class B_Font : public B_NamedObj
{
public:
    struct B_CharSize
    {
        float x;
        float y;
        float width;
        float height;
    };

    struct B_CharData
    {
        B_CharSize charSize[256];
    };

    const B_CharData *GetChars() const
    {
        return charData;
    }

    unsigned long GethBitmap() const
    {
        return bitmapHandle;
    }

private:
    long bitmapHandle;
    char unknown_fields[24];
    B_CharData *charData;
};

#endif /* BUIXC_H */
