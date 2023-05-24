#ifndef TRAINED_NINJA_HPP
#define TRAINED_NINJA_HPP

#include "Ninja.hpp"
#include <iostream>

namespace ariel {
    class TrainedNinja : public Ninja{
        private:
        public:
            TrainedNinja();
            TrainedNinja(std::string name, const Point& location);
            ~TrainedNinja() override = default;

            // Inside the Point class declaration
TrainedNinja(const TrainedNinja& other) = default;
TrainedNinja& operator=(const TrainedNinja& other) = default;
TrainedNinja(TrainedNinja&& other) = default;
TrainedNinja& operator=(TrainedNinja&& other) = default;

    };
}

#endif
