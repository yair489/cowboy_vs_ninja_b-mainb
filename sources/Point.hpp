#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

namespace ariel {
    //  class point 
    class Point {
    private:
        double _x; 
        double _y;
    
    public:

        /*Constructor*/
        Point();//: _x(0.0), _y(0.0) {}
        Point(double xxxxx, double yyyyyyyy);//: _x(xxxxx), _y(yyyyyyyy){}
        ~Point(){}
        
        // Inside the Point class declaration
Point(const Point& other) = default;
Point& operator=(const Point& other) = default;
Point(Point&& other) = default;
Point& operator=(Point&& other) = default;



        double distance(const Point& other) const;
        std::string print() const;
        static Point moveTowards(const Point &source, const Point &target, double distance);

        /*getters*/
        double getX() const{
         return this->_x;
        }
        double getY() const{
            return this->_y;
        }


    };
}

#endif
