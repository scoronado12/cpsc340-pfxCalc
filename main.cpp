#include <iostream>
#include <stack>
#include <string>

using namespace std;

int stackProcessor(string pfxExpression);


int main(){
    
    string pfxIn;
    int resultant;
    
    while (true){
        cout << "Enter a postfix expression or quit to exit:";
        getline(cin,pfxIn);
        
        if (pfxIn == "exit" || pfxIn == "quit"){
            exit(0);
        }else {
            stackProcessor(pfxIn);
//             cout << resultant;
        }
        
    }

    return 0;
}

int stackProcessor(string pfxExpression){
    
    stack <char> myStack;
    
    for (char c: pfxExpression){
        cout << c << endl;
    }
    
    return 0;
}
