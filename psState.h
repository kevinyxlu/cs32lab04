#ifndef POLICESTATEDATA_H
#define POLICESTATEDATA_H

#include "raceDemogData.h"
#include "psData.h"

using namespace std;

class psState {
public:
    psState(string inS) : state(inS) {} //add
    
    //complete these
    int getNumMentalI();
    int getFleeingCount();
    int getCasesOver65();
    int getCasesUnder18();
    raceDemogData getRacialData();
    int getnumMales();
    int getnumFemales();
    int getNumberOfCases();
    string getState() const {return state; } 

    //add any others needed

    friend std::ostream& operator<<(std::ostream &out, const psState& PD);

protected:
    const string state;
    //add others
};

#endif