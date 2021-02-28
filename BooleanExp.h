//
// Created by Eusebiu Rares on 28.02.2021.
//

#ifndef LOGIC_BOOLEANEXP_H
#define LOGIC_BOOLEANEXP_H

#include <string>
#include <bitset>

class BooleanExp {
private :
    static const int SIGMA = 26 ;
    std::string exp ;
    std::bitset<1 + SIGMA> upd ;
    int point ;
    char currentChar() {
        while (exp[point] == ' ') {
            advance() ;
        }
        return exp[point] ;
    }
    void advance() {
        point ++ ;
    }
    char notSign, BASE ;

public :
    __attribute__ ( (always_inline)) BooleanExp(std::string aux) {
        exp = aux ;
        point = 0 ;
        /// Change the NOT sign here
        notSign = '~' ;
        /// it does not work with both upper and lower at the same time
        BASE = 'a' ;
    }

    void reset(int pos = 0) {
        this ->point = pos ;
    }

    bool evaluate() {
        bool currVal = xorFactor() ;
        while (currentChar() == '|') {
            advance() ;
            currVal |= xorFactor() ;
            //advance() ;
        }
        reset() ;
        return currVal ;
    }

    bool xorFactor() {
        bool currVal = andFactor() ;
        while (currentChar() == '^') {
            advance() ;
            currVal ^= andFactor() ;
            //advance() ;
        }
        return currVal ;
    }

    bool andFactor() {
        bool currVal = notFactor() ;
        while (currentChar() == '&') {
            advance() ;
            currVal &= notFactor() ;
            //advance() ;
        }
        return currVal ;
    }

    bool notFactor() {
        bool currVal ;
        if (currentChar() == '(') {
            advance() ;
            currVal = evaluate() ;
            advance() ;
        } else {
            if (currentChar() == '0') {
                advance() ;
                currVal = 0 ;
            } else if (currentChar() == '1') {
                advance() ;
                currVal = 1 ;
            } else if (currentChar() == notSign) {
                advance() ;
                currVal = !notFactor() ;
            } else {
                currVal = upd[currentChar() - BASE] ;
                advance() ;
            }
        }
        return currVal ;
    }

    void update(char let, bool value) {
        upd[let - BASE] = value ;
    }
};


#endif //LOGIC_BOOLEANEXP_H
