#include <iostream>
#include "srtreader.h"

int main()
{
    SrtReader reader("/media/timin/DATA/Downloads/The.Venture.Bros.S01.2004.x264.DVDRip-SergeZuich/subs.srt");
    TempReader tempReader("/media/timin/DATA/Downloads/The.Venture.Bros.S01.2004.x264.DVDRip-SergeZuich/subs_rus.temp");

    SrtExtLine line;
    std::ofstream out("/media/timin/DATA/Downloads/The.Venture.Bros.S01.2004.x264.DVDRip-SergeZuich/subs_rus.srt");
    while (reader >> line && tempReader >> line) out << line;
    return 0;
}
