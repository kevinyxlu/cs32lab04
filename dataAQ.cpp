/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

bool compTeenPop(const std::pair<std::string, shared_ptr<demogState>> &left, const std::pair<std::string, shared_ptr<demogState>> &right) {
  if (left.second->getpopUnder18() > right.second->getpopUnder18()) return true;
  return false;
}

bool compPoliceShootings(const shared_ptr<psState> &left, const shared_ptr<psState> &right) {
  if (left->getNumberOfCases() > right->getNumberOfCases()) return true;
  return false;
}

bool compPoverty(const shared_ptr<demogState> &left, const shared_ptr<demogState> &right) {
  if (left->getPoverty() > right->getPoverty()) return true;
  return false;
}

dataAQ::dataAQ() {}

/* necessary function to aggregate the data - this CAN and SHOULD vary per
   student - depends on how they map, etc. */
void dataAQ::createStateDemogData(std::vector<shared_ptr<demogData>> theData) {
//FILL in
  std::string currentState = theData[0]->getState();
  std::vector<shared_ptr<demogData>> stateCounties;
  for (auto entry : theData) {
    if (entry->getState() != currentState) {
      theStates.insert(std::make_pair(currentState, std::make_shared<demogState>(currentState, stateCounties)));
      // std::cout << "New map entry for state: " << currentState << "\n"; //deboog
      stateCounties.clear();
      currentState = entry->getState();
    }
    stateCounties.push_back(entry);
  }

  if (stateCounties.size()) {
    theStates.insert(std::make_pair(currentState, std::make_shared<demogState>(currentState, stateCounties)));
    //std::cout << "New map entry for (final) state: " << currentState << "\n"; //deboog
    stateCounties.clear();
  }
  //std::cout << theStates.size() << "\n"; //deboog
}

void dataAQ::createStatePoliceData(std::vector<shared_ptr<psData>> theData) {
  for (auto entry : theData) {
    std::string currentState = entry->getState();
    if (!psStates.count(currentState)) {
      psStates.insert(std::make_pair(currentState, std::make_shared<psState>(currentState, theData)));
    }
  }
}

//return the name of the state with the largest population under age 5
string dataAQ::youngestPop() {
	//FILL in
  double record = 0;
  string usurper = "";
  for (auto state : theStates) {
    if (state.second->getpopUnder5() > record) { 
      usurper = state.first;
      record = state.second->getpopUnder5();
    }
  }
  return usurper; 
} 

//return the name of the state with the largest population under age 18
string dataAQ::teenPop()  {
	double record = 0;
  string usurper = "";
  for (auto state : theStates) {
    //std::cout << state.first << ": " << state.second->getpopUnder18() << " vs " << record << "\n";
    if (state.second->getpopUnder18() > record) { 
      usurper = state.first;
      record = state.second->getpopUnder18();
    }
  }
  return usurper; 
}

//return the name of the state with the largest population over age 65
string dataAQ::wisePop()  {
  double record = 0;
  string usurper = "";
  for (auto state : theStates) {
    if (state.second->getpopOver65() > record) { 
      usurper = state.first;
      record = state.second->getpopOver65();
    }
  }
  return usurper; 
}

//return the name of the state with the largest population who did not receive high school diploma
string dataAQ::underServeHS() {
	//FILL in  
  double record = 0;
  string usurper = "";
  for (auto state : theStates) {
    if ((100.0 - state.second->getHSup()) > record) { 
      usurper = state.first;
      record = 100.0 - state.second->getHSup();
    }
  }
  return usurper; 
} 

//return the name of the state with the largest population who did receive bachelors degree and up
string dataAQ::collegeGrads() {
	double record = 0;
  string usurper = "";
  for (auto state : theStates) {
    if ((state.second->getBAup()) > record) { 
      usurper = state.first;
      record = state.second->getBAup();
    }
  }
  return usurper; 
}

//return the name of the state with the largest population below the poverty line
string dataAQ::belowPoverty() {
	double record = 0;
  string usurper = "";
  for (auto state : theStates) {
    if (state.second->getPoverty() > record) { 
      usurper = state.first;
      record = state.second->getPoverty();
    }
  }
  return usurper; 
} 

std::ostream& operator<<(std::ostream&out, const dataAQ &allStateDemogData) 
{
  for (auto entry : allStateDemogData.theStates)
  {
    out << *(entry.second);
    out << *(allStateDemogData.psStates.at(entry.first));
  }
  return out;
}

//sort and report the top ten states in terms of number of police shootings 
void dataAQ::reportTopTenStatesPS() { 
  std::vector<shared_ptr<psState>> what;
  for (auto entry : psStates) what.push_back(entry.second);
  sort(what.begin(), what.end(), compPoliceShootings);
  std::cout << "Top ten states sorted on Below Poverty data & the associated police shooting data:\n";
  std::cout << std::setprecision(2) << std::fixed;
  for (int i = 0; i < 10; i++) {
    if (what[i]) { //Is a psState
      shared_ptr<demogState> makeState = theStates[what[i]->getState()];
      std::cout << what[i]->getState() << "\n";
      std::cout << "Total population: " << makeState->getPop() << "\n";
      std::cout << "Police shooting incidents: " << what[i]->getNumberOfCases() << "\n";
      std::cout << "Percent below poverty: " << makeState->getPoverty() << "\n";
    }
  }
}

//sort and report the top ten states with largest population below poverty 
void dataAQ::reportTopTenStatesBP(){ 
  std::vector<shared_ptr<demogState>> what;
  for (auto entry : theStates) what.push_back(entry.second);
  sort(what.begin(), what.end(), compPoverty);
  //for (auto entry : what) std::cout << entry->getState() << " " << entry->getPoverty() << "\n";
  std::cout << "Top ten states sorted on Below Poverty data & the associated police shooting data:\n";
  std::cout << std::setprecision(2) << std::fixed;
  for (int i = 0; i < 10; i++) {
    if (what[i]) { //Is a demogState
      std::cout << what[i]->getState() << "\n";
      std::cout << "Total population: " << what[i]->getPop() << "\n";
      std::cout << "Percent below poverty: " << what[i]->getPoverty() << "\n";
      std::cout << "Police shooting incidents: " << psStates[what[i]->getState()]->getNumberOfCases() << "\n";
    }
  }
}