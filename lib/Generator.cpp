#include "CppMake/Generator.hpp"
#include "CppMake/Utils.hpp"

Generator::Generator(const std::string &outputFile): output(outputFile), insertNewLine(false) {}
Generator::~Generator()
{
    output.close();
}
std::ostream& Generator::raw()
{
    return output;
}
Generator& Generator::putString(const std::string& str)
{
    if (insertNewLine)
    {
        insertNewLine = false;
        output << std::endl;
    }
    output << str;
    return *this;
}
Generator& Generator::putString(const std::string& str, const std::map<std::string, std::string>& vars)
{
    std::string strCpy = str;
    for (const auto& mapping: vars)
        replace(strCpy, "{"+mapping.first+"}", mapping.second);
    return putString(strCpy);
}