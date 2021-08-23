//
// Created by MuYao Si on 2021-08-22.
//

#ifndef ADVANCEDVERSION_PAYOFF_H
#define ADVANCEDVERSION_PAYOFF_H


class PayOff {
public:
    PayOff();
    virtual double operator() (double sourceSpot) const = 0;
    virtual ~PayOff();
    virtual PayOff* clone() const = 0;
};

class PayOffCall: public PayOff{
public:
    PayOffCall(double sourceStrike);
    virtual double operator() (double sourceSpot) const;
    virtual ~PayOffCall();
    virtual PayOff* clone() const;

private:
    double Strike;
};

class PayOffPut:public PayOff{
public:
    PayOffPut(double sourceStrike);
    virtual double operator() (double sourceSpot) const;
    virtual ~PayOffPut();
    virtual PayOff* clone() const;

private:
    double Strike;
};

#endif //ADVANCEDVERSION_PAYOFF_H
