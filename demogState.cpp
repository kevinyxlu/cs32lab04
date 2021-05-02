#include "demogState.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>
using namespace std;

//add member functions here

/* print state data - as aggregate of all the county data */
std::ostream& operator<<(std::ostream &out, const demogState&SD) {

    // outputs the data in the form:
    // State Info: UT
    // Number of Counties: 29   
    // Population Info:
    // (over 65): 10.03% and total: 295146
    // (under 18): 30.71% and total: 903830
    // (under 5): 8.58% and total: 252378
    // Education info: 
    // (Bachelor or more): 30.54% and total: 898886
    // (high school or more): 91.01% and total: 2678412
    // persons below poverty: 12.67% and total: 372832
    // Total population: 2942902
    
    cout << fixed;
    cout.precision(2);
    out << "State Info: " << SD.stateName << endl; // State Info: UT
    out << "Number of Counties: " << SD.numCounties << endl; // Number of Counties: 29   
    out << "Population Info:\n"; // Population Info:
    out << "(over 65): " << SD.percentOver65 << "% and total: " << SD.countOver65 << endl; // (over 65): 10.03% and total: 295146
    out << "(under 18): " << SD.percentUnder18 << "% and total: " << SD.countUnder18 << endl; // (under 18): 30.71% and total: 903830
    out << "(under 5): " << SD.percentUnder5 << "% and total: " << SD.countUnder5 << endl; // (under 5): 8.58% and total: 252378
    out << "Education info:\n"; // Education info: 
    out << "(Bachelor or more): " << SD.percentBachelorPlus << "% and total: " << SD.countBachelorPlus << endl; // (Bachelor or more): 30.54% and total: 898886
    out << "(high school or more): " << SD.percentHSPlus << "% and total: " << SD.countHSPlus << endl; // (high school or more): 91.01% and total: 2678412
    out << "persons below poverty: " << SD.percentPoverty << "% and total: " << SD.countPoverty << endl;// persons below poverty: 12.67% and total: 372832
    out << "Total population: " << SD.totalPopulation << endl; // Total population: 2942902
    return out;
}

demogState::demogState(string state, vector<shared_ptr<demogData>> countyData)
{
    stateName = state; // set name of the state
    numCounties = countyData.size(); // size of the vector should be the number of counties

    // set all the counts to 0 to prepare to iterate through vector
    totalPopulation = 0;
    countOver65 = 0;
    countUnder18 = 0;
    countUnder5 = 0;
    countBachelorPlus = 0;
    countHSPlus = 0;
    countPoverty = 0;

    for(int i = 0; i < countyData.size(); i++) // iterate through all counties in the state to get all counts for the state
    {
        // aggregate the data counts for the states
        totalPopulation = totalPopulation + countyData[i]->getPop(); // aggregate population
        countOver65 = countOver65 + countyData[i]->getpopOver65Count(); // aggregate countOver65
        countUnder18 = countUnder18 + countyData[i]->getpopUnder18Count(); // aggregate countUnder18
        countUnder5 = countUnder5 + countyData[i]->getpopUnder5Count();
        countBachelorPlus = countBachelorPlus + countyData[i]->getBAupCount();
        countHSPlus = countHSPlus + countyData[i]->getHSupCount();
        countPoverty = countPoverty + countyData[i]->getPovertyCount();
    }

    percentOver65 = (countOver65 / double(totalPopulation)) * 100; // calculate the percent age above 65
    percentUnder18 = (countUnder18 / double(totalPopulation)) * 100; // calculate the percent age under 18
    percentUnder5 = (countUnder5 / double(totalPopulation)) * 100; // calculate the percent age under 5
    percentBachelorPlus = (countBachelorPlus / double(totalPopulation)) * 100; // calculate the percent bachelor degree or more
    percentHSPlus = (countHSPlus / double(totalPopulation)) * 100; // calculate the percent high school educated or more
    percentPoverty = (countPoverty / double(totalPopulation)) * 100; // calculate the percent below poverty
}