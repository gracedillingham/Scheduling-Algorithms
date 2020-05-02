//
// Created by gdill on 5/1/2020.
//

#include "calculations.h"

double calculations::calcWaitTime(int turnAround, int burst){

    waitTime = turnAround - burst;
    return waitTime;

}//end calcWaitTime