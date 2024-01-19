#ifndef CPPMAKE_APP_GUARD
#define CPPMAKE_APP_GUARD

#include <vector>
#include "CppMake/Target.hpp"

class Application: public ITarget
{
private:
    std::vector<std::string> sources;
public:
    Application(const std::string& name);
    Application(const std::string& name, const std::vector<std::string>& sources);

    void generate(std::ostream &stream) const override;
    Application& addSources(const std::vector<std::string>& sources);
};

#endif