/**
 * 定义算术异常相关枚举
*/

#ifndef MAX_EXCEPTION_ENUM
#define MAX_EXCEPTION_ENUM
#include <string>
using namespace std;

namespace MathExceptionEnum {
    const string DIVISOR_ZERO_ERROR = "除数不能为零";
    const string MOD_ERROR = "模运算操作数需要两个整数！";
    const string LOG_ERROR = "对数的真数必须为正数";
    const string COMMON_ERROR = "未知错误，请检查表达式是否正确";
}


#endif