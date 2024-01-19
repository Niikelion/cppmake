#ifndef CPPMAKE_TARGET_GUARD
#define CPPMAKE_TARGET_GUARD

#include <iostream>
#include <string>

class ITarget {
protected:
    std::string name;
public:
    ITarget(const std::string& name);

    void setName(const std::string& name);
    virtual void generate(std::ostream& stream) const = 0;
};

#endif