//
// Created by gdill on 4/28/2020.
//

#include "roundRobin.h"

void roundRobin::runRR() {

    //variables
    int processTimer = 3; //switch processes every 50 ms
    int burstTime[] = {5,3,8,9}; //burst times for processes in order
    int timeElapsed = 0; //keep track of time that has
    queue<int> toComplete;
    int turnAround = 0;
    map<int, string> pairs = {{5,"P1"},{3,"P2"}, {8,"P3"}, {9,"P4"}};
    map<string, int> ogPairs = {{"P1",5},{"P2",3}, {"P3",8}, {"P4",9}};
    map<string, int> arrivalTime = {{"P1", 1},{"P2",2},{"P3",3},{"P4",4}}; //initialize arrival time array values
    int temp;
    string temp2;
    int changeVal;
    int waitTime;
    string currProcess;


     /* add all burst values to the queue; they will then be processed in a first-in, first-out
     * order and returned to the end of the queue if the burst time is not complete */
    for(int i = 0; i < 4; i++){
        toComplete.push(burstTime[i]);
    }//end for


     /* execute processes in order for the amount of time determined by the processTimer
     * continue this time-scheduled loop until each process has finished by running
     * for the allotted time and then rotating */
    while(!toComplete.empty()){

        cout << "Top of while, time elapsed: " << timeElapsed << endl;

        /*
         * If the burst time will be completed in the determined process time, add the amount
         * of time that will pass, determine the process the burst time belongs to, and calculate
         * the process's turn around time and wait time. Then print the results update queue & pair container
         */
        if(toComplete.front() <= processTimer){

            timeElapsed += toComplete.front();
            currProcess = pairs.at(toComplete.front());
            turnAround = timeElapsed - arrivalTime.at(currProcess);
            waitTime += turnAround - ogPairs.at(currProcess);

            cout << "Process " << currProcess << " at " << toComplete.front() << " turn around time " << turnAround;
            cout << " wait time: " << waitTime << endl;

            pairs.erase(toComplete.front());
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




