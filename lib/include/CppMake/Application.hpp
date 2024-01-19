#ifndef CPPMAKE_APP_GUARD
#define CPPMAKE_APP_GUARD

#include <vector>
#include "Target.hpp"

class Application: public LocalTarget
{
private:
    std::vector<std::string> sources;
public:
    Application(const std::string& name);
    Application(const std::string& name, const std::vector<std::string>& sources);

    void generate(Generator &stream) const override;
    Application& addSources(const std::vector<std::string>& sources);
};

#endif