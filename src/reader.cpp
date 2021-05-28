#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstring>

#include "srtreader.h">

int main(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++)
    {
        SrtReader reader(argv[i]);
        std::cout << reader << std::endl;

        SrtLine line;
        std::string filename;
        SrtReader::renameFile(filename, argv[i], "_eng.temp");
        std::ofstream out(filename);
        while (reader >> line)
        out << "#" << line;
    }
    return 0;
}
