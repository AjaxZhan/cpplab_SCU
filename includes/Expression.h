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
    /** Convert inFixExp to RPN*/
    void inFixExpToRPN();

    /** Calculate by RPN. */
    double calculate();

    /** Check user's input. */
    void checkValidation();

    /** Print the result. */
    void printResult(){
        cout << "运算器正在紧张工作中......\n运算执行完成啦！" <<endl;
        cout << "您输入的表达式为: "<< userExp << endl;
        cout << "该表达式的逆波兰式为: " << getRPNString() << endl;
        cout << "该表达式的计算结果为: " << resCache << endl; 
    }

    /** Return the string of RPN. */
    string getRPNString(){
        string res = "";
        for(auto &x : RPN){
            res+=x;
            res+=" ";
        }
        return res;
    }
    
    /** Constuctor */
    Expression(){}
    Expression(string expstr){
        this->userExp = expstr;
        this->mathService = MathService();
    }

    /** Destructor */
    ~Expression(){}

private:
    double resCache = -1; // 结果
    string userExp;  // 用户输入的表达式
    vector<string> RPN; // 逆波兰式
    MathService mathService;
};

#endif