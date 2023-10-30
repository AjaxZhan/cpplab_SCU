#include "Stack.h"
using namespace std;

int main(){
    Stack<int> s(100);
    s.push(100);
    s.push(200);
    s.push(300);
    s.push(400);

    cout << "s.size()" << s.size() << endl;

    while(!s.empty()){
        cout << s.pop() << " ";
    }
    cout << endl;
    
    cout << "isempty , 1 is yes : " << s.empty() << endl;

    cout  << "now s.size is "<< s.size() << endl;



    return 0;
}