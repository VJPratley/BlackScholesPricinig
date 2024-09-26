#ifndef OptionPricingFormulas_hpp
#define OptionPricingFormulas_hpp

#include <cmath>

namespace OptionPricing {

// Helper function
double normalCDF(double value);

// Pricing functions
double priceForward(double S, double K, double T, double r, double q);
double priceCall(double S, double K, double T, double r, double q, double v);
double pricePut(double S, double K, double T, double r, double q, double v);
double priceDigitalCall(double S, double K, double T, double r, double q, double v);
double priceDigitalPut(double S, double K, double T, double r, double q, double v);
double priceZeroCouponBond(double T, double r);

} 

#endif 
