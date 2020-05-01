//
// Created by gdill on 4/28/2020.
//

#include "roundRobin.h"

void roundRobin::runRR() {

    //need process list and matching burst/execution time

    //variables
    int processTimer = 3; //switch processes every 50 ms
    int burstTime[] = {5,3,8,9}; //burst times for processes in order
    map<string, int> arrivalTime = {{"P1", 1},{"P2",2},{"P3",3},{"P4",4}}; //initialize arrival time array values
    string processOrder[4] = {"P1", "P2", "P3", "P4"};
    int timeElapsed = 0; //keep track of time that has
    queue<string> processes;
    int counter = 0;
    double average = 0;
    queue<int> toComplete;
    int turnAround = 0;
    map<int, string> pairs = {{5,"P1"},{3,"P2"}, {8,"P3"}, {9,"P4"}};
    map<string, int> ogPairs = {{"P1",5},{"P2",3}, {"P3",8}, {"P4",9}};
    int temp;
    string temp2;
    int changeVal;
    int waitTime;

    //add all values to queue
    for(int i = 0; i < 4; i++){

        //add weights to minimum priority queue
        processes.push(processOrder[i]);
        toComplete.push(burstTime[i]);

    }//end for

    //queue pops from front

    string currProcess;

    //execute processes in order for a limited amount of time
    //continue this time-scheduled loop until each process has finished
    //loop while queue is not empty
    //run for allotted time then rotate
    while(!toComplete.empty()){

        cout << "Top of while, time elapsed: " << timeElapsed << endl;

        if(toComplete.front() <= processTimer){

            timeElapsed += toComplete.front();

            currProcess = pairs.at(toComplete.front());

            turnAround = timeElapsed - arrivalTime.at(currProcess);

            waitTime += turnAround - ogPairs.at(currProcess);

            cout << "Process " << currProcess << " at " << toComplete.front() << " turn around time " << turnAround;
            cout << " wait time: " << waitTime << endl;

            pairs.erase(toComplete.front());
            //execute for the remainder of the process' burst time
            toComplete.pop();

        }//end if
        else{

            cout << "didn't match, process " << pairs.at(toComplete.front()) << endl;

            //execute for the length of processTimer
            //adjust burst time remaining
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




