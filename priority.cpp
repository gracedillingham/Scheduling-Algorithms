//
// Created by gdill on 5/1/2020.
//

#include "priority.h"

void priority::runPriority() {

    //variables
    readFiles files;
    files.read();
    int burstTime[6] = {-3,-4,-5,-10,-12,-15}; //burst times for processes in order
    int timeElapsed = 0; //keep track of time that has
    priority_queue<int> toComplete;
    map<int, string> pairs = files.getPairs();
    map<string, int> ogPairs = files.getOgPairs();
    int waitTime;
    string currProcess;
    int absVal;
    calculations c;
    int total = 0;


    // add all burst values to the queue; they will then be processed in a first-in, first-out order (smallest first)
    for(int i = 0; i < 6; i++){
        toComplete.push(burstTime[i]);
    }//end for


    //completely execute processes in order
    while(!toComplete.empty()){

        absVal = abs(toComplete.top());
        timeElapsed += absVal;
        currProcess = pairs.at(absVal);
        waitTime = c.calcWaitTime(timeElapsed, ogPairs.at(currProcess)); //time Elapsed = turnAround time
        total += waitTime;

        cout << "Process " << currProcess << " turn around time " << timeElapsed << " wait time: " << waitTime << endl;

        pairs.erase(absVal);
        toComplete.pop();

    }//end while

    cout << "final total " << total << endl;

    int average = c.calcAverage(total,6);
    cout << "Average wait time: " << average << endl;

}//end runpriority

