#pragma once

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

namespace ariel{

    class Team{

        public:

        string _name;
        double _talent;

        int _wins = 0;
        int _loses = 0;

        int _winPoints = 0;
        int _lossPoints = 0;
        
        int _sequenceWins = 0;
        int _sequenceLoses = 0;

        int _maxSequenceWins = 0;
        int _maxSequenceLoses = 0;

        Team(string name, double talent){

            if(name==" " || name =="\n" || talent < 0 || talent >1){

                throw invalid_argument("illegal input");
            }

            _talent = talent;
            _name = name;
        }

        bool operator == (const Team& other) const{
            return _name == other._name;
        }

        bool operator!=(const Team& other)const{
            return !(*this == other);
        }
    };
}