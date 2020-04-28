//
// Created by gdill on 4/27/2020.
//

#include <cstring>
#include <iostream>
#include "roundRobin.h"

using namespace std;

//The purpose of this program is to test and compare the performance of
//different scheduling algorithms on the same data sets and find the better
//one for minimizing wait time

int main(int argc, char** argv){

    cout << "Hello " << endl;

    roundRobin r;
    r.runRR();

    return 0;

}