#include "include/CppMake/Application.hpp"
#include "CppMake/Utils.hpp"

Application::Application(const std::string& name): LocalTarget(name) {}
Application::Application(const std::string& name, const std::vector<std::string>& sources): ITarget(name), sources(sources) {}

void Application::generate(Generator& stream) const
{
    stream.putLine("add_executable({name})", { { "name", name } });


    if (!sources.empty())
    {
        std::vector<std::string> s;
        for (const auto& source: sources)
            s.push_back("\"" + source + "\"");

        stream.putLine("target_sources({name} PRIVATE {sources})", {
            { "name", name },
            { "sources", join(s, " ") }
        });
    }
}

Application& Application::addSources(const std::vector<std::string>& newSources)
{
    for (const auto& source: newSources)
        sources.push_back(source);

    return *this;
}