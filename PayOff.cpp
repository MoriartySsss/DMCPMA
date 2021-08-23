//
// Created by MuYao Si on 2021-08-22.
//

#include "PayOff.h"
#include <algorithm>
using namespace std;

PayOff::PayOff() {
// constructor
}

PayOff::~PayOff() {
// destructor
}

PayOffCall::~PayOffCall() {

};

PayOffPut::~PayOffPut() {

}



PayOffCall::PayOffCall(double sourceStrike): Strike(sourceStrike)
{
}

double PayOffCall::operator()(double sourceSpot) const {
    return max(sourceSpot - Strike, 0.0);
}

PayOff* PayOffCall::clone() const{
    return new PayOffCall(*this);
}





PayOffPut::PayOffPut(double sourceStrike): Strike(sourceStrike) {

}

double PayOffPut::operator()(double sourceSpot) const {
    return max(Strike - sourceSpot, 0.0);
}

PayOff *PayOffPut::clone() const {
    return new PayOffPut(*this);
}


