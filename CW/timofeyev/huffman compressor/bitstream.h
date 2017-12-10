// Курсовая работа
// bitstream.h
// Тимофеев Дмитрий, группа 6383
// 24.11.17
//
// Динамическое кодирование и декодирование по Хаффману

#ifndef BITSTREAM
#define BITSTREAM

#include<istream>

class BitInputStream{
public:
    BitInputStream(std::istream &is){this->is=&is;}
     char readBit();
     char readChar();
private:
    std::istream *is;
    char buf;
    int ind=8;
};

class BitOutputStream{
public:
    BitOutputStream(std::ostream &os){this->os=&os;}
    void writeBit( char bit);
    void writeChar( char c);
    void close();

private:
    std::ostream *os;
    char buf=0;
    int ind=0;
};

#endif // BITSTREAM

