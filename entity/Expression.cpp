#ifndef EXPRESSION
#define EXPRESSION

#include <iostream>
using namespace std;

/**
 * @brief Store the input of the user, provide calculate method to get result. 
 * @version 1.0
 * @author CagurZhan
*/
// TODO
class Expression {

public:
    /** User's input expression.  */
    string expStr;

    /** Calculate the expression and return the result. */
    double calculate();

    /** Constuctor */
    Expression(string exp){

    }

    /** Destructor */
    ~Expression(){

    }



private:
    double resCache;

};

#endif