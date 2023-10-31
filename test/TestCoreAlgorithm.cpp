#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
/**
 * 逆波兰表达式：中序表达式的二叉树的后序遍历。
 * 算法；
 *  遇见数字入栈
 *  遇到操作符，从栈取元素计算，然后加入栈。
 *  计算结果就是栈的最后一个元素。
*/

void toInfixExpList(){
    string exp = "1+((2+3)*4)-5";
    vector<string> v;
    int i = 0;
    string tmp; // comcat multiply bit number
    for(auto& c : exp ){
        
    }
}

int main(){
    

    return 0;
}