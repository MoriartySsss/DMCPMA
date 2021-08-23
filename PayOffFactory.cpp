//
// Created by MuYao Si on 2021-08-22.
//

#include "PayOffFactory.h"
#include <iostream>
using namespace std;

PayOffFactory &PayOffFactory::getInstance() {
    static PayOffFactory theFactory;
    return theFactory;
}

void PayOffFactory::RegisterPayOff(string PayOffName, PayOffFactory::PayOffFunction sourcePayOffFunctionPtr) {
    PayOffPool.insert(pair<string, PayOffFunction> (PayOffName, sourcePayOffFunctionPtr));
}

PayOff* PayOffFactory::CallOutPatOff(string PayOffName, double Strike) {
    map<string, PayOffFunction>::const_iterator iter = PayOffPool.find(PayOffName);
    if (iter == PayOffPool.end()){
        cout << PayOffName << " is not in the pool, please register the payoff or add it into an imported dataset" << endl;
        return NULL;
    } else {
        return (iter->second)(Strike);
    }
}

PayOffFactory::~PayOffFactory() {

}
