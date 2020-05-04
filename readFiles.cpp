//
// Created by gdill on 5/1/2020.
//

#include "readFiles.h"

void readFiles::read(){

    //variables
    int processCount;
    int burstTime;
    string process;
    ifstream infile;
    vector<int> bursts;
    map<int, string> readPairs;
    map<string, int> readOgPairs;
    map<int, string> pairPtr;
    map<string, int> ogPairPtr;

    //open command file & test for open
    infile.open("testData.txt");

    if(!infile.is_open()){
        cout << "Data file is not open" << endl;
    }

    //read in and print number of processes
    infile >> processCount;
    setProcessNum(processCount);
    cout << "Process Count: " << processCount << endl;

    //read in test data
    for(int i = 0; i < processCount; i++){

        infile >> burstTime;
        infile >> process;

        bursts.push_back(burstTime);
        readPairs.insert({burstTime, process});
        readOgPairs.insert({process, burstTime});

    }//end for

    //set data to be returned
    setBursts(bursts);
    setOgPairs(readOgPairs);
    setPairs(readPairs);

}//end read


map<string, int> readFiles::getOgPairs(){
    return ogPairs;
}//end getOgPairs


map<int, string> readFiles::getPairs(){
    return pairs;
}//end getBurstTime


void readFiles::setOgPairs(map<string,int> map){
    ogPairs = map;
}//end setOgPairs


void readFiles::setPairs(map<int,string> map){
    pairs = map;
}//end setBurstTime


void readFiles::setProcessNum(int num){
    processCount = num;
}//end setProcessNum


int readFiles::getProcessNum(){
    return processCount;
}//end getProcessNum

void readFiles::setBursts(vector<int> v){
    returnBursts = v;
}//end getBursts

vector<int> readFiles::getBursts(){
    return returnBursts;
}//end getBursts





