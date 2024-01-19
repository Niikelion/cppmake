#include "include/CppMake/Target.hpp"

ITarget::ITarget(const std::string& name): name(name) {}
ITarget::~ITarget() = default;
void ITarget::setName(const std::string& newName)
{
    name = newName;
}
const std::string& ITarget::getName() const
{
    return name;
}

void ImportedTarget::generate(Generator &stream) const {}

PackageImport::PackageImport(const std::string& name, bool modernPackage): name(name), modernPackage(modernPackage) {}
void PackageImport::generate(Generator &stream) const
{
    stream.putLine("find_package(REQUIRED {config})", { { "config", modernPackage ? "CONFIG" : "" } });
}
ImportedTarget& PackageImport::target(const std::string &targetName, bool prefixWithPackage)
{
    targets.emplace_back(std::move(std::make_unique<ImportedTarget>(prefixWithPackage ? name + "::" + targetName : targetName)));
}