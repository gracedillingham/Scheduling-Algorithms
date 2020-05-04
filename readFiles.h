//
// Created by gdill on 5/1/2020.
//

#ifndef SCHEDULING_ALGORITHMS_READFILES_H
#define SCHEDULING_ALGORITHMS_READFILES_H
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

class readFiles {
public:
    void read(); //read in files
    map<string, int> getOgPairs();
    map<int, string> getPairs();
    void setOgPairs(map<string,int> map);
    void setPairs(map<int,string> map);
    void setProcessNum(int num);
    int getProcessNum();
    void setBursts(vector<int> v);
    vector<int> getBursts();


private:
    map<int, string> pairs;
    map<string, int> ogPairs;
    int processCount;
    vector<int> returnBursts;
};


#endif //SCHEDULING_ALGORITHMS_READFILES_H
