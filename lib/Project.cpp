#include "Project.hpp"
#include <fstream>
#include <string>
#include <utility>

Project::Project(std::string name): name(std::move(name)) {}
Project::~Project() {
    std::ofstream output("generated.cmake");

    output << "project(\"" << name << "\")";

    output.close();
}

void Project::setName(std::string newName) {
    name = std::move(newName);
}