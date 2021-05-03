#ifndef STATE_H
#define STATE_H

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include "demogData.h"

/*
  class to represent state data - fairly redundent at this point but will use
  inheritence later - FILL IN
*/
class demogState {
  public:
   //FILL IN

    // constructor with no arguments puts -1 for all values as stud values
    demogState() {}

    //constructor with two arguments: the abbreviation of the state and a vector 
    demogState(string state, vector<shared_ptr<demogData>> countyData);

    string getState() const { return stateName; }
    double getpopOver65() const { return percentOver65; }
    double getpopUnder18() const { return percentUnder18; }
    double getpopUnder5() const { return percentUnder5; }
    double getBAup() const { return percentBachelorPlus; }
    double getHSup() const { return percentHSPlus; }
    double getPoverty() const { return percentPoverty; }
    int getPop() const { return totalPopulation; }

    friend std::ostream& operator<<(std::ostream &out, const demogState &SD);


	private:
    // state information
    string stateName = "TOUPDATE"; // name of the state
    int totalPopulation = -1; // the population of the state
    int numCounties = -1; // number of counties imn the state

    // percentage data
    double percentOver65 = -1; // age above 65
    double percentUnder18 = -1; // age under 18
    double percentUnder5 = -1; // age under 5
    double percentBachelorPlus = -1; // bachelor degree or more
    double percentHSPlus = -1; // high school educated or more
    double percentPoverty = -1; // below poverty

    // count data
    int countOver65 = -1; // age above 65
    int countUnder18 = -1; // age under 18
    int countUnder5 = -1; // age under 5
    int countBachelorPlus = -1; // bachelor degree or more
    int countHSPlus = -1; // high school educated or more
    int countPoverty = -1; // below poverty

    // racial data (percantages)
    double percentFirstNation = -1;
    double percentAsian = -1;
    double percentBlack = -1;
    double percentLatinx = -1;
    double percentHIPacificIsle = -1;
    double percentMultiRace = -1;
    double percentWhite = -1;
    double percentWhiteNH = -1;

    // racial data (counts)
    int countFirstNation = -1;
    int countAsian = -1;
    int countBlack = -1;
    int countLatinx = -1;
    int countHIPacificIsle = -1;
    int countMultiRace = -1;
    int countWhite = -1;
    int countWhiteNH = -1;

	//DATA here
};
#endif