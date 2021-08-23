//
// Created by MuYao Si on 2021-08-22.
//

#ifndef ADVANCEDVERSION_BRIDGE_H
#define ADVANCEDVERSION_BRIDGE_H
#include "PayOff.h"

class Bridge {
private:
    PayOff* PayOffPtr;

public:
    Bridge(const Bridge& source){
        PayOffPtr = source.PayOffPtr->clone();
    }
    Bridge(const PayOff& source){
        PayOffPtr = source.clone();
    }
    double operator() (double Spot) const{
        return PayOffPtr->operator()(Spot);
    }
    ~Bridge(){
        delete PayOffPtr;
    }
    Bridge& operator = (const Bridge& source){
        if (this == &source){
            return *this;
        } else {
            delete PayOffPtr;
            PayOffPtr = source.PayOffPtr->clone();
            return *this;
        }
    }

};


#endif //ADVANCEDVERSION_BRIDGE_H
