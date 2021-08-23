//
// Created by MuYao Si on 2021-08-22.
//

#ifndef ADVANCEDVERSION_MONTECARLOENGINE_H
#define ADVANCEDVERSION_MONTECARLOENGINE_H


#include <cmath>
#include <algorithm>
#include "Random1.h"
#include "Options.h"

double MonteCarloEngine(Options* sourceOption,
                        double Spot,
                        unsigned long NumberOfPaths);

#endif //ADVANCEDVERSION_MONTECARLOENGINE_H
