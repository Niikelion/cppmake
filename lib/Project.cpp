#include <fstream>
#include <string>
#include <utility>

#include "include/CppMake/Project.hpp"
#include "CppMake/Generator.hpp"

Project::Project(const std::string& name): name(name) {}
Project::~Project() {
    Generator generator = Generator{ "generated.cmake" };

    generator.putLine(R"(project({name}))", { { "name", name } });

    for (const auto& package: imports)
        package->generate(generator);

    for (const auto& target: targets)
        target->generate(generator);
}

void Project::setName(std::string newName) {
    name = std::move(newName);
}

ITarget& Project::addTarget(std::unique_ptr<ITarget> &&target)
{
    targets.emplace_back(std::move(target));
    return *targets.back();
}
PackageImport& Project::require(const std::string& packageName, bool modernPackage)
{
    imports.emplace_back(std::move(std::make_unique<PackageImport>(packageName, modernPackage)));
}