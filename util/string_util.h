#ifndef STRING_UTIL_H
#define STRING_UTIL_H
#include <string>
#include <vector>
#include <sstream>

namespace util {
    std::vector<std::string>& split(const std::string& s, char delim, std::vector<std::string>& elems);
    std::vector<std::string> split(const std::string& s, char delim);
}

#endif // STRING_UTIL_H
