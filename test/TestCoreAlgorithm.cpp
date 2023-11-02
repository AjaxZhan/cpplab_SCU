#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include "../includes/Enum.h"

using namespace std;

// 给定逆波兰式，计算其值
double calculate(vector<string>& tokens){
    stack<double>st;
    for(auto &item : tokens){
        if(item == "+" || item == "-" || item == "*" || item == "/") {
            auto a = st.top();
            st.pop();
            auto b = st.top();
            st.pop();
            if(item == "+") st.push(a+b);
            else if(item == "-") st.push(b-a);
            else if(item == "*") st.push(a*b);
            else if(item == "/") st.push(b/a);
        }else{
            st.push(stod(item));
        }
    }
    double res = st.top();
    st.pop();
    return res;
}

// 检查表达式是否合法
void checkValidation(string &infixToken) {
    bool lastBucket = 1; // 0: left,  1 :right
    char buckNum = 0;
    bool lastpoint = false;
    for(auto &c: infixToken){
        // 表达式携带空格，不合法
        if(c == ' ') throw runtime_error(ExpressionEnum::ILLEGAL_SPACE_ERROR);

        // 表达式含有非法字符
        if(!(isdigit(c) || c== '+' || c=='-' || c=='*' || c=='/' || c=='#' || c=='(' || c==')' || c=='.' )){
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
        if(c== '('){
            // 上一个括号是 '('
            if(!lastBucket) throw runtime_error(ExpressionEnum::BUCKET_ERROR);
            buckNum++;
            lastBucket = !lastBucket;
        }else if(c == ')'){
            // 上一个括号是 ')'
            if(lastBucket) throw runtime_error(ExpressionEnum::BUCKET_ERROR);
            buckNum++;
            lastBucket = !lastBucket;
        }


    }

    // 括号不合法
    if(buckNum && buckNum%2!=0) throw runtime_error(ExpressionEnum::BUCKET_ERROR); 
}

// 给定中缀表达式，转换为后缀表达式
vector<string> toPostFix(string &infixToken) {
    stack<char> stk;
    string numCache = "";
    vector<string> res;
    for(auto& c : infixToken){
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
    return res;
}

int main(){
    
    // 中缀表达式：
    string inFixExp = "(2.5-#1)*(3.5+4.5)";
    checkValidation(inFixExp);
    // 后缀表达式
    vector<string> res = toPostFix(inFixExp);

    cout << "Expression is : ";
    // 转换为后缀表达式
    for(auto &x:res){
        cout << x << " ";
    }
    cout << endl;

    cout << "res is " << calculate(res) << endl;

    return 0;
}