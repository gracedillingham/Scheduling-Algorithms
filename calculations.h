//
// Created by gdill on 5/1/2020.
//

#ifndef SCHEDULING_ALGORITHMS_CALCULATIONS_H
#define SCHEDULING_ALGORITHMS_CALCULATIONS_H


class calculations {
public:
    double calcWaitTime(int turnAround, int burst); //calculate a process's total wait time in the queue
    double calcTurnAround(int completion, int arrival);

private:
    double waitTime;
    double turnAroundTime;
    double average;
};


#endif //SCHEDULING_ALGORITHMS_CALCULATIONS_H
