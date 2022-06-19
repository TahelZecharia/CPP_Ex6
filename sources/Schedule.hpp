#pragma once

#include "Team.hpp"
#include "Game.hpp"
#include "League.hpp"

#include <algorithm>

using namespace std;

namespace ariel{
    
    class Schedule{
        
        public:
        
        League *_league;

        Schedule(League &league) : _league(&league){

        }

        void winner(){

            Team* winner = _league->_teams.at(0);

            for(size_t i = 0; i<_league->_teams.size(); i++){

                if(_league->_teams.at(i)->_wins > winner->_wins){

                    winner = _league->_teams.at(i);
                }
            }

            cout << "THE WINNER TEAM IS: " << winner->_name << endl;
        }

        void print() {

            sort(_league->_teams.begin(),_league->_teams.end(),
            [](Team* a, Team* b) {return a->_wins > b->_wins;});

            for(size_t i=0 ; i < _league->_teams.size() ;i++){

                Team* temp = _league->_teams.at(i);

                cout << "NAME: " << temp->_name << "  |  ";
                cout << "WINS: " <<  to_string(temp->_wins)<< "  |  ";
                cout << "LOSSES: " << to_string(temp->_loses)<< "  |  ";
                cout << "POINTS: " << to_string(temp->_winPoints) << "  |  ";
                cout << "LOSS POINTS: " <<  to_string(temp->_lossPoints) << "  |  ";
                cout << "DIFF: " <<  to_string(temp->_winPoints -  temp->_lossPoints) << "  |  ";
                cout << endl;
            }
        }
    };
}
