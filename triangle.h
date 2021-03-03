//
// Created by Euraba on 03.03.2021.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>

struct Point {
    int x, y ;

    Point() {
        this -> x = this -> y = 0 ;
    }

    Point(int _x, int _y) {
        this ->x = _x ;
        this ->y = _y ;
    }

    bool operator < (const Point &aux) const {
        double angle = -atan2(this -> x, -this ->y) ;
        double auxAngle = -atan2(aux.x, -aux.y) ;
        return angle < auxAngle ;
    }

};

class Triangle {
public :
    Point A, B, C ;

    Triangle() {
        this -> A = this -> B = this -> C = Point() ;
    }

    Triangle(Point _A, Point _B, Point _C) {
        this -> A = _A ;
        this -> B = _B ;
        this -> C = _C ;
    }

    double Area() {
        double ret(0) ;

        ret += A.x * B.y - A.y * B.x ;
        ret += B.x * C.y - B.y * C.x ;
        ret += C.x * A.y - C.y * A.x ;

        ret = std::abs(ret) ;
        ret = ret / 2.00 ;

        return ret ;
    }

    bool isPointInside(const Point fountain) {
        Triangle aux = Triangle(A, B, C) ;
        double currentArea = aux.Area() ;
        double retArea(0) ;
        Triangle newT ;

        newT = Triangle(aux.A, aux.B, fountain) ;
        retArea += newT.Area() ;

        newT = Triangle(aux.C, aux.B, fountain) ;
        retArea += newT.Area() ;

        newT = Triangle(aux.A, aux.C, fountain) ;
        retArea += newT.Area() ;

        return currentArea == retArea ;
    }
};


#endif //TRIANGLE_H
