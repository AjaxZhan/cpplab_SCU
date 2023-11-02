#ifndef _ENUM_
#define _ENUM_

/**
 * @brief Define global enums and constants.
 * @version 1.0
 * @author CagurZhan
*/

#include <string>
#include <set>
#include <unordered_map>

using namespace std;

namespace ExpressionEnum {
    const string ILLEGAL_CHARACTER_ERROR = "请勿输入非法字符";
    const string ILLEGAL_SPACE_ERROR = "表达式不应该含有空格";
    const string MISSING_OPERATOR_ERROR = "运算符错误，请检查您的输入"; 
    const string MISSING_OPERAND_ERROR = "运算单元错误，请检查您的运算单元"; 
    const string BUCKET_ERROR = "括号不匹配";
    const string COMMON_ERROR = "未知错误，请检查表达式";
}

namespace GlobalEnum {
    const double PI = 3.14159265358979323846;
    const double ACCURACY = 1e-3;
    const set<char> ILLEGAL_OPERAND = {'+','-','*','/','%','#'};
    const unordered_map<char,int> operatorPriority{
        {'+',1},
        {'-',1},
        {'*',2},
        {'/',2},
        {'%',2},
        {'(',0}
    };
    
}

namespace MathExceptionEnum {
    const string DIVISOR_ZERO_ERROR = "除数不能为零";
    const string MOD_ERROR = "模运算操作数需要两个整数！";
    const string MOD_ZERO_ERROR = "模运算的第二个操作数不能为0";
    const string COMMON_ERROR = "未知错误，请检查表达式是否正确";
}

#endif