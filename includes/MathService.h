/**
 * @brief Encapsulate math operations and perform it. 
 * @version 1.0
 * @author CagurZhan
*/
#ifndef _MATH_SERVICE_
#define _MATH_SERVICE_

#include <iostream>
#include "Enum.h"

using namespace std;

class MathService {

public:
    double add(double a, double b);
    double sub(double a, double b);
    double mul(double a, double b);
    double div(double a, double b);
    double mod(double a, double b);
};

#endif