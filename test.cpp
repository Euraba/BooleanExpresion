#include <iostream>
#include "BooleanExp.h"

int main() {
    BooleanExp example("a|b&c") ;
    example.update('a', 1) ;
    example.update('b', 1) ;
    example.update('c', 0) ;
    bool eval = example.evaluate() ;
    std::cout << eval ;
}
