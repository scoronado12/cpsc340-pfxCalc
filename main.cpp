#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>


/** @author scoronado
 *  @since 2019-04-06
 *  POST FIX CALCULATOR
 */


using namespace std;

void stringProcessor(string pfxExpression, stack <double> &mystl, vector <string> &operadores);
float operate(double operand1, double operand2, string operador);
void cleanStacks(stack <double> &mystl);
bool isOperator(string spot);


/**
 * main() - front facing user input
 * @return 0 - signifying a proper Unix exit code
 */


int main(){
    string pfxIn;
    int resultant;
    stack <double> mystl;
    vector <string> operadores;

    while (true){
        cout << "Enter a postfix expression or quit to exit:";
        getline(cin,pfxIn);
        if (pfxIn == "exit" || pfxIn == "quit"){
            exit(0);
        }else {
            stringProcessor(pfxIn, mystl, operadores);
        }
    }

    return 0;
}

/**
 * stringProcessor
 *  @param stack <double> mystl - stack of numbers  - passed by reference
 *  @param stack <string> operadores - stack of operators - passed by reference
 */


void stringProcessor(string pfxExpression, stack <double> &mystl, vector <string> &operadores){
    stringstream expressionIn(pfxExpression);
    vector<string> contents;
    vector<string> nums;

    string thing = "";
    double solution = 0;
    //pump everything, including spaces to stringstream as strings
    while (expressionIn.good() && !expressionIn.eof()){
        expressionIn >> thing;
        contents.push_back(thing);
    }
    
    //replace E and PI with cmath constants
    for (int i = 0; i < contents.size(); i++) {
        if (contents.at(i) == "PI"){
            contents.at(i) = to_string(M_PI);
        } else if (contents.at(i) == "E"){
            contents.at(i) = to_string(M_E);
        }
    }
    
    
    //format check - used some 326 logic here
    for (int i = 0 ; i < contents.size(); i++){
         //cout << "checking " << contents.at(i) << endl;
        if (!(isOperator(contents.at(i)) || contents.at(i) == " " || isdigit(contents.at(i).at(0)))){
            cout << "Invalid Expression!" << endl;
//             cout << "First check" << endl;
            contents.clear();
            return;
        }
    //Scan contents to rule out bad expressions
    
    for (string thing: contents){
        if (isOperator(thing)){
            operadores.push_back(thing);
        } else if (isdigit(thing.at(0))){
            nums.push_back(thing); // vector of strings
        }
    }
    
    
    
    
        
        
    }
    
    
    
    if (nums.size() > operadores.size() * 2 || nums.size() == operadores.size()){
        cout << "Invalid Expression!" <<endl;
        contents.clear();
        nums.clear();
        operadores.clear();
    	return;
    }
    
    try {
        int i = 0;
        for (string thing: contents){
            if (isdigit(thing.at(0))){
                mystl.push(stod(thing));
            } else if (isOperator(thing)){ 
                while (mystl.size() > 1){
                    double op1 = mystl.top();
                    mystl.pop();
                    double op2 = mystl.top();
                    mystl.pop();
//                     cout <<"OPERATOR " << thing << endl;
                    solution = operate(op1,op2,operadores.at(i));
                    i++;
                    mystl.push(solution);
                }
                

            }
        }
    }catch (exception& e) {
        cout << "Invalid Expression" << endl;
        cleanStacks(mystl);
        nums.clear();
        operadores.clear();
        contents.clear();
        main();
    }
     cleanStacks(mystl); //empty them just in case.
     expressionIn.clear(); //clear stringstream
     nums.clear();
     operadores.clear();
     cout << solution << endl;
}


/** Clean Stacks - sequentially takes two stacks and empties them.
 * @param stack <double> mystl - Stack of nums
 */

void cleanStacks(stack <double> &mystl){
    while (!mystl.empty()){
        mystl.pop();
    }
}

/** Operate - Performs and operation on two nums and returns the result
 * @param operand1 - double
 * @param opearand2 - double
 * @param opeardor - string of the operator
 */


float operate(double operand1, double operand2, string operador){
    //operator is operador in spanish because the word operator is reserved
    if (operador == "+") {
        return operand1 + operand2;
    } else if (operador == "-"){
        return operand2 - operand1;
    } else if (operador == "/"){
        if (operand2 < operand1){
            return operand2 / operand1;
        } else {
            return operand1 / operand2;
        }
    } else if (operador == "^"){
        return pow(operand2,operand1);
    } else if (operador == "*"){
        return operand1 * operand2;
    }
    return 0;
}

/** isOperator - returns true if param is an operator
 *  @param spot - string
 */

bool isOperator(string spot){
    if (spot == "+" || spot == "-" || spot == "*" || spot == "/" || spot == "^"){
        return true;
    }
    return false;

}
