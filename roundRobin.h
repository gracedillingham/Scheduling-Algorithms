//
// Created by gdill on 4/28/2020.
//

#ifndef SCHEDULING_ALGORITHMS_ROUNDROBIN_H
#define SCHEDULING_ALGORITHMS_ROUNDROBIN_H
#include <iostream>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

class roundRobin {
public:
    void runRR();               //run processes through the round robin scheduling algorithm
    int calcTurnAroundTime();   //calculate turn around time for a process
};


#endif //SCHEDULING_ALGORITHMS_ROUNDROBIN_H
