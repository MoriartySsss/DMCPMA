//
// Created by MuYao Si on 2021-08-22.
//

#ifndef ADVANCEDVERSION_PAYOFFFACTORY_H
#define ADVANCEDVERSION_PAYOFFFACTORY_H

#include <map>
#include <string>
#include "PayOff.h"
using namespace std;


class PayOffFactory
{
public:
    typedef PayOff* (*PayOffFunction) (double Strike); // the pointer of the constructor
    static PayOffFactory& getInstance();
    void RegisterPayOff(string PayOffName,PayOffFunction sourcePayOffFunctionPtr);
    PayOff* CallOutPatOff(string PayOffName, double Strike);
    ~PayOffFactory();

private:
    map<string, PayOffFunction> PayOffPool;
    PayOffFactory()= default;
    PayOffFactory(const PayOffFactory& source) {};
    PayOffFactory& operator=(const PayOffFactory& source){ return *this;};
};

#endif //ADVANCEDVERSION_PAYOFFFACTORY_H
