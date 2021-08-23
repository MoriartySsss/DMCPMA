//
// Created by MuYao Si on 2021-08-22.
//

#include "MonteCarloEngine.h"


double MonteCarloEngine(Options* sourceOption,
                        double Spot,
                        unsigned long NumberOfPaths)
{
    double Vol = sourceOption->GetVol();
    double Expiry = sourceOption->GetExpiry();
    double r = sourceOption->GetRiskFreeRate();
    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    double movedSpot = Spot * exp(r*Expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;

    for(unsigned long i =0; i < NumberOfPaths; i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp(rootVariance*thisGaussian);
        double thisPayoff = sourceOption->OptionPayOff(thisSpot);
        thisPayoff = thisPayoff>0?thisPayoff:0;
        runningSum += thisPayoff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}

