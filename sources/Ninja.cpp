#include "Ninja.hpp"

using namespace ariel;
// using namespace std::;
 Ninja::Ninja():  speed(0){}
 Ninja::Ninja(std::string name, const Point& location, int hit_point, int speed): Character(name, location, hit_point) , speed(speed){}
void Ninja::move(const Character* enemy) {
    changeLocation(Point::moveTowards(getLocation(), enemy->getLocation(), getSpeed()));
}

void Ninja::slash(Character* enemy) {
    if (!enemy->isAlive() || !isAlive() ||this == enemy)
        throw std::runtime_error("enemy is dead");

    if (isAlive()) {
        double distance = getLocation().distance(enemy->getLocation());
        if (distance <= 1)
            enemy->hit(40);
    }
}

std::string Ninja::print() {
    return "N:" + Character::print();
}