// Курсовая работа
// bitstream.cpp
// Тимофеев Дмитрий, группа 6383
// 24.11.17
//
// Динамическое кодирование и декодирование по Хаффману

#include"bitstream.h"

const  char masks[8]={1,
                             2,
                             4,
                             8,
                             16,
                             32,
                             64,
                             (char)128};


 char BitInputStream::readBit(){
    if(ind>7){
        ind=0;
        is->read((char*)&buf,sizeof(buf));
    }
    return (masks[ind++]&buf)==0?0:1;
}

 char BitInputStream::readChar(){
     char res=0;
    for(int i=0;i<8;i++){
        res<<=1;
        res|=readBit();
    }
    return res;
}

void BitOutputStream::close(){
    if(ind!=0)os->write((const char*)&buf,sizeof(buf));
}

void BitOutputStream::writeBit( char byte){
    if(ind>7){
        ind=0;
        os->write((const char*)&buf,sizeof(buf));
        buf=0;
    }
    buf|=(byte<<(ind++));
}

void BitOutputStream::writeChar( char c){
    for(int i=7;i>=0;i--){
         char bit=((c&masks[i])==0)?0:1;
        writeBit(bit);
    }
}

