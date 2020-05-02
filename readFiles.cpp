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
    map<int, string> readPairs;
    map<string, int> readOgPairs;
    map<int, string> pairPtr;
    map<string, int> ogPairPtr;

    //open command file & test for open
    infile.open("testData.txt");

    //cout << "test file for open " << endl;

    if(!infile.is_open()){
        cout << "Data file is not open" << endl;
    }

    infile >> processCount;
    cout << processCount << endl;

    for(int i = 0; i < processCount; i++){

        infile >> burstTime;
        infile >> process;

       // cout << burstTime << endl;
        //cout << process << endl;

        //bursts[i] = burstTime;
        readPairs.insert({burstTime, process});
        readOgPairs.insert({process, burstTime});

    }//end for

    setOgPairs(readOgPairs);
    setPairs(readPairs);

    cout << "Pair top " << readPairs.at(3) << endl;

    cout << "bottom read" << endl;

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







