#ifndef COLORO_H
#define COLORO_H

#include <cstring>
#include <string>
namespace colord{

    enum foreground_color{
        Black = 30,
        Red = 31,
        Green = 32,
        Yellow = 33,
        Blue = 34,
        Magenta = 35,
        Cyan = 36,
        White = 37
    };

//    friend ostream& operator << (ostream& out, ){

//    }

    std::string getColoredOutput(foreground_color color){
        std::string output("\033[");
        output.append(std::to_string(color));
        output.append("m");
        return output;
    }

    std::string resetAttributes(){
        return "\033[0m";
    }



}

#endif // COLORO_H


