#include "srtreader.h"
#include "algorithm"


SrtReader& operator>>(SrtReader& reader, SrtLine &line)
{
    if(!(reader.m_file >> line.number)) return reader;

    std::string temp;
    reader.readRawLine(temp);
    auto ending = std::find_if(temp.begin(), temp.end(), CharSeq("</", 2));
    int index = temp.size() - (--ending - temp.begin());
    auto starting = std::find(temp.rbegin() + index, temp.rend(), '>');

    line.text.resize(ending - starting.base());
    std::copy(starting.base(), ending, line.text.begin());
    return reader;
}

SrtReader& operator>>(SrtReader& reader, SrtExtLine &line)
{
    if(!(reader.m_file >> line.number)) return reader;

    std::string temp;
    reader.readRawLine(temp);
    auto ending = std::find_if(temp.begin(), temp.end(), CharSeq("</", 2));
    int index = temp.size() - (--ending - temp.begin());
    auto starting = std::find(temp.rbegin() + index, temp.rend(), '>');

    line.text.resize(ending - starting.base());
    std::copy(starting.base(), ending, line.text.begin());

    line.lineStart.resize(starting.base() - temp.begin());
    std::copy(temp.begin(), starting.base(), line.lineStart.begin());

    line.lineEnd.resize(temp.end() - ending);
    std::copy(ending, temp.end(), line.lineEnd.begin());

    return reader;
}


std::ostream& operator<<(std::ostream& stream, const SrtLine &line)
{
    stream << line.number << ' ' << line.text << std::endl;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const SrtExtLine &line)
{
    stream << line.lineStart << line.translated << line.text << line.lineEnd;
    return stream;
}
TempReader& operator>>(TempReader& reader, SrtExtLine &line)
{
    char ch;
    int number;
    reader.m_file >> ch >> number;

    line.translated.clear();
    while (reader.m_file.get(ch) && ch != '#')
        line.translated.push_back(ch);
    reader.m_file.unget();
    return reader;
}
void SrtReader::renameFile(std::string &fileName, const char *old, const char *postfix)
{
   fileName += old;
   fileName.resize(fileName.size() - 5);
   fileName += postfix;
}

void SrtReader::readRawLine(std::string &str)
{
    for (char ch; m_file.get(ch);) {
        str.push_back(ch);
        if (ch == '\n') {
            m_file.get(ch);
            if (ch == '\r')
            m_file.get(ch);
            if (ch == '\n') return;
            m_file.unget();
        }
    }
}
