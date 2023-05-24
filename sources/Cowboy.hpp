#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include <iostream>

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int shooting_bullets;

    public:
        Cowboy();// : Character("yair", Point(), 110), shooting_bullets(6) {}
        Cowboy(std::string name, const Point &location);// : Character(name, location, 110), shooting_bullets(6) {}
        ~Cowboy() override {}

// Inside the Point class declaration
Cowboy(const Cowboy& other) = default;
Cowboy& operator=(const Cowboy& other) = default;
Cowboy(Cowboy&& other) = default;
Cowboy& operator=(Cowboy&& other) = default;


        void shoot(Character *enemy);
        bool hasboolets() const;
        void reload();
        std::string print();

        int getBullet() const
        { // need to demo
            return this->shooting_bullets;
        }
    };
}

#endif
