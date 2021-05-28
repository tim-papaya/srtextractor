#ifndef SRTREADER_H
#define SRTREADER_H

#include <fstream>
#include <string>

class CharSeq
{
    const char* m_seq;
    int size;
    int count;
public:
    CharSeq(const char* seq, int size)
        : m_seq(seq), size(size), count(0) {}
    bool operator()(char &val)
    {
        if (m_seq[count] == val) count++;
        else count = 0;
        if (count == size) return true;
        return false;
    }
};

struct SrtLine
{
    unsigned number;
    std::string text;

    friend std::ostream& operator<<(std::ostream& stream, const SrtLine &line);
};

struct SrtExtLine : SrtLine
{
    std::string lineStart;
    std::string lineEnd;
    std::string translated;

    friend std::ostream& operator<<(std::ostream& stream, const SrtExtLine &line);
};

class SrtReader
{
    std::ifstream m_file;

public:
    SrtReader(const char *fileName) : m_file(fileName) {}
    ~SrtReader() { if (m_file) m_file.close(); }

    operator bool() { return m_file.is_open() && !m_file.eof(); }

    friend SrtReader& operator>>(SrtReader& reader, SrtLine &line);
    friend SrtReader& operator>>(SrtReader& reader, SrtExtLine &line);

    static void renameFile(std::string &fileName, const char* old, const char* postfix);

private:
    void readRawLine(std::string &str);
};

class TempReader
{
    std::ifstream m_file;

public:
    TempReader(const char *fileName) : m_file(fileName) {}
    ~TempReader() { if (m_file) m_file.close(); }

    operator bool() { return m_file.is_open() && !m_file.eof(); }

    friend TempReader& operator>>(TempReader& reader, SrtExtLine &line);
};

#endif // SRTREADER_H
