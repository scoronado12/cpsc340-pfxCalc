#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

void stringProcessor(string pfxExpression, stack <double> &mystl);
float operate(double operand1, double operand2, string operador);
bool isOperator(string spot);

int main(){
    string pfxIn;
    int resultant;
    stack <double> mystl;

    while (true){
        cout << "Enter a postfix expression or quit to exit:";
        getline(cin,pfxIn);
        if (pfxIn == "exit" || pfxIn == "quit"){
            exit(0);
        }else {
            stringProcessor(pfxIn, mystl);
        }
    }

    return 0;
}

void stringProcessor(string pfxExpression, stack <double> &mystl){
    stringstream expressionIn(pfxExpression);
    vector<string> contents;
    int i = 0;
    double operand1 = 0;
    double operand2 = 0;
    string thing = "";
    while (expressionIn.good()){
        expressionIn >> thing;
        contents.push_back(thing);
        

        if (isdigit(thing.at(0))) {
            //push to the stack
             mystl.push(stod(contents.at(i)));
        } else if (isOperator(thing)){
            
            //pop stack twice if empty or see a beautiful segmentation fault
            if (!mystl.empty()){
                operand1 = mystl.top();
                mystl.pop();
                if (!mystl.empty()){
                    operand2 = mystl.top();
                    mystl.pop(); 
                } else {
                    cout << "Invalid Operation" << endl;
                    main();
                }
            }
            
        } else {
            cout << "Invalid Expression" << endl;
            main();
        }
        i++;
    }
    
    expressionIn.clear(); //clear string stream
    cout << operate(operand1 , operand2, thing) << endl;
    
}

float operate(double operand1, double operand2, string operador){
    //operator is operador in spanish because the word operator is reserved
    
    if (operador == "+") {
        return operand1 + operand2;
    } else if (operador == "-"){
        return operand2 - operand1;
    } else if (operador == "/"){
        return operand2 / operand1;
    } else if (operador == "^"){
        return pow(operand2,operand1);
    } else if (operador == "*"){
        return operand1 * operand2;
    }
        
    return 0;
    
    
    
}


bool isOperator(string spot){
    if (spot == "+" || spot == "-" || spot == "*" || spot == "/" || spot == "^"){
        return true;
    }
    return false;

}
