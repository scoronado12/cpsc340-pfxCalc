#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void stringProcessor(string pfxExpression);
bool isOperator(string spot);

int main(){
    string pfxIn;
    int resultant;


    while (true){
        cout << "Enter a postfix expression or quit to exit:" << endl;
        getline(cin,pfxIn);
        if (pfxIn == "exit" || pfxIn == "quit"){
            exit(0);
        }else {
            stringProcessor(pfxIn);
        }
    }

    return 0;
}

void stringProcessor(string pfxExpression){
    stringstream expressionIn(pfxExpression);
    
    vector<string> contents;
    int i = 0;
    while (expressionIn.good() && !expressionIn.eof()){
        string thing = "";
        expressionIn >> thing;
        
        if (isOperator(thing)){
            //add into a stack of operators
            
        } else if (isdigit(thing.at(0))) {
            //add into a stack of
        }
        
        i++;
        
    }
    
    expressionIn.clear();
}

bool isOperator(string spot){
    if (spot == "+" || spot == "-" || spot == "*" || spot == "/"){
        return true;
    }
    return false;

}
