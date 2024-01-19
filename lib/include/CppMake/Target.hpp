#ifndef CPPMAKE_TARGET_GUARD
#define CPPMAKE_TARGET_GUARD

#include <string>
#include <memory>
#include <vector>
#include "CppMake/Generator.hpp"

class ITarget {
protected:
    std::string name;
public:
    explicit ITarget(const std::string& name);
    virtual ~ITarget();

    void setName(const std::string& name);
    [[nodiscard]] const std::string& getName() const;
    virtual void generate(Generator& stream) const = 0;
};

enum LinkType
{
    Public,
    Private,
    Interface
};

template<typename T>class LocalTarget: public ITarget {
private:
    std::map<std::string, std::vector<const ITarget*>> linkedTargets;
public:
    using ITarget::ITarget;

    T& link(const ITarget& target, LinkType type = LinkType::Private)
    {
        std::string t;
        switch (type) {
            case LinkType::Private: t="PRIVATE"; break;
            case LinkType::Public: t="PUBLIC"; break;
            case LinkType::Interface: t="INTERFACE"; break;
        }

        if (!linkedTargets.contains(t))
        {
            linkedTargets.emplace(t, std::vector<const ITarget*>{});
        }

        linkedTargets[t].emplace_back(&target);

        return *dynamic_cast<T*>(this);
    }
};

class ImportedTarget: public ITarget
{
public:
    using ITarget::ITarget;

    void generate(Generator& stream) const override;
};

class PackageImport
{
private:
    std::string name;
    bool modernPackage;
    std::vector<std::unique_ptr<ImportedTarget>> targets;
public:
    PackageImport(const std::string& name, bool modernPackage);

    void generate(Generator& stream) const;
    ImportedTarget& target(const std::string& name, bool prefixWithPackage = true);
};

#endif