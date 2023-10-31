/**
 * @brief Test the stack class. 
 * @version 1.0
 * @author CagurZhan
*/
#include "includes/Stack.h"
using namespace std;

/** A stupid test for my stack class. */
void testStack(){
    Stack<int> s(100);
    s.push(100);
    s.push(200);
    s.push(300);
    s.push(400);

    if(s.top()!=400) throw runtime_error("Fail to pass top() and push() test!");

    if(s.size() != 4) throw runtime_error("Fail to pass size() test!");

    while(!s.empty()){
        s.pop();
    }

    if(!s.empty()) throw runtime_error("Fail to pass empty() and pop() test!");

    cout << "Congratulation!  testStack() pass ! " << endl;
}

int main(){

    testStack();
    
    return 0;
}