//
// Created by gdill on 5/1/2020.
//

#include "priority.h"

void priority::runPriority() {

    //variables
    int burstTime[3] = {-3,-4,-5}; //burst times for processes in order
    int timeElapsed = 0; //keep track of time that has
    priority_queue<int> toComplete;
    int turnAround = 0;
    map<int, string> pairs = {{3,"P1"},{4,"P2"}, {5,"P3"}};
    map<string, int> ogPairs = {{"P1",3},{"P2",4}, {"P3",5}};
    map<string, int> arrivalTime = {{"P1", 0},{"P2",0},{"P3",0}}; //initialize arrival time array values
    int waitTime;
    string currProcess;
    int absVal;


    // add all burst values to the queue; they will then be processed in a first-in, first-out order (smallest first)
    for(int i = 0; i < 3; i++){
        toComplete.push(burstTime[i]);
    }//end for


    //completely execute processes in order
    while(!toComplete.empty()){

        absVal = abs(toComplete.top());
        timeElapsed += absVal;
        currProcess = pairs.at(absVal);
        turnAround = timeElapsed - arrivalTime.at(currProcess);
        waitTime = turnAround - ogPairs.at(currProcess);

        cout << "Process " << currProcess << " turn around time " << turnAround << " wait time: " << waitTime << endl;

        pairs.erase(absVal);
        toComplete.pop();

    }//end while

}//end runpriority

