#include "CppMake/Target.hpp"

ITarget::ITarget(const std::string& name): name(name) {}
void ITarget::setName(const std::string& newName)
{
    name = std::move(newName);
}