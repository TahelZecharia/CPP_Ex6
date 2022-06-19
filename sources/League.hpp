#pragma once

#include "Team.hpp"
#include "Game.hpp"

using namespace std;

namespace ariel{

    class League{

        public:

        vector <Team*> _teams;

        League(){
            
            for(int i =0; i < 20; i++){
               
                this->_teams.push_back(new Team(to_string(i), 0.1));
            }
        }

        League(vector <Team*> teams){

            for(int i=0; i<teams.size(); i++){
                
                this->_teams.push_back(teams.at((unsigned int)i));
            }
        }

        ~League(){
            
            for(int i=0;i<_teams.size();i++){

                delete _teams.at((unsigned int)i);
            }
        }

        void start (){

            vector<Game*> games;
           
            for(int i=0 ; i<_teams.size() ; i++){
                
                for(int j = i+1; j <_teams.size();j++){

                    games.push_back(new Game(_teams.at((unsigned int)i),_teams.at((unsigned int)j)));
                    games.push_back(new Game(_teams.at((unsigned int)j),_teams.at((unsigned int)i)));

                    for(int i=0;i<games.size();i++){

                        games.at((unsigned int)i)->play();
                    }
                }
            }
        } 
    };
}