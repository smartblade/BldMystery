#define BBLIBC_LIB_EXPORT
#include "Name.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003300
* VC++ mangling:          ??0B_Name@@QAE@XZ
*/

B_Name::B_Name() : string(new char[1]), len(0) {
    *string = 0; // initialize the first byte to 0
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003337
* VC++ mangling:          ??0B_Name@@QAE@PBD@Z
*/

B_Name::B_Name(const char* str) {
    char* p = (char*)str;
    int len = 0;

    // Calculate the length of the string
    while (*p != '\0') {
        len++;
        p++;
    }

    len++; // account for null character

    char* buffer = new char[len];

    // Copy the string into the allocated memory
    for (int i = 0; i < len; i++) {
        buffer[i] = str[i];
    }

    this->string = buffer; //strdup(str);
    this->len = len;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100033A4
* VC++ mangling:          ??0B_Name@@QAE@ABV0@@Z
*/

B_Name::B_Name(const B_Name& src) : len(src.len) {
    string = new char[len + 1];
    strcpy(string, src.string);
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003410
* VC++ mangling:          ??0B_Name@@QAE@I@Z
*/

B_Name::B_Name(unsigned int len) : len(len) {
    string = new char[len + 1];
    string[len] = '\0';
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100039BA
* VC++ mangling:          ??1B_Name@@QAE@XZ
*/

B_Name::~B_Name() {
    delete string;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003769
* VC++ mangling:          ?CompareNoCase@B_Name@@QBEIPBD@Z
*/

unsigned int B_Name::CompareNoCase(const char* str) const {
    if (this->string != 0) {
        return 1;
    }

    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000378E
* VC++ mangling:          ??4B_Name@@QAEAAV0@ABV0@@Z
*/

B_Name& B_Name::operator =(const B_Name& src) {
    if (this != &src) {
        //delete[] string;
        //delete string;
        len = src.len;
        string = new char[len + 1];
        strcpy(string, src.string);
    }
    return *this;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100036C5
* VC++ mangling:          ??9B_Name@@QBEIPBD@Z
*/

unsigned int B_Name::operator !=(const char* str) const {
    return strcmp(string, str) != 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1000354D
* VC++ mangling:          ??8B_Name@@QBEIABV0@@Z
*/

unsigned int B_Name::operator ==(const B_Name& rhs) const {
    // TODO Implement
    return 0;

}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003457
* VC++ mangling:          ?String@B_Name@@QBEQADXZ
*/

 char* const B_Name::String() const {
    return this->string;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100035D2
* VC++ mangling:          ??8B_Name@@QBEIPBD@Z
*/

unsigned int B_Name::operator ==(const char* str) const {
    // TODO Implement
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003643
* VC++ mangling:          ??9B_Name@@QBEIABV0@@Z
*/

unsigned int B_Name::operator !=(const B_Name& rhs) const {
    return !(*this == rhs);
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003467
* VC++ mangling:          ??OB_Name@@QBEIABV0@@Z
*/

unsigned int B_Name::operator >(const B_Name& rhs) const {
    // TODO Implement
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100034DA
* VC++ mangling:          ??MB_Name@@QBEIABV0@@Z
*/

unsigned int B_Name::operator <(const B_Name& rhs) const {
    // TODO Implement

    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003C70
* VC++ mangling:          ??YB_Name@@QAEABV0@PBD@Z
*/

B_Name const& B_Name::operator +=(const char* str) {
    // TODO Implement
    return *this;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003D30
* VC++ mangling:          ??YB_Name@@QAEABV0@D@Z
*/

const B_Name& B_Name::operator+=(char c) {
    // TODO Implement
    return *this;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003DCE
* VC++ mangling:          ??YB_Name@@QAEABV0@ABV0@@Z
*/

B_Name const& B_Name::operator +=(const B_Name& other) {
    // TODO Implement
    return *this;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003BC7
* VC++ mangling:          ??H@YA?AVB_Name@@PBDABV0@@Z
*/

B_Name operator +(const char* str, const B_Name& bName) {
    B_Name result = bName; // Create a copy of bName
    result += str; // Append the string to the copy
    return result;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003B1E
* VC++ mangling:          ??H@YA?AVB_Name@@ABV0@PBD@Z
*/

B_Name operator+(B_Name const& other, char const* str) {
    // TODO Implement
    return other;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003A70
* VC++ mangling:          ??H@YA?AVB_Name@@ABV0@0@Z
*/

B_Name operator+(B_Name const& lother, B_Name const& rother) {
    // TODO Implement
    return lother;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003898
* VC++ mangling:          ?Left@B_Name@@QBE?AV1@I@Z
*/

B_Name B_Name::Left(unsigned int count) const {
    if (count > len) {
        count = len;
    }

    B_Name result(count);
    strncpy(result.string, string, count);
    return result;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003821
* VC++ mangling:          ?Right@B_Name@@QBE?AV1@I@Z
*/

B_Name B_Name::Right(unsigned int count) const {
    if (count > len) {
        count = len;
    }

    B_Name result(count);
    strncpy(result.string, string + (len - count), count);
    return result;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003E91
* VC++ mangling:          ?UpCase@B_Name@@QAEXXZ
*/

void B_Name::UpCase() {
    char* str = string;
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}
