#ifndef TEAM_HPP
#define TEAM_HPP

#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"

#include <iostream>
#include <vector>
#include <limits>

namespace ariel
{
    class Team
    {
    private:
        Character *_leader;
        std::vector<Character *> list_s;
    public:
        
        // constructor and destructor
        Team() : _leader(nullptr) {}
        Team(Character *leader) : _leader(leader){
            if (leader->getIsLeader() || this->_leader == nullptr){
                throw std::runtime_error("already leader");}
            leader->setIsLeader();
            this->list_s.push_back(leader);
        }
        
        virtual ~Team()
        {
            for (Character *fighter : list_s)
            {
                delete fighter;
            }
        }
// Inside the Point class declaration
Team(const Team& other) = default;
Team& operator=(const Team& other) = default;
Team(Team&& other) = default;
Team& operator=(Team&& other) = default;

       
        Character *find_t(Team *enemyTeam);

        // member functions

        /*get ninja or cowboy and add them to the group*/
        void add(Character *fighter);
        void attack(Team *enemyTeam);
        int stillAlive();
        void print();

        void setLeader(Character *new_leader)
        {
            this->_leader = new_leader;
        }

        Character *getLeader() const
        {
            return this->_leader;
        }
        std::vector<Character*>& getlist_s()  {
        return list_s;
    }
    };
}

#endif
