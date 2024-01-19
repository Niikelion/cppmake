#include "CppMake/Application.hpp"

Application::Application(const std::string& name): ITarget(name) {}
Application::Application(const std::string& name, const std::vector<std::string>& sources): ITarget(name), sources(sources) {}

void Application::generate(std::ostream& stream) const
{
    stream << "add_executable(" << name << ")\n";

    if (!sources.empty())
    {
        stream << "target_sources(" << name << " PRIVATE\n";
        for (const auto& source: sources)
            stream << "\"" << source << "\"\n";
        stream << ")\n";
    }
}

Application& Application::addSources(const std::vector<std::string>& newSources)
{
    for (const auto& source: newSources)
        sources.push_back(source);

    return *this;
}