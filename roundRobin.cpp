//
// Created by gdill on 4/28/2020.
//

#include "roundRobin.h"

void roundRobin::runRR() {

    //need process list and matching burst/execution time

    //variables
    int processTimer = 2; //switch processes every 50 ms
    int burstTime[] = {5,3,8,9}; //burst times for processes in order
    queue<int> toComplete;

    //add all values to queue
    for(int i = 0; i < 4; i++){

        //add weights to minimum priority queue
        toComplete.push(burstTime[i]);

    }//end for

    //execute processes in order for a limited amount of time
    //continue this time-scheduled loop until each process has finished

    //loop while queue is not empty
    //run for allotted time then rotate



    cout << "end round robin" << endl;

}//end runRR


int roundRobin::calcWaitingTime() {

    //waiting time is the total amount of time in the queue and
    //can be calculated by turn around time - arrival time

    return 0;

}//end calcWaitingTime



int roundRobin::calcTurnAroundTime() {

    //turn around time is the time between submission into the queue
    //and completion, calculated as completion time - arrival time

    return 0;
}//end calcTurnAroundTime




