
#include "dataAQ.h"
#include "psData.h"
#include "parse.h"
#include <iostream>
#include "tddFuncs.h"
using namespace std;

int main() {
  cout << "Testing state data police shooting..." << endl;

	dataAQ theAnswers;

    //read in a csv file and create a vector of objects representing each counties data
    std::vector<shared_ptr<psData>> thePoliceData = read_csvPolice(
            "police_shootings_cleaned.csv", POLICE);

    theAnswers.createStatePoliceData(thePoliceData);

    shared_ptr<psState> CA_PSData = theAnswers.getStatePoliceData("CA");
    
  	ASSERT_EQUALS(211, CA_PSData->getNumMentalI() );
    //other values will be tested on gradescope

  return 0;
}
