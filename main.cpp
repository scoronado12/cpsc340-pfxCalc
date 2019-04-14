#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>


using namespace std;

void stringProcessor(string pfxExpression, stack <double> &mystl, stack <string> &operadores);
float operate(double operand1, double operand2, string operador);
void cleanStacks(stack <double> &mystl, stack <string> &operadores);
bool isOperator(string spot);

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

void stringProcessor(string pfxExpression, stack <double> &mystl, stack <string> &operadores){
    
    
    stringstream expressionIn(pfxExpression);
    vector<string> contents;
    string thing = "";
    double solution;
    
    //pump everything, including spaces to stringstream as strings
    while (expressionIn.good() && !expressionIn.eof()){
        expressionIn >> thing;
        contents.push_back(thing);
    }
    //format check  
    for (int i = 0 ; i < contents.size(); i++){
        cout << "checking " << contents.at(i) << endl;
        if (!(isOperator(contents.at(i)) || contents.at(i) == " " || isdigit(contents.at(i).at(0)))){
            cout << "Invalid Expression!" << endl;
            cout << "First check failed" << endl;
            main();
        }
    }
    //stack adding
    for (int i = 0; i < contents.size(); i++) {
        if (isOperator(contents.at(i))){
            operadores.push(contents.at(0));
        } else if (isdigit(contents.at(i).at(0))){ // I know this looks dirty but isdigit doesn't like smashing the entire number in there
            mystl.push(stod(contents.at(i)));
        }
    }
    
    /*if mystl < operator */
    
    if (mystl.size() > operadores.size()){
        cout << "stacks have a good ratio" << endl;
    }else {
        cout << "Invalid Expression!" << endl;
        cout << "second check failed" << endl;
        cout << "mystl " << mystl.size() << endl;
        cout << "operators " << operadores.size() << endl;
        cleanStacks(mystl, operadores); // clean up just in case
        main();
    }
    //time to empty all of them doing an operation
     while (!(mystl.empty() && operadores.empty())){
         cout << "working through it" << endl;
         double operand1 = mystl.top();
         mystl.pop();
         double operand2 = mystl.top();
         mystl.pop();
         
         string operador = operadores.top();
         operadores.pop();
         
         solution = solution + operate(operand1, operand2, operador);
         
     }
     
     cleanStacks(mystl, operadores);
    
    
    
    
    
    expressionIn.clear(); //clear stringstream
    
     cout << solution << endl;
    
}

void cleanStacks(stack <double> &mystl, stack <string> &operadores){
    while (!mystl.empty()){
        mystl.pop();
    }
    
    while (!operadores.empty()){
        operadores.pop();
    }
    
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
