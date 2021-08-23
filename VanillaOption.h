//
// Created by MuYao Si on 2021-08-22.
//

#ifndef ADVANCEDVERSION_VANILLAOPTION_H
#define ADVANCEDVERSION_VANILLAOPTION_H

#include "PayOff.h"
#include "Bridge.h"
#include "Options.h"

class VanillaOption:public Options {
public:
    VanillaOption(const Bridge& sourcePayOff, double sourceExpiry, double sourceVol);
    double GetExpiry() const;
    double GetVol() const;
    double OptionPayOff(double Spot) const;

private:
    double Expiry;
    double Vol;
    Bridge PayOffBridge;
};


#endif //ADVANCEDVERSION_VANILLAOPTION_H
