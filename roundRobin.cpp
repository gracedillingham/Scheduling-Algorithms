//
// Created by gdill on 4/28/2020.
//

#include "roundRobin.h"

void roundRobin::runRR() {

    //need process list and matching burst/execution time

    //variables
    int processTimer = 3; //switch processes every 50 ms
    int burstTime[] = {3,5,8,9}; //burst times for processes in order
    int arrivalTime[4] = {0,0,0,0}; //initialize arrival time array values to zero
    int timeElapsed = 0; //keep track of time that has elapsed
    int counter = 0;
    double average = 0;
    int toAdd = 0;
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
    while(!toComplete.empty()){
        cout << "in while" << endl;

        if(toComplete.front() <= processTimer){

            cout << "in if" << endl;

            timeElapsed += toComplete.front();

            cout << "at " << toComplete.front() << " time " << timeElapsed << endl;

            //execute for the remainder of the process' burst time
            toComplete.pop();

        }//end if
        else{

            cout << "in else" << endl;

            //execute for the length of processTimer
            //adjust burst time remaining
            toComplete.front() -= processTimer;

            timeElapsed += processTimer;

        }//end else

        //adjust counter
        if(counter >= 3){
            counter = 0;
        }
        else{
            counter++;
        }


    }//end while


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




