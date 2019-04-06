#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    
    string pfxIn;
    int resultant;
    
    while (true){
        cout << "Enter a postfix expression or quit to exit:" << endl;
        getline(cin,pfxIn);
        
        if (pfxIn == "exit" || pfxIn == "quit"){
            exit(0);
        }else{
            resultant = stackProcessor(pfxIn);
            cout << resultant;
        }
        
    }

    return 0;
}

int stackProcessor(string pfxExpression){
    
    
}
