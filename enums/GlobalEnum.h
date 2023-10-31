/**
 * @brief Some global constant.
 * @version 1.0
 * @author CagurZhan
*/
#ifndef GLOBAL_ENUM
#define GLOBAL_ENUM

#include <set>
using namespace std;

namespace GlobalEnum {
    const double PI = 3.14159265358979323846;
    const set<char> ILLEGAL_OPERAND = {'+','-','*','/','^','%','#'};    
}

#endif