#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>


/** @author scoronado
 *  @since 2019-04-06
 *  POST FIX CALCULATOR
 */


using namespace std;

void stringProcessor(string pfxExpression, stack <double> &mystl, stack <string> &operadores);
float operate(double operand1, double operand2, string operador);
void cleanStacks(stack <double> &mystl, stack <string> &operadores);
bool isOperator(string spot);


/**
 * main() - front facing user input
 * @return 0 - signifying a proper Unix exit code
 */


int main(){
    string pfxIn;
    int resultant;
    stack <double> mystl;
    stack <string> operadores;

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
 * 
 */


void stringProcessor(string pfxExpression, stack <double> &mystl, stack <string> &operadores){
    stringstream expressionIn(pfxExpression);
    vector<string> contents;
    string thing = "";
    double solution = 0;
    //pump everything, including spaces to stringstream as strings
    while (expressionIn.good() && !expressionIn.eof()){
        expressionIn >> thing;
        contents.push_back(thing);
    }
    //format check - used some 326 logic here
    for (int i = 0 ; i < contents.size(); i++){
//         cout << "checking " << contents.at(i) << endl;
        if (!(isOperator(contents.at(i)) || contents.at(i) == " " || isdigit(contents.at(i).at(0)))){
            cout << "Invalid Expression!" << endl;
//              cout << "First check failed" << endl;
            main();
        }
    }
    //stack adding
    for (int i = 0; i < contents.size(); i++) {
        if (isOperator(contents.at(i))){
            operadores.push(contents.at(i));
        } else if (isdigit(contents.at(i).at(0))){ // I know this looks dirty but isdigit doesn't like the entire number in there as an int/double/etc
            mystl.push(stod(contents.at(i)));
        }
    }

    /*if mystl < operator */
    
    if ((mystl.size() < operadores.size() || (/*TODO 1 2 3 4 * must be caught */) )){ // 2nd format check check if expression is invalid
        cout << "Invalid Expression!" << endl;
        cleanStacks(mystl, operadores); // clean up just in case
        main();
//         cout << "second check failed" << endl;
//         cout << "mystl " << mystl.size() << endl;
//         cout << "operators " << operadores.size() << endl;
    }
    //time to empty all of them doing an operation
     double operand2 = 0;
     while (!(mystl.empty())){

         double operand1 = mystl.top();
         mystl.pop();
         if (mystl.empty()){
            //TODO check if this needs to be different
            solution = operate(operand1, solution, operadores.top());
            operadores.pop();
         }else {
             operand2 = mystl.top();
             mystl.pop();
         }
         if (!operadores.empty()){
            string operador = operadores.top();
            operadores.pop();
            solution = solution + operate(operand1, operand2, operador);
         } /*else {
             cout << "Invalid Expression!" << endl;
             cout << "Third check" << endl;
             cleanStacks(mystl, operadores);
             main();
         }*/
     }
     cleanStacks(mystl, operadores); //empty them just in case.
     expressionIn.clear(); //clear stringstream
     cout << solution << endl;
}


/** Clean Stacks - sequentially takes two stacks and empties them.
 * @param stack <double> mystl - Stack of nums
 * @param operadores <string> - stack of operators
 */

void cleanStacks(stack <double> &mystl, stack <string> &operadores){
    while (!mystl.empty()){
        mystl.pop();
    }
    
    while (!operadores.empty()){
        operadores.pop();
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
        return operand2 / operand1;
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
