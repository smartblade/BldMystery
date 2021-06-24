#pragma once

#include <string>

class Procedure
{
public:
    Procedure();
    Procedure(const std::string& dll, const std::string& name, bool isSystem);
    std::string Dll() const;
    std::string FullName() const;
    bool IsSystem() const;

private:
    std::string dll;
    std::string name;
    bool isSystem = true;
};

