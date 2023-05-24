#include "Team2.hpp"
using namespace ariel;
using namespace std;
Team2::Team2() : Team() {}
Team2::Team2(Character *leader) : Team(leader) {}

void Team2::add(Character *soldier)
{
    if (soldier->getInGroup() || getlist_s().size() >= 10)
    {
        throw runtime_error("run time eror");
    }

    getlist_s().insert(getlist_s().begin(), soldier);

    soldier->setInGroup();
}
