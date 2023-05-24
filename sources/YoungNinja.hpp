#ifndef YOUNG_NINJA_HPP
#define YOUNG_NINJA_HPP

#include "Ninja.hpp"
#include <iostream>

namespace ariel {
    class YoungNinja : public Ninja{
        private:
        public:
            YoungNinja();
            YoungNinja(std::string name, Point location);
            ~YoungNinja() override;

            // Inside the Point class declaration
YoungNinja(const YoungNinja& other) = default;
YoungNinja& operator=(const YoungNinja& other) = default;
YoungNinja(YoungNinja&& other) = default;
YoungNinja& operator=(YoungNinja&& other) = default;

    };
}

#endif
