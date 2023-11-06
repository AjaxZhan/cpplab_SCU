#include "../includes/MathService.h"

double MathService::add(double a, double b){
    return a + b;
}

double MathService::sub(double a, double b){
    return a - b;
}

double MathService::mul(double a, double b){
    return a *b ;
}

double MathService::div(double a, double b){
    if(b == 0) throw runtime_error(MathExceptionEnum::DIVISOR_ZERO_ERROR);
    return a / b ;
}

double MathService::mod(double a, double b){
    // a or b is not Integer.
    if(abs(a - static_cast<long long>(a)) > GlobalEnum::ACCURACY
    || abs(b - static_cast<long long>(b)) > GlobalEnum::ACCURACY)
        throw runtime_error(MathExceptionEnum::MOD_ERROR);
    
    if(abs(b) <= GlobalEnum::ACCURACY)
        throw runtime_error(MathExceptionEnum::MOD_ZERO_ERROR);
    
    return static_cast<long long>(a) % static_cast<long long>(b);
}
