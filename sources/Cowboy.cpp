#include "Cowboy.hpp"

using namespace ariel;
Cowboy::Cowboy() : Character("yair", Point(), 110), shooting_bullets(6) {}
        Cowboy::Cowboy(std::string name, const Point &location) : Character(name, location, 110), shooting_bullets(6) {}

void Cowboy::shoot(Character* enemy){
    if(!enemy->isAlive() || !this->isAlive() || this == enemy){ 
        throw std::runtime_error("eror");
    }
    if(this->isAlive()) {
        if (this->hasboolets()) { 
            enemy->hit(10); 
            this->shooting_bullets-=1; 
        }
    }
}

void Cowboy::reload(){
    if(!isAlive()){
        throw std::runtime_error("cowboy dead");
    }
    this->shooting_bullets =6;
}
bool Cowboy::hasboolets() const {
    if (shooting_bullets >0)
        return true;
    return false;
}

std::string Cowboy::print() {
    return "C: " +Character::print();
}



