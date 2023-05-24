#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include <iostream>

namespace ariel {
    class Ninja : public Character{
        private:
            int speed; 
        public:
            Ninja();//:  speed(0){}
            Ninja(std::string name, const Point& location, int hit_point, int speed);//: Character(name, location, hit_point) , speed(speed){}
            ~Ninja() override{}
           
// Inside the Point class declaration
Ninja(const Ninja& other) = default;
Ninja& operator=(const Ninja& other) = default;
Ninja(Ninja&& other) = default;
Ninja& operator=(Ninja&& other) = default;

            void move(const Character* enemy);
            void slash(Character* enemy);
            std::string print();

            int getSpeed() const{
                return this->speed;
            }

    };
}

#endif
