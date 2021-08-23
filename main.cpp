#include <iostream>
#include "Random1.h"
#include "VanillaOption.h"
#include "Bridge.h"
#include "PayOff.h"
#include "PayOffFactory.h"
#include "PayOffHelper.h"
#include "MonteCarloEngine.h"


using namespace std;

int main() {
    // Here is an example of using this option management system
    // In this system, the payoff function is much more important than the option itself
    // Therefore the first step is declare the payoff function and register it into the factory
    //
    // Step 1
    //
    // Declare the payoff of the option as a derived class of "payoff"
    // It must include constructor, operator(), destructor, and the clone function
    // Let's consider a call option that if it is exercised, the seller should pay one dollar to the buyer
    // We call this kind option in our system "onecall"

    class PayOffOneCall:public PayOff{
    public:
        PayOffOneCall(double sourceStrike){ //the constructor
            Strike = sourceStrike;
        }
        virtual double operator() (double sourceSpot) const{ //operator()
            if (sourceSpot > Strike) {
                return 1.0;
            } else {
                return 0.0;
            }
        }
        virtual ~PayOffOneCall(){};
        virtual PayOffOneCall* clone() const{
            return new PayOffOneCall(*this);
        }
    private:
        double Strike;
    };

    //
    // Step 2
    //
    // Then register the payoff into the factory
    PayOffHelper<PayOffOneCall> RegisterOneCall("onecall");

    // Here are some examples of the default european call and put payoff
    PayOffHelper<PayOffCall> RegisterEuroCall("call");
    PayOffHelper<PayOffPut> RegisterEuroPut("put");

    //
    // Step 3
    //
    // Check the factory and call out the payoff and its pointer
    PayOff* OneCallPtr = PayOffFactory::getInstance().CallOutPatOff("onecall", 100);
    PayOff* CallPtr = PayOffFactory::getInstance().CallOutPatOff("call", 65);
    PayOff* PutPtr = PayOffFactory::getInstance().CallOutPatOff("put", 65);

    //
    // Step 4
    //
    // Then prepare the option class
    // Since the three options above involves the same parameters, the default VanillaOption would be useful
    // Remember, if you consider some exotic options, e.g. Asian option, please build the option by yourself
    // Using the "Bridge" API like what I did in "VanillaOption.h" would make things easier.
    //
    // We always want out clients to build the classes of the objects by themselves since different options may need different parameters

    VanillaOption OneCall(*OneCallPtr, 0.25, 0.3);
    VanillaOption EuroCall(*CallPtr, 0.25, 0.3);
    VanillaOption EuroPut(*PutPtr, 0.25, 0.3);
    VanillaOption* OneCallOptionPtr = &OneCall;
    VanillaOption* CallOptionPtr = &EuroCall;
    VanillaOption* PutOptionPtr = &EuroPut;

    //
    // Step 5
    //
    // Use the MonteCarlo Engine to compute the price of the options
    //

    double Expiry = 0.25;
    double Strike = 65;
    double Vol = 0.30;
    double r = 0.08;
    double Spot = 60;
    unsigned long NumberOfPaths = 50000;
    double result = MonteCarloEngine(CallOptionPtr, Spot, NumberOfPaths);
    std::cout << "This price is " << result << std::endl;
    std::cout << "The exact price is 2.13337" << std::endl;
    return 0;
}











