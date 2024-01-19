#pragma once
#ifndef CPPMAKE_PROJECT_GUARD
#define CPPMAKE_PROJECT_GUARD

#include "string"

class Project
{
private:
    std::string name;
public:
    Project(std::string name);
    ~Project();

    void setName(std::string name);
};

#endif