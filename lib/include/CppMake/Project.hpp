#pragma once
#ifndef CPPMAKE_PROJECT_GUARD
#define CPPMAKE_PROJECT_GUARD

#include <string>
#include <vector>
#include <memory>
#include <concepts>
#include "Target.hpp"

class Project
{
private:
    std::string name;
    std::vector<std::unique_ptr<ITarget>> targets;
    std::vector<std::unique_ptr<PackageImport>> imports;
public:
    explicit Project(const std::string& name);
    ~Project();

    void setName(std::string name);

    ITarget& addTarget(std::unique_ptr<ITarget>&& target);
    template<std::derived_from<ITarget> T> T& add(std::unique_ptr<T>&& target)
    {
        return dynamic_cast<T&>(addTarget(std::move(target)));
    }
    template<std::derived_from<ITarget> T, typename... Args> T& create(Args&&... args)
    {
        return add<T>(std::move(std::make_unique<T>(std::forward<Args>(args)...)));
    }
    PackageImport& require(const std::string& name, bool modernPackage = true);
};

#endif