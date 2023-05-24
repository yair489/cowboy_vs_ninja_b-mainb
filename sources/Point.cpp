#include "Point.hpp"
#include "cmath"
#include <vector>

using namespace ariel;

 Point::Point(): _x(0.0), _y(0.0) {}
        Point::Point(double xxxxx, double yyyyyyyy): _x(xxxxx), _y(yyyyyyyy){}
double Point::distance(const Point& other) const{
    double dx = getX() - other.getX();
    double dy = getY() - other.getY();
    return sqrt(dx*dx + dy*dy);
}


std::string Point::print() const{
    return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")" ;
}


Point Point::moveTowards(const Point &source, const Point &target, double distance)
{
    if(distance <0){
         throw std::invalid_argument("must be positive."); 
    }

    double dx = target._x - source._x;
    double dy = target._y - source._y;
    double dist = std::sqrt(dx * dx + dy * dy);
    if (dist <= distance)
    {
        return target; // target is already reachable
    }
    double k = distance / dist;
    double x = source._x + dx * k;
    double y = source._y + dy * k;
    return Point(x, y);
}
