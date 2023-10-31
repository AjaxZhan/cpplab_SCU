#ifndef _STACK_SELF_
#define _STACK_SELF_
#include <iostream>
using namespace std;
#define DEFAULT_SIZE 100

/**
 * @brief Simple self-implementation stack class.
 * @version 1.0
 * @author CagurZhan
*/
template<class T>
class Stack{

private:
    /** Store item in stack. */
    T* items;
    
    /** Top pointer. */
    int sp;

    /** Capacity of the stack .*/
    /** It can be use to resize the items, but I have not implement yet. */
    int capacity;

public:
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