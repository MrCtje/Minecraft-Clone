#ifndef CONSOLEHEADER_H
#define CONSOLEHEADER_H

#include "coloro.h"
#include <string>

void printHeader(std::string text){
    int horizontalBorderSize = 46;
    int verticalBorderSize = 1;
    int length = text.size();
    int spaces = ceil((horizontalBorderSize - length - verticalBorderSize * 2) / 2);
    std::string spacesbuffer;
    spacesbuffer.reserve(spaces);
    spacesbuffer.replace(0,spaces,spaces,' ');

    std::cout << "##############################################"<<std::endl
         << "#" << spacesbuffer << text;

    std::cout << (spacesbuffer.size()+spaces+verticalBorderSize*2+length == horizontalBorderSize? spacesbuffer: spacesbuffer.append(" ")) << "#" << std::endl
         << "##############################################" << std::endl;
}

void printHeader(std::string text, colord::foreground_color color){
    int horizontalBorderSize = 46;
    int verticalBorderSize = 1;
    int length = text.size();
    int spaces = ceil((horizontalBorderSize - length - verticalBorderSize * 2) / 2);
    std::string spacesbuffer;
    spacesbuffer.reserve(spaces);
    spacesbuffer.replace(0,spaces,spaces,' ');

    std::cout << colord::getColoredOutput(color)
         << "##############################################"<< std::endl
         << "#" << spacesbuffer << text;

    std::cout << (spacesbuffer.size()+spaces+verticalBorderSize*2+length == horizontalBorderSize? spacesbuffer: spacesbuffer.append(" ")) << "#" << std::endl
         << "##############################################" << colord::resetAttributes() << std::endl;
}


#endif // CONSOLEHEADER_H
