#include "../includes/UIController.h"

/** Displayed  initialization information */
void UIController::init(){
    cout <<
        "                          _ooOoo_                               " <<  endl <<   
        "                         o8888888o                              " << endl <<  
        "                         88\" . \"88                            " << endl <<  
        "                         (| ^_^ |)                              " << endl <<  
        "                         O\\  =  /O                             " << endl <<  
        "                      ____/`---'\\____                          " << endl <<  
        "                    .'  \\|     |//  `.                         " << endl <<  
        "                   /  \\|||  :  |||//  \\                       " << endl <<  
        "                  /  _||||| -:- |||||-  \\                      " << endl <<  
        "                  |   | \\\\\\  -  /// |   |                    " << endl <<  
        "                  | \\_|  ''\\---/''  |   |                     " << endl <<  
        "                  \\  .-\\__  `-`  ___/-. /                     " << endl <<  
        "                ___`. .'  /--.--\\  `. . ___                    " << endl <<  
        "              ."" '<  `.___\\_<|>_/___.'  >'"".                 " << endl <<  
        "            | | :  `- \\`.;`\\ _ /`;.`/ - ` : | |               " << endl <<  
        "            \\  \\ `-.   \\_ __\\ /__ _/   .-` /  /             " << endl <<  
        "      ========`-.____`-.___\\_____/___.-`____.-'========        " << endl <<  
        "                           `=---='                              " << endl <<  
        "      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^        " << endl <<  
        " >>>>>>>>>>(♥◠‿◠)ﾉﾞ 欢迎来到表达式求值系统  ლ(´ڡ`ლ)<<<<<<<<<<" << endl <<  
        " >>>>>>>>>>佛祖保佑ლ     永无BUGლ   永不修改ლ       <<<<<<<<<<"<< endl << 
        " >>>>>>>>>>输入1进入系统   输入2查看帮助  输入0退出系统<<<<<<<<<<"<< endl;
    cin >> input;
    checkInput();
}

/** Check user's input */
void UIController::checkInput(){
    switch (input)
    {
    case 0: // Exit system
        cout << "拜拜了您，欢迎下次使用！" << endl;
        exit(0);
        break;
    case 1 : // handle expression

        // 1. input the expression
        cout << "请输入您想要计算的表达式，格式请看说明！" << endl;        
        cin >> this->exp;
        expression = Expression(this->exp);

        // 2. check validation
        try{
            expression.checkValidation();
        }catch(const runtime_error & e){
            cout << "表达式解析错误，错误原因：" << e.what() << endl;
            ifContinue();
            return ;
        }

        // 3. get RPN
        expression.inFixExpToRPN();

        // 4. calculate 
        expression.calculate();

        // 4. print the result
        expression.printResult();

        // 5. query if continue? 
        ifContinue();
        
        break;
    case 2: // Show help message
        help();
        ifContinue();
        break;
    default:
        menu();
        break;
    }
}

/** Show menus */
void UIController::menu(){
    cout <<
        " >>>>>>>>>>(♥◠‿◠)ﾉﾞ      系统菜单            ლ(´ڡ`ლ)<<<<<<<<<<" << endl <<  
        "      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^    " << endl <<  
        " >>>>>>>>>>            输入1进入系统                <<<<<<<<<<"<< endl <<
        " >>>>>>>>>>            输入2查看帮助                <<<<<<<<<<"<< endl <<
        " >>>>>>>>>>            输入0退出系统                <<<<<<<<<<"<< endl;
    cin >> input;
    checkInput();
}

/** Show help message. */
void UIController::help() {
    cout <<
        " >>>>>>>>>>(♥◠‿◠)ﾉﾞ      帮助信息            ლ(´ڡ`ლ)<<<<<<<<<<" << endl <<  
        "支持运算类型如下：加(+)、减(-)、乘(*)、除法(/)、取模(%)" << endl << 
        "支持的数字类型如下：自然数、负整数、全体浮点数" << endl << 
        "注意1：负数应该用#表示" << endl << 
        "注意2：系统不允许表达式带空格" << endl;
}

/** Ask user if continue. */
void UIController::ifContinue(){
    cout << "是否继续操作？输入1表示继续，否则退出。" << endl;
    int tmp;
    cin >> tmp;
    if(tmp == 1){
        cout <<endl;
        menu();
    }else{
        cout << "拜拜了您，欢迎下次使用！" << endl;
        exit(0);
    }
}
