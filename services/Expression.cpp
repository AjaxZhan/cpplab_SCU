#include "../includes/Expression.h"

/**
 * @note Must be called after inFixExpToRPN()
 * @brief Calculate result from RPN
 * @return Expression result
 * @throw run_time_error if there exist arithmetic exception.
*/
double Expression::calculate(){
    Stack<double>st;
    for(auto &item : RPN){
        if(item == "+" || item == "-" || item == "*" || item == "/") {
            auto a = st.top();
            st.pop();
            auto b = st.top();
            st.pop();
            if(item == "+") st.push(mathService.add(a,b));
            else if(item == "-") st.push(mathService.sub(b,a));
            else if(item == "*") st.push(mathService.mul(a,b));
            else if(item == "/") st.push(mathService.div(b,a));
            else if(item == "%") st.push(mathService.mod(b,a));
        }else{
            st.push(stod(item));
        }
    }
    double res = st.top();
    st.pop();
    this->resCache = res;
    return res;
}


/**
 * @throw rum_time_error if expression is invalid.
*/
void Expression::checkValidation(){
    char buckNum = 0;
    bool lastpoint = false;
    for(auto &c: userExp){
        // 表达式携带空格，不合法
        if(c == ' ') throw runtime_error(ExpressionEnum::ILLEGAL_SPACE_ERROR);

        // 表达式含有非法字符
        if(!(isdigit(c) || c== '+' || c=='-' || c=='*' || c=='/' || c=='#' || c=='(' || c==')' || c=='.' || c=='%' )){
            throw runtime_error(ExpressionEnum::ILLEGAL_CHARACTER_ERROR);
        }

        // 判断是否输入了两个小数点
        if(c == '.'){
            if(lastpoint == true) throw runtime_error(ExpressionEnum::MISSING_OPERAND_ERROR);
            lastpoint = true;
        }else{
            lastpoint = false;
        }

        // 统计括号数量
        if(c== '(' || c==')')
            buckNum++;


    }

    // 括号不合法
    if(buckNum && buckNum%2!=0) throw runtime_error(ExpressionEnum::BUCKET_ERROR); 
}

/** 
 * @brief convert inFixExp to RPN
 * */
void Expression::inFixExpToRPN(){

    Stack<char> stk;
    string numCache = "";
    vector<string> res;
    for(auto& c : userExp){
        // 处理负数
        if(c == '#'){
            numCache.push_back('-');
        }
        // 数字 or 小数点，加入cache
        else if(isdigit(c) || c== '.'){
            numCache.push_back(c);
        }
        else if(c == '('){
            // res.push_back(string(1,c));
            stk.push(c);
            // 这里搞错了，导致一直segmentation fault，GPT也找不出来BUG
            // 最后是用GDB debug了好久，发现stk居然没有将(入栈，这导致了对空栈进行了pop操作，最后导致内存溢出。
        }else if(c == ')'){

            if(!numCache.empty()){
                res.push_back(numCache);
                numCache.clear();
            }

            while(!stk.empty() && stk.top()!='('){
                res.push_back(string(1,stk.top()));
                stk.pop();
            }
            stk.pop();
        }
         // 操作符，先将cache送入表达式，然后处理
        else if(GlobalEnum::ILLEGAL_OPERAND.count(c)){
            if(!numCache.empty()){
                res.push_back(numCache);
                numCache.clear();
            }
            while(!stk.empty() && GlobalEnum::operatorPriority.at(stk.top()) 
                >= GlobalEnum::operatorPriority.at(c) ){
                    res.push_back(string(1,stk.top()));
                    stk.pop();
            }
            stk.push(c);
        }
    }

    if(!numCache.empty()){
        res.push_back(numCache);
        numCache.clear();
    }

    while(!stk.empty()){
        res.push_back(string(1,stk.top()));
        stk.pop();
    }
    this->RPN = res;
}