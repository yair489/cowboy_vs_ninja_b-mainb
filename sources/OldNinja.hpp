#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP

#include "Ninja.hpp"
#include <iostream>

namespace ariel {
    class OldNinja : public Ninja{
//        private:
        public:
            OldNinja();
            OldNinja(std::string name, const Point& location);
            ~OldNinja() override;

            // Inside the Point class declaration
OldNinja(const OldNinja& other) = default;
OldNinja& operator=(const OldNinja& other) = default;
OldNinja(OldNinja&& other) = default;
OldNinja& operator=(OldNinja&& other) = default;

    };
}

#endif
