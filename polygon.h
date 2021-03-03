//
// Created by Euraba on 03.03.2021.
//

#ifndef POLYGON_H
#define POLYGON_H


#include <vector>
#include <iostream>

struct Point {
    int x, y ;
    Point() {} ;
    Point(int _x, int _y) {
        this ->x = _x ;
        this ->y = _y ;
    }

    bool operator == (const Point & aux) {
        return (this ->x == aux.x && this ->y == aux.y) ;
    }

    bool operator != (const Point &aux) {
        return !(*this == aux) ;
    }
};

class Polygon {
private :
    std::vector<Point> points ;
    int orientation ;
public :
    Polygon(const std::vector <Point> &points) : points(points) {}

    int area() {
        int ret(0) ;
        for (int i = 0 ; i < points.size() ; ++ i) {
            ret += (points[i].x * points[i + 1].y) - (points[i].y * points[i + 1].x) ;
        }
        if (ret < 0) {
            orientation = 0 ;
            ret *= -1 ;
        } else orientation = 1 ;
        return ret / 2 ;
    }

    void add(Point aux) {
        points.push_back(aux) ;
    }

    void complete() {
        if (points.back() != points.front()) {
            points.push_back(points[0]) ;
        }
    }

    int getOrientation() {
        return orientation ;
    }

    void debug() {
        for (auto it : points) {
            std::cerr << it.x << ' ' << it.y << '\n' ;
        }
    }

};


#endif POLYGON_H
