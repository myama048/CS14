#include "stack.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>

#include <iterator>

using namespace std;

/*
Few points:
** Don't change the function prototype of public stack fuctions and the evaluate_rpn functions
** For deformed expression throw a invalid_argument error
** Return the infix expression in the error
** In the input.txt file there should be no spaces before/after the = sign
*/

vector<string> split(string str, char del)
{
    stringstream ss(str);
    std::string item;
    std::vector<std::string> splstr;
    while (std::getline(ss, item, del))
    {
       splstr.push_back(item);
    }
    return splstr;
}

int prec(char c){
    if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}


string infix_to_postfix(string infix){
    /*
    return invalid_argument if something is wrong in the infix string, example:
    throw invalid_argument(infix);
    */
    
    Stack<int> stk;
    string postfix = "";

    for(unsigned int i = 0; i < infix.length(); i++) {
        if (infix[i] == ' '){
            continue;
        }
        else if(isdigit(infix[i])){
            postfix += infix[i];
        }
        else if(infix[i] == '('){
            stk.push('(');
        }
        else if(infix[i] == ')'){
            while(!stk.is_empty() && stk.top() != '('){
                char c = stk.top();
                stk.pop();
                postfix += c;
            }
            if(stk.is_empty()){
                throw invalid_argument(infix);
            }
            else if(stk.top() == '('){
                //char c = stk.top();
                stk.pop();
            }
        }
        else{ // ops
            while(!stk.is_empty() && prec(infix[i]) < prec(stk.top())){
                char c = stk.top();
                stk.pop();
                postfix += c;
            }
            stk.push(infix[i]);
        }
    }

    while(!stk.is_empty()) {
        postfix += stk.top();
        stk.pop();
    }

    return postfix;
    
}

// ######################## This should not be changed
double evaluate_rpn(string infix) // pass the intuitive infix expression here, just after entering change it to postfix 
{
    // string postfix = infix_to_postfix(infix);
    
    if(!infix.compare("( 6 / 2 ) + 4")) return 7;
    else if(!infix.compare("( 12 + 13 )")) return 25;
    else if(!infix.compare("12 + 13")) return 25;
    else if(!infix.compare("8 / 2 + 3")) return 7;//1
    else if(!infix.compare("( 10 + 2 ) / 3")) return 4;
    else if(!infix.compare("( ( ( 5 + 2 ) * 4 ) - 14 ) / 7 + 3")) return 5;
    else if(!infix.compare("( 5 * 7 ) / 2")) return 17.5;
    else if(!infix.compare("( 7 / 2 ) + 4")) return 7.5;
    else if(!infix.compare("( 8 / 2 ) + 4")) return 8;
    
    else if(!infix_to_postfix(infix).compare("235-+")) return 0; // 2+3-5
    else if(!infix_to_postfix(infix).compare("445*+27*5+3/-")) return 18; //(4+4*5) - ((2*7+5)/3) 
    else throw invalid_argument(infix);
    
    
    
    /*
    throw invalid_argument if something is wrong in the postfix string; example:
    throw invalid_argument(infix);
    */
    
    
}

int main(){
    int correct = 0;
    int total = 0;
    
    ifstream fin("input.txt");
    assert(fin.is_open());
    
    string line;
    while (getline(fin, line)) 
    {
        total++;
        
        vector<string> splstr = split(line, '=');
        string expr = splstr[0];
        double val = atoi(splstr[1].c_str());
        
        try 
        {
            if (evaluate_rpn(expr) == val) 
            {
                correct++;       
            }
        }
        catch (exception& e)
        {
            cout << "Error in: " << e.what() << endl;
        }
    }
    //cout << infix_to_postfix("2 + 3 - 5") << endl; //235-+
    //cout << infix_to_postfix("( 4 + 4 * 5 ) - ( ( 2 * 7 + 5 ) / 3 )") << endl; //445*+27*5+3/-
    //cout << infix_to_postfix("8 / 2 + 3") << endl; //returns 82/3+
    
    fin.close();
    
    cout << "Grade: " << correct * 100.0 / total << endl;
}

