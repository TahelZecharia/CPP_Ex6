#include "doctest.h"

#include "Team.hpp"
#include "Game.hpp"
#include "League.hpp"
#include "Schedule.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("play"){

    vector<Team*> teams;

    CHECK_NOTHROW(teams.push_back(new Team("a",0.1)));
    CHECK_NOTHROW(teams.push_back(new Team("b",0.2)));
    CHECK_NOTHROW(teams.push_back(new Team("c",0.3)));
    CHECK_NOTHROW(teams.push_back(new Team("d",0.4)));
    CHECK_NOTHROW(teams.push_back(new Team("e",0.5)));
    CHECK_NOTHROW(teams.push_back(new Team("f",0.6)));
    CHECK_NOTHROW(teams.push_back(new Team("g",0.7)));
    CHECK_NOTHROW(teams.push_back(new Team("h",0.8)));
    CHECK_NOTHROW(teams.push_back(new Team("i",0.9)));
    CHECK_NOTHROW(teams.push_back(new Team("j",0.1)));
    CHECK_NOTHROW(teams.push_back(new Team("k",0.2)));
    CHECK_NOTHROW(teams.push_back(new Team("l",0.3)));
    CHECK_NOTHROW(teams.push_back(new Team("m",0.4)));
    CHECK_NOTHROW(teams.push_back(new Team("n",0.5)));
    CHECK_NOTHROW(teams.push_back(new Team("o",0.6)));
    CHECK_NOTHROW(teams.push_back(new Team("p",0.7)));
    CHECK_NOTHROW(teams.push_back(new Team("q",0.8)));
    CHECK_NOTHROW(teams.push_back(new Team("r",0.9)));
    CHECK_NOTHROW(teams.push_back(new Team("s",0.1)));
    CHECK_NOTHROW(teams.push_back(new Team("t",0.2)));

    League* league = new League(teams);
    CHECK(league->_teams.size() == 20);
    CHECK_NOTHROW(league->start());
    Schedule schedule(*league);
    schedule.winner();
    schedule.print();
}