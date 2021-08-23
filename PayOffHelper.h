//
// Created by MuYao Si on 2021-08-22.
//

#ifndef ADVANCEDVERSION_PAYOFFHELPER_H
#define ADVANCEDVERSION_PAYOFFHELPER_H

#include <iostream>
#include <string>
#include "PayOff.h"
#include "PayOffFactory.h"
using namespace std;

template <class T>
class PayOffHelper {
public:
    static PayOff* import(double Strike){
      return new T(Strike);
    };
    PayOffHelper(string PayOffName){
        PayOffFactory& theFactory = PayOffFactory::getInstance();
        theFactory.RegisterPayOff(PayOffName, import);
    };
};


#endif //ADVANCEDVERSION_PAYOFFHELPER_H
