//
// Created by Euraba on 03.03.2021.
//

#ifndef OUTPARSING_H
#define OUTPARSING_H


#include <ios>
#include <fstream>

class OutputParsing {
public:
    OutputParsing() {} ;

    OutputParsing(const char * file_name) {
        output_file.open(file_name, std::ios::out | std::ios::binary) ;
        output_file.sync_with_stdio(false) ;
        index = 0 ;
    }

    inline OutputParsing & operator << (int target) {
        aux = 0 ;
        n = target ;
        target < 0 ? sign = -1 : sign = 1 ;
        if (!n) {
            nr[aux ++] = '0' ;
        }
        for ( ; n ; n /= 10) {
            nr[aux ++] = sign * (n % 10) + '0' ;
        }
        if (sign == -1) {
            buffer[index] = '-' ;
            inc() ;
        }
        for ( ; aux ; inc())
            buffer[index] = nr[-- aux] ;
        return *this ;
    }

    inline OutputParsing & operator << (const char * target) {
        aux = 0 ;
        while (target[aux]) {
            buffer[index] = target[aux ++] ;
            inc() ;
        }
        return *this ;
    }
    ~OutputParsing() {
        output_file.write(buffer, index) ;
        output_file.close() ;
    }

private:
    std::fstream output_file;
    static const int SIZE = 0x200000;
    int index = 0, aux, n, sign;
    char buffer[SIZE], nr[24];

    inline void inc() {
        if (++index == SIZE) {
            index = 0 ;
            output_file.write(buffer, SIZE);
        }
    }
} ;


#endif //OUTPARSING_H
