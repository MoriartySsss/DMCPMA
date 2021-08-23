//
// Created by MuYao Si on 2021-08-23.
//

#ifndef ADVANCEDVERSION_OPTIONS_H
#define ADVANCEDVERSION_OPTIONS_H


class Options {
private:
    double RiskFreeRate = 0.08;
public:
    virtual double GetExpiry() const = 0;
    virtual double GetVol() const = 0;
    virtual double& GetRiskFreeRate(){return RiskFreeRate;};
    virtual double OptionPayOff(double Spot) const = 0;
};


#endif //ADVANCEDVERSION_OPTIONS_H
