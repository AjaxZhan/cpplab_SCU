/**
 * 定义表达式检测异常相关枚举
*/

#ifndef EXPRESSION_EXCEPTION_ENUM
#define EXPRESSION_EXCEPTION_ENUM

/**
 * @brief Define an expression exception-related enumeration
 * @version 1.0
 * @author CagurZhan
*/

#include <string>
using namespace std;

namespace ExpressionEnum {
    const string ILLEGAL_CHARACTER_ERROR = "请勿输入非法字符";
    const string MISSING_OPERATOR_ERROR = "缺少运算符";
    const string MISSING_OPERAND_ERROR = "缺少算子";
    const string BUCKET_ERROR = "括号不匹配";
    const string COMMON_ERROR = "未知错误，请检查表达式";
}

#endif