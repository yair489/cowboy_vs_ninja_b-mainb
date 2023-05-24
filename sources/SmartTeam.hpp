#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include "Team.hpp"

#include <iostream>
#include <vector>

namespace ariel {
    class SmartTeam: public Team{
        private:
        public:
            // constructor and destructor
            SmartTeam();
            SmartTeam(Character* leader);
            ~SmartTeam() override = default;

            // Inside the Point class declaration
SmartTeam(const SmartTeam& other) = default;
SmartTeam& operator=(const SmartTeam& other) = default;
SmartTeam(SmartTeam&& other) = default;
SmartTeam& operator=(SmartTeam&& other) = default;

            // member functions
            void attack(Team* enemyTeam) ;
    };
}

#endif
