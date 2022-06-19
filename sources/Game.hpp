#pragma once

#include "Team.hpp"
using namespace std;

namespace ariel{
    
    class Game{
        public:
        Team* _home;
        Team* _out;

        Game(Team* home, Team* out) : _home(home), _out(out){

        }
        
        void play(){

            int homePoints = (rand()%(100-55)) + 55;
            int outPoints = (rand()%(100-50)) + 50;

            homePoints += (int)(_home->_talent * 10);
            outPoints += (int)(_out->_talent * 10);

            _home->_winPoints += homePoints;
            _home->_lossPoints += outPoints;

            _out->_winPoints += outPoints;
            _out->_lossPoints += homePoints;

            if (homePoints >= outPoints) {
                
                _home->_wins++;
                _out->_loses++;

                _home->_sequenceLoses = 0;
                _home->_sequenceWins +=1;
                
                if (_home->_sequenceWins > _home->_maxSequenceWins){
                    
                    _home->_maxSequenceWins = _home->_sequenceWins;
                }

                _out->_sequenceWins = 0;
                _out->_sequenceLoses +=1;

                if (_out->_sequenceLoses > _out->_maxSequenceLoses){

                     _out->_maxSequenceLoses = _out->_sequenceLoses;
                }
            }

            else{

                _out->_wins++;
                _home->_loses++;

                _out->_sequenceLoses = 0;
                _out->_sequenceWins +=1;
                
                if (_out->_sequenceWins > _out->_maxSequenceWins){
                    
                    _out->_maxSequenceWins = _out->_sequenceWins;
                }

                _home->_sequenceWins = 0;
                _home->_sequenceLoses +=1;

                if (_home->_sequenceLoses > _home->_maxSequenceLoses){

                     _home->_maxSequenceLoses = _home->_sequenceLoses;
                }

            }
        }
    };
}