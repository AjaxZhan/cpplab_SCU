/**
 * @brief Responsible for interacting with users
 * @version 1.0
 * @author CagurZhan
*/
#ifndef _UI_CONTROLLER_
#define _UI_CONTROLLER_
#include <iostream>
#include <string>
#include "Expression.h"
using namespace std;
/**
 * @brief Responsible for user interaction
 * @version 1.0
 * @author CagurZhan
*/
class UIController{
public:
    Expression expression; // expression
    
    void init();
    void menu();
    void checkInput();
    void help();
    void ifContinue();
    UIController(){
    }
private:
    int input; // menu choice
    string exp;
};

#endif