#ifndef DATAAQ_H
#define DATAAQ_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "demogState.h"
#include "psState.h"

/*
  data aggregator and query for testing
*/
class dataAQ {
  public:
    dataAQ();

    /* necessary function to aggregate the data - this CAN and SHOULD vary per
   student - depends on how they map, etc. */
    void createStateDemogData(std::vector<shared_ptr<demogData>> theData);
    void createStatePoliceData(std::vector<shared_ptr<psData>> theData);

    //return the name of the state with the largest population under age 5
    string youngestPop();
    //return the name of the state with the largest population under age 18
    string teenPop();
    //return the name of the state with the largest population over age 65
    string wisePop();
    //return the name of the state with the largest population who did not finish high school
    string underServeHS();
    //return the name of the state with the largest population who completed college
    string collegeGrads();
    //return the name of the state with the largest population below the poverty line
    string belowPoverty();

    string getMinTeenPop();

    //sort and report the top ten states in terms of number of police shootings 
    void reportTopTenStatesPS();
    //sort and report the top ten states with largest population below poverty 
    void reportTopTenStatesBP();

    //getters
    shared_ptr<demogState> getStateData(string stateName) { /*fix this*/  return theStates[stateName]; } //FIX 
    shared_ptr<psState> getStatePoliceData(string stateName) { return psStates[stateName]; } //FIX  
    
    friend std::ostream& operator<<(std::ostream &out, const dataAQ &allStateDemogData);

    private:
       //how will you store the two different data-types?
       map<std::string, shared_ptr<demogState>> theStates;
       map<std::string, shared_ptr<psState>> psStates;

};
#endif