#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <vector>

#include "srtextract.h">

int main(int argc, char* argv[])
{
    if (argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
        std::cout << "Usage: srtextr [command] [argument]\n\n"
                  << "Commands:\n"
                  << "\tread\t" << "read lines from [argument] file to _eng.temp file\n"
                  << "\twrite\t" << "write from _rus.temp file to _rus.srt file\n\n"
                  << "Arguments:\n"
                  << "\tFILE_NAME.srt\t" << "path to .srt file\n";

    }
    else if (argc == 3 && !strcmp(argv[1], "read")) {
        std::cout << "Starting to extract lines from srt file - "
                  << argv[2] << std::endl;
        SrtReader reader(argv[2]);
        SrtLine line;

        std::string filename;
        SrtReader::renameFile(filename, argv[2], "_eng.temp");
        std::ofstream out(filename);

        while (reader >> line)
        out << "#" << line;

        std::string tempfilename;
        SrtReader::renameFile(tempfilename, argv[2], "_rus.temp");
        std::ofstream tempEmptyFile(tempfilename);
        tempEmptyFile.close();
    }
    else if (argc == 3 && !strcmp(argv[1], "write")) {
        std::cout << "Starting to create srt file from lines for file - "
                  << argv[2] << std::endl;
        SrtReader reader(argv[2]);

        std::string tempfilename;
        SrtReader::renameFile(tempfilename, argv[2], "_rus.temp");
        TempReader tempReader(tempfilename);

        std::string srtfilename;
        SrtReader::renameFile(srtfilename, argv[2], "_rus.srt");
        std::ofstream out(srtfilename);

        SrtExtLine line;
        while (reader >> line && tempReader >> line) out << line;
    }
    else {
        std::cout << "Wrong arguments!" << std::endl;
        return 1;
    }

    std::cout << "Creation is done" << std::endl;;
    return 0;
}
