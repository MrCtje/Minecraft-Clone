#include "util/string_util.h"

namespace util{
    std::vector<std::string>& split(const std::string& s, char delim, std::vector<std::string>& elems){
        std::stringstream sstream(s);
        std::string item;
        while(std::getline(sstream, item, delim)){
            if(item != "")
            elems.push_back(item);
        }
        return elems;
    }

    std::vector<std::string> split(const std::string& s, char delim){
        std::vector<std::string> elems;
        util::split(s,delim,elems);
        return elems;
    }
}

