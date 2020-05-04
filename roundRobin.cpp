//
// Created by gdill on 4/28/2020.
//

#include "roundRobin.h"

void roundRobin::runRR() {

    //variables
    readFiles files;
    int processTimer = 3;
    int timeElapsed = 0;
    queue<int> toComplete;
    int temp;
    string temp2;
    int changeVal;
    int waitTime;
    string currProcess;
    calculations c;
    int total = 0;

    //read in data files and import values
    files.read();
    vector<int>burstTime = files.getBursts();
    map<int, string> pairs = files.getPairs();
    map<string, int> ogPairs = files.getOgPairs();
    int processCount = files.getProcessNum();

     /* add all burst values to the queue; they will then be processed in a first-in, first-out
     * order and returned to the end of the queue if the burst time is not complete */
    for(int i = 0; i < processCount; i++){
        toComplete.push(burstTime.at(i));
    }//end for


     /* execute processes in order for the amount of time determined by the processTimer
     * continue this time-scheduled loop until each process has finished by running
     * for the allotted time and then rotating */
    while(!toComplete.empty()){

        /*
         * If the burst time will be completed in the determined process time, add the amount
         * of time that will pass, determine the process the burst time belongs to, and calculate
         * the process's turn around time and wait time. Then print the results update queue & pair container
         */
        if(toComplete.front() <= processTimer){

            timeElapsed += toComplete.front();
            currProcess = pairs.at(toComplete.front());
            waitTime = c.calcWaitTime(timeElapsed, ogPairs.at(currProcess));
            total += waitTime;
            cout << "Process " << currProcess << " turn around time " << timeElapsed << " wait time: " << waitTime << endl;
            pairs.erase(toComplete.front());
            toComplete.pop();

        }//end if
        else{

             /*
             * execute for the length of the processTimer, adjust burst time remaining,
             * move the process at the front of the queue to the back of the queue, and
              * increment the amount of time that has Elapsed
             */
            temp = toComplete.front();
            temp2 = pairs.at(temp);
            toComplete.front() -= processTimer;
            changeVal = toComplete.front();
            toComplete.pop();
            pairs.erase(temp);
            pairs.insert({changeVal, temp2});
            toComplete.push(changeVal);
            timeElapsed += processTimer;

        }//end else

    }//end while

    int average = c.calcAverage(total, processCount);
    cout << "Average wait time: " << average << endl;

}//end runRR






