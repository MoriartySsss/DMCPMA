//
// Created by MuYao Si on 2021-08-22.
//

#include "VanillaOption.h"

VanillaOption::VanillaOption(const Bridge &sourcePayOff, double sourceExpiry, double sourceVol): PayOffBridge(sourcePayOff), Expiry(sourceExpiry), Vol(sourceVol)
{

}

double VanillaOption::GetExpiry() const {
    return Expiry;
}

double VanillaOption::GetVol() const {
    return Vol;
}

double VanillaOption::OptionPayOff(double Spot) const {
    return PayOffBridge(Spot);
}


