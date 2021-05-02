#ifndef POLICESTATEDATA_H
#define POLICESTATEDATA_H

#include <memory>
#include <vector>
#include "raceDemogData.h"
#include "psData.h"

using namespace std;

class psState {
public:
    psState(string inS, vector<shared_ptr<psData>> psData); // finish
    
    //complete these
    int getNumMentalI() const { return numMentalIllness; }
    int getFleeingCount() const { return fleeingCount; }
    int getCasesOver65() const { return casesOver65; }
    int getCasesUnder18() const { return casesUnder18; }
    raceDemogData getRacialData();
    int getnumMales() const { return numMales; }
    int getnumFemales() const { return numFemales; }
    int getNumberOfCases() const { return numCases; }
    string getState() const { return state; } 

    //add any others needed

    friend std::ostream& operator<<(std::ostream &out, const psState& PD);

protected:
    string state;
    int numMentalIllness = 0;
    int fleeingCount = 0;
    int casesOver65 = 0;
    int casesUnder18 = 0;
    int numMales = 0;
    int numFemales = 0;
    int numCases = 0;
    //add others
};

#endif