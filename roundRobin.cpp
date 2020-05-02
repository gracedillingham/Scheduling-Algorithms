//
// Created by gdill on 4/28/2020.
//

#include "roundRobin.h"

void roundRobin::runRR() {

    //variables
    int processTimer = 1; //switch processes every 50 ms
    int burstTime[3] = {3,4,5}; //burst times for processes in order
    int timeElapsed = 0; //keep track of time that has
    queue<int> toComplete;
    int turnAround = 0;
    map<int, string> pairs = {{3,"P1"},{4,"P2"}, {5,"P3"}};
    map<string, int> ogPairs = {{"P1",3},{"P2",4}, {"P3",5}};
    map<string, int> arrivalTime = {{"P1", 0},{"P2",0},{"P3",0}}; //initialize arrival time array values
    int temp;
    string temp2;
    int changeVal;
    int waitTime;
    string currProcess;


     /* add all burst values to the queue; they will then be processed in a first-in, first-out
     * order and returned to the end of the queue if the burst time is not complete */
    for(int i = 0; i < 3; i++){
        toComplete.push(burstTime[i]);
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
            turnAround = timeElapsed - arrivalTime.at(currProcess);
            waitTime = turnAround - ogPairs.at(currProcess);

            cout << "Process " << currProcess << " turn around time " << turnAround << " wait time: " << waitTime << endl;

            pairs.erase(toComplete.front());
            toComplete.pop();

        }//end if
        else{

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

    }//end while

}//end runRR


int roundRobin::calcTurnAroundTime() {

    //turn around time is the time between submission into the queue
    //and completion, calculated as completion time - arrival time

    return 0;
}//end calcTurnAroundTime




