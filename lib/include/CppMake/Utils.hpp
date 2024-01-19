#ifndef CPPMAKE_UTILS_GUARD
#define CPPMAKE_UTILS_GUARD

#include <string>
#include <sstream>

void replace(std::string& subject, const std::string& search, const std::string& replace);

template <typename I> std::string join(I begin, I end, const std::string& separator = ".")
{
    std::ostringstream o;
    if(begin != end)
    {
        o << *begin++;
        for(;begin != end; ++begin)
            o  << separator << *begin;
    }
    return o.str();
}
template <typename T> std::string join(const T& c, const std::string& separator = ".")
{
    using std::begin;
    using std::end;
    return join(begin(c), end(c), separator);
}

#endif
