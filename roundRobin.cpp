//
// Created by gdill on 4/28/2020.
//

#include "roundRobin.h"

void roundRobin::runRR() {

    //need process list and matching burst/execution time

    //variables
    int processTimer = 3; //switch processes every 50 ms
    int burstTime[] = {5,3,8,9}; //burst times for processes in order
    int arrivalTime[4] = {0,0,0,0}; //initialize arrival time array values to zero
    string processOrder[4] = {"P1", "P2", "P3", "P4"};
    int timeElapsed = 0; //keep track of time that has
    queue<string> processes;
    int counter = 0;
    double average = 0;
    int toAdd = 0;
    queue<int> toComplete;
    int turnAround = 0;
    map<int, string> pairs = {{5,"P1"},{3,"P2"}, {8,"P3"}, {9,"P4"}};

    //add all values to queue
    for(int i = 0; i < 4; i++){

        //add weights to minimum priority queue
        processes.push(processOrder[i]);
        toComplete.push(burstTime[i]);

    }//end for

    //queue pops from front

    //execute processes in order for a limited amount of time
    //continue this time-scheduled loop until each process has finished
    //loop while queue is not empty
    //run for allotted time then rotate
    while(!toComplete.empty()){

        if(toComplete.front() <= processTimer){

            timeElapsed += toComplete.front();

            turnAround = timeElapsed - 0;

            cout << "Process " << pairs.at(toComplete.front()) << " at " << toComplete.front() << " turn around time " << turnAround << endl;

            pairs.erase(toComplete.front());
            //execute for the remainder of the process' burst time
            toComplete.pop();

        }//end if
        else{

            int temp;
            string temp2;
            //execute for the length of processTimer
            //adjust burst time remaining
            temp = toComplete.front();
            temp2 = pairs.at(temp);
            toComplete.front() -= processTimer;
            pairs.insert({toComplete.front(), temp2});

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




