#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <iostream>

namespace ariel
{

    class Character
    {
        // protected:
    private:
        Point location;
        std::string name;
        int alive_Point;
        bool in_group = false;
        bool isLeader = false;

    public:
        // Constructor  Destructor

        Character(std::string name, const Point &location, int hit_point);// : name(name), location(location), alive_Point(hit_point) {}
        Character();// : name("yair"), location(Point(0,0)), alive_Point(0) {}
        virtual ~Character() {}
        //  Character(Character&& ) noexcept;
        // Character& operator = (Character&&) noexcept;

        // Inside the Point class declaration
Character(const Character& other) = default;
Character& operator=(const Character& other) = default;
Character(Character&& other) = default;
Character& operator=(Character&& other) = default;



        /* func */
        std::string print();
        bool isAlive() const;
        double distance(Character *other);
        void hit(int num);

        /*getters and setters */

        int getHitPoints() const//demo
        {
            return alive_Point;
        }

        std::string getName() const
        {
            return name;
        }

        const Point &getLocation() const
        {
            return location;
        }

        void changeLocation(Point const &other)
        {
            location = other;
        }

        bool getInGroup() const
        {
            return in_group;
        }

        void setInGroup()
        {
            in_group = true;
        }

        bool getIsLeader() const
        {
            return isLeader;
        }

        void setIsLeader()
        {
            isLeader = true;
        }

    };
}

#endif
