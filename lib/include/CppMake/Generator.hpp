#ifndef CPPMAKE_GENERATOR_GUARD
#define CPPMAKE_GENERATOR_GUARD

#include <string>
#include <fstream>
#include <map>

class Generator
{
private:
    std::ofstream output;
    bool insertNewLine;
public:
    explicit Generator(const std::string& outputFile);
    ~Generator();

    std::ostream& raw();

    Generator& putString(const std::string& str);
    Generator& putString(const std::string& str, const std::map<std::string, std::string>& vars);
    inline Generator& putLine(const std::string& line)
    {
        putString(line);
        insertNewLine = true;
        return *this;
    }
    inline Generator& putLine(const std::string& line, const std::map<std::string, std::string>& vars)
    {
        putString(line, vars);
        insertNewLine = true;
        return *this;
    }
};

#endif