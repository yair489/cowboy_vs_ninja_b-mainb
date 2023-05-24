#include "Team.hpp"
using namespace ariel;

void Team::add(Character* soldier)
{
    if (soldier->getInGroup() || list_s.size() >= 10)
    {
        throw std::runtime_error("in team.");
    }

    if (dynamic_cast<Cowboy*>(soldier))
    {
        list_s.insert(list_s.begin(), soldier); // Insert Cowboy at the beginning
    }
    else if (dynamic_cast<Ninja*>(soldier))
    {
        list_s.push_back(soldier); // Insert Ninja at the end
    }

    soldier->setInGroup();
}

Character* Team::find_t(Team* enemyTeam)
{
    Character* closestEnemy = nullptr;
    double closestDistance = std::numeric_limits<double>::max();

    for (auto enemy : enemyTeam->list_s)
    {
        if (enemy->isAlive() && _leader->distance(enemy) < closestDistance)
        {
            closestEnemy = enemy;
            closestDistance = _leader->distance(enemy);
        }
    }

    return closestEnemy;
}


void Team::attack(Team *enemyTeam)
{
    if (!enemyTeam || !_leader)
    {
        throw std::invalid_argument("enemy team is nullptr");
    }

    if (enemyTeam->stillAlive() == 0 || this->stillAlive() == 0)
    {
        throw std::runtime_error("Nobody is alive");
    }

    if (!_leader->isAlive())
    {
        Character *closest = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (Character *soldier : list_s)
        {
            if (soldier->isAlive())
            {
                double distance = soldier->distance(getLeader());
                if (distance < minDistance)
                {
                    closest = soldier;
                    minDistance = distance;
                }
            }
        }

        setLeader(closest);
    }

    Character *target = find_t(enemyTeam);

    if (target)
    {

        for (Character *fighter : list_s)
        {
            if (fighter == nullptr || target == nullptr || !fighter->isAlive() || !target->isAlive())
                continue;

            Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
            Ninja *ninja = dynamic_cast<Ninja *>(fighter);

            if (cowboy)
            {
                if (cowboy->hasboolets())
                {
                    cowboy->shoot(target);
                    if (!target->isAlive())
                        target = find_t(enemyTeam);
                }
                else
                {
                    cowboy->reload();
                }
            }
            else if (ninja)
            {
                if (ninja->distance(target) < 1)
                {
                    ninja->slash(target);
                    if (!target->isAlive())
                        target = find_t(enemyTeam);
                }
                else
                {
                    ninja->move(target);
                }
            }
        }
    }
}

int Team::stillAlive()
{
    int aliveMembers = 0;

    for (Character *fighter : list_s)
    {
        if (fighter->isAlive())
        {
            aliveMembers++;
        }
    }

    return aliveMembers;
}

void Team::print()
{
    for (Character *fighter : list_s)
    {
        std::cout << fighter->print() << std::endl;
    }
    std::cout << "" << std::endl;
}
