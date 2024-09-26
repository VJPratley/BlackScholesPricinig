#include <iostream>
#include "OptionPricingFormulas.hpp"

int main() {
    double S = 100.0;  // Spot price
    double K = 100.0;  // Strike price
    double T = 1;    // Time to maturity (1 year)
    double r = 0.05;   // Risk-free rate (5%)
    double q = 0.02;   // Dividend yield (2%)
    double v = 0.2;    // Volatility (20%)

    
    std::cout << "Forward price: " << OptionPricing::priceForward(S, K, T, r, q) << std::endl;
    std::cout << "Call option price: " << OptionPricing::priceCall(S, K, T, r, q, v) << std::endl;
    std::cout << "Put option price: " << OptionPricing::pricePut(S, K, T, r, q, v) << std::endl;
    std::cout << "Digital call option price: " << OptionPricing::priceDigitalCall(S, K, T, r, q, v) << std::endl;
    std::cout << "Digital put option price: " << OptionPricing::priceDigitalPut(S, K, T, r, q, v) << std::endl;
    std::cout << "Zero-coupon bond price: " << OptionPricing::priceZeroCouponBond(T, r) << std::endl;

    return 0;
}