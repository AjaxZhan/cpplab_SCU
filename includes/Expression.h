#ifndef _EXPRESSION_
#define _EXPRESSION_

#include <iostream>
#include "Stack.h"
#include "MathService.h"
#include <vector>

using namespace std;

/**
 * @brief Store the input of the user, provide calculate method to get result. 
 * @version 1.0
 * @author CagurZhan
*/
class Expression {

public:
    
    void tranToPostOrder();
    double calculate();
    void checkValidation();

    /** Print the result. */
    void printResult(){
        cout << "你输入的表达式为: "<< userExp << endl;
        cout << "该表达式的逆波兰式是：" << postOrderExp << endl;
        cout << "表达式计算结果为: " << resCache << endl; 
    }

    /** Constuctor */
    Expression(){}
    Expression(string expstr){
        this->userExp = expstr;
    }

    /** Destructor */
    ~Expression(){}

private:
    double resCache = -1; // resCache
    string userExp;  // Expression
    string postOrderExp;
};

#endif