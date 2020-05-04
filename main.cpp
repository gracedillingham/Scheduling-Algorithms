//
// Created by gdill on 4/27/2020.
//

#include <iostream>
#include "roundRobin.h"
#include "priority.h"

using namespace std;

//The purpose of this program is to test and compare the performance of
//different scheduling algorithms on the same data sets and find the better
//one for minimizing wait time

int main(int argc, char** argv){


    cout << "Running Round Robin Scheduling: " << endl;
    roundRobin r;
    r.runRR();

    cout << endl << "Running Priority Scheduling: " << endl;
    priority p;
    p.runPriority();


    return 0;

}