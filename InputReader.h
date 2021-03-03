#ifndef InputReader_H
#define InputReader_H

#include <cstdio>

template <typename T>
class InputReader {
private:
    FILE *input_file ;
    static const int SIZE = (1 << 17) ;
    int point ;
    char buffer[SIZE] ;
    __attribute__ ( (always_inline)) void advance() {
        ++ point ;
        if (point == SIZE) {
            point = 0 ;
            fread (buffer, SIZE, 1, input_file) ;
        }
    }
public:
    InputReader() {}
    InputReader (const char *file_name) {
        input_file = fopen (file_name, "r") ;
        point = 0 ;
        fread (buffer, SIZE, 1, input_file) ;
    }
    __attribute__ ( (always_inline)) InputReader &operator >> (T &n) {
        for (; !isdigit (buffer[point]) ; advance()) ;
        n = 0 ;
        for (; isdigit (buffer[point]) ; advance()) {
            n = n * 10 + buffer[point] - '0' ;
        }
        return *this ;
    }
} ;

#endif //UNTITLED1_LIBRARY_H
