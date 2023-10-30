/**
 * 功能：手动实现Stack
*/
#ifndef STACK_SELF
#define STACK_SELF
#include <iostream>
using namespace std;
#define DEFAULT_SIZE 100

template<class T>
class Stack{

private:
    T* items;
    int sp;
    int capacity;

public:
    /** Stack interface */
    Stack(int size=DEFAULT_SIZE);
    void push(T);
    T pop();
    T& top();
    int size();
    bool empty();
    bool full();

    ~Stack(){
        delete[] this->items;
    }

};

/** Constructor */
template<class T>
Stack<T>::Stack(int size){
    items = new T[size];
    capacity = size;
    sp = -1;
}

/**  Add item to the top. */
template<class T>
void Stack<T>::push(T item){
    if(full()) throw out_of_range("cannot push item into a full stack!");
    items[++sp] = item;
}

/** Remove item on the top and return its value. */
template<class T>
T Stack<T>::pop(){
    if(empty()) throw out_of_range("cannot remove item from a empty stack.");
    return items[sp--];
}

/** Return the top of the stack. */
template<class T>
T& Stack<T>::top(){
    if(empty()) throw out_of_range("Stack is empty.");
    return items[sp];
}

/** Return the size of the stack */
template<class T>
int Stack<T>::size(){
    return sp+1;
}

/** Check if the stack is empty. */
template<class T>
bool Stack<T>::empty(){
    return sp == -1;
}

/** Check if the stack is full. */
template<class T>
bool Stack<T>::full(){
    return sp == capacity + 1;
}


#endif