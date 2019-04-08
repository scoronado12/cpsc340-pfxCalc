#include <iostream>
#include <stack>
#include <string>
#include <cctype> //for isdigit()
#include <cmath> //for pow() func
#include <cstdlib> //atof(char num)

using namespace std;

void stringParser(string pfxExpression, stack <double> myStack); //parseLine
void addToStack(double);
double operate();


int main(){
    string pfxIn;
    int resultant;

    stack <double> myStack;

    while (true){
        cout << "Enter a postfix expression or quit to exit:";
        getline(cin,pfxIn);
        if (pfxIn == "exit" || pfxIn == "quit"){
            exit(0);
        }else {
            stringParser(pfxIn, myStack);
        }
    }

    return 0;
}


void stringParser(string pfxExpression, stack <double> myStack){


    for (char c: pfxExpression){
        cout << c << endl;
    }

}
