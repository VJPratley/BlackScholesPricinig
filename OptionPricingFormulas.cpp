#include "OptionPricingFormulas.hpp"

namespace OptionPricing {

// Normal cumulative distribution function (for d1 and d2 calculations)
double normalCDF(double value) {
    return 0.5 *( 1+std::erf(value/sqrt(2)));
}

// Pricing a forward contract
double priceForward(double S, double K, double T, double r, double q) {
    return S * exp(-q * T) - K * exp(-r * T);
}

// Pricing a European call option
double priceCall(double S, double K, double T, double r, double q, double v) {
    double d1 = (log(S / K) + (r - q + 0.5 * v * v) * T) / (v * sqrt(T));
    double d2 = d1 - v * sqrt(T);
    return S * exp(-q * T) * normalCDF(d1) - K * exp(-r * T) * normalCDF(d2);
}

// Pricing a European put option
double pricePut(double S, double K, double T, double r, double q, double v) {
    double d1 = (log(S / K) + (r - q + 0.5 * v * v) * T) / (v * sqrt(T));
    double d2 = d1 - v * sqrt(T);
    return K * exp(-r * T) * normalCDF(-d2) - S * exp(-q * T) * normalCDF(-d1);
}

// Pricing a digital call option
double priceDigitalCall(double S, double K, double T, double r, double q, double v) {
    double d2 = (log(S / K) + (r - q - 0.5 * v * v) * T) / (v * sqrt(T));
    return exp(-r * T) * normalCDF(d2);
}

// Pricing a digital put option
double priceDigitalPut(double S, double K, double T, double r, double q, double v) {
    double d2 = (log(S / K) + (r - q - 0.5 * v * v) * T) / (v * sqrt(T));
    return exp(-r * T) * normalCDF(-d2);
}

// Pricing a zero-coupon bond
double priceZeroCouponBond(double T, double r) {
    return exp(-r * T);
}

} 