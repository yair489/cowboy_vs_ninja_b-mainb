#include "Character.hpp"

using namespace ariel;

  Character::Character(std::string name, const Point &location, int hit_point) : name(name), location(location), alive_Point(hit_point) {}
         Character::Character() : name("yair"), location(Point(0,0)), alive_Point(0) {}
bool Character::isAlive() const {
    return getHitPoints() > 0;
}

double Character::distance(Character* other) {
    return getLocation().distance(other->getLocation());
}

void Character::hit(int hurt) {
    if (hurt < 0) {
        throw std::invalid_argument("Cannot hit below 0.");
    }
    alive_Point -= hurt;
}

std::string Character::print() {
    std::string msg;
    if (isAlive()) {
        msg = "Name: " + getName() + ". Life Points: " + std::to_string(getHitPoints()) + ". Location: " + getLocation().print();
    } else {
        msg = "(" + getName() + ")";
    }
    return msg;
}