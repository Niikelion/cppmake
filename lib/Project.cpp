#include <fstream>
#include <string>
#include <utility>

#include "include/CppMake/Project.hpp"

Project::Project(const std::string& name): name(name) {}
Project::~Project() {
    std::ofstream output("generated.cmake");

    output << "project(\"" << name << "\")\n";

    for (const auto& target: targets)
        target->generate(output);

    output.close();
}

void Project::setName(std::string newName) {
    name = std::move(newName);
}

ITarget& Project::addTarget(std::unique_ptr<ITarget> &&target)
{
    targets.emplace_back(std::move(target));
    return *targets.back();
}