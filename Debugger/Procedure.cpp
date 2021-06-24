#include "Procedure.h"

Procedure::Procedure()
{
}

Procedure::Procedure(
    const std::string& dll, const std::string& name, bool isSystem)
    :
    dll(dll), name(name), isSystem(isSystem)
{
}

std::string Procedure::Dll() const
{
    return dll;
}

std::string Procedure::FullName() const
{
    return dll + "!" + name;
}

bool Procedure::IsSystem() const
{
    return isSystem;
}
