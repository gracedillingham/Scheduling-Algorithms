//
// Created by gdill on 5/1/2020.
//

#include "priority.h"

void priority::runPriority() {

    //variables
    readFiles files;
    int timeElapsed = 0; //keep track of time that has
    priority_queue<int> toComplete;
    int waitTime;
    string currProcess;
    int absVal;
    calculations c;
    int total = 0;

    //read in and set data
    files.read();
    map<int, string> pairs = files.getPairs();
    map<string, int> ogPairs = files.getOgPairs();
    int processCount = files.getProcessNum();
    vector<int>burstTime = files.getBursts();

    /* add all burst values to the queue; they will be added as negative numbers in
     * order to create the desired priority, and they will be run as such */
    for(int i = 0; i < processCount; i++){
        toComplete.push(-(burstTime.at(i)));
    }//end for

    /*
     * For each process, completely execute processes in order, take the absolute value of the next burst, increment time,
     * and then print the process's results. Once a process is complete, remove it from the queue
     */
    while(!toComplete.empty()){

        absVal = abs(toComplete.top());
        timeElapsed += absVal;
        currProcess = pairs.at(absVal);
        waitTime = c.calcWaitTime(timeElapsed, ogPairs.at(currProcess));
        total += waitTime;
        cout << "Process " << currProcess << " turn around time " << timeElapsed << " wait time: " << waitTime << endl;
        pairs.erase(absVal);
        toComplete.pop();

    }//end while

    int average = c.calcAverage(total,processCount);
    cout << "Average wait time: " << average << endl;

}//end runpriority

