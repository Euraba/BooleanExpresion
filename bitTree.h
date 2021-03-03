//
// Created by Euraba on 03.03.2021.
//

#ifndef TURNURI4_BITTREE_H
#define TURNURI4_BITTREE_H


#include <vector>

template <typename T>
class bitTree {
private :
    std::vector<T> aib ;
    static const int MAXVAL = (1 << 30) ;
    int sz ;
public :
    __attribute__ ( (always_inline)) bitTree (int _ = 0) {
        this ->sz = _ ;
        aib.resize (sz + 1) ;
    }
    __attribute__ ( (always_inline)) void update (int poz, T val) {
        for (int i = poz ; i <= sz ; i += (i & (-i))) {
            aib.at (i) += val ;
        }
    }
    __attribute__ ( (always_inline)) int query (int poz) {
        T ret (0) ;
        for (int i = poz ; i > 0 ; i -= (i & (-i))) {
            ret += (T)aib.at (i) ;
        }
        return ret ;
    }
    __attribute__ ( (always_inline)) int BinarySearch (T val) {
        int ret (0) ;
        for (int step (MAXVAL) ; step ; step >>= 1) {
            if (ret + step <= sz && aib[ret + step] <= val) {
                val -= aib.at (ret + step) ;
                ret |= step ;
            }
        }
        if (!val) {
            return ret ;
        }
        return -1 ;
    }
};


#endif //TURNURI4_BITTREE_H
