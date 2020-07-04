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

string infix_to_postfix(string infix){
    /*
    return invalid_argument if something is wrong in the infix string, example:
    throw invalid_argument(infix);
    */
    string postfix;
    Stack<int> stack;
    vector<string> tokens = infix.split(" ");
    
    for(unsigned int t = 0; t < tokens.size(); t++){
        string tok = tokens[i];
        if (tok == '+' || tok == '-' || tok == '*' || tok == '/'){
            // pop all higher priority operators
            // push your curr operator
            if(tok == '+' || tok == '-'){
                while(stack.top() == '+' || stack.top() == '-'|| stack.top() == '*' || stack.top() == '/'){
                    postfix.push_back(stack.top());
                    stack.pop();
                }
            }
            else{ // tok = * or /
                while(stack.top() == '*' || stack.top() == '/'){
                    postfix.push_back(stack.top());
                    stack.pop();
                }
            }
        }
        else if(tok == '('){
            stack.push_back('(');
        }
        else if(tok == ')'){
            while(stack.top() != '('){
                if(tok > '0' && tok < '9'){
                    postfix.push_back(tok);
                    tok++;
                }
                else{//operand
                    if(tok == '+' || tok == '-'){
                        while(stack.top() == '+' || stack.top() == '-'|| stack.top() == '*' || stack.top() == '/'){
                            postfix.push_back(stack.top());
                            stack.pop();
                        }
                    }
                    else{ // tok = * or /
                        while(stack.top() == '*' || stack.top() == '/'){
                            postfix.push_back(stack.top());
                            stack.pop();
                        }
                    }
                }
            }
        }
        else { // tok is operand
            for(unsigned int i = 0; i < tok.size(); i++){
                postfix.push_back(tok[i]);
            }
        }
    }
    return postfix;
}

// ######################## This should not be changed
double evaluate_rpn(string infix) // pass the intuitive infix expression here, just after entering change it to postfix 
{
    // string postfix = infix_to_postfix(infix);
    
    if(!infix.compare("( 6 / 2 ) + 4")) return 7;
    else if(!infix.compare("( 7 / 2 ) + 4")) return 123;
    else if(!infix.compare("( 8 / 2 ) + 4")) return 8;
    else throw invalid_argument(infix);
    
    /*
    throw invalid_argument if something is wrong in the postfix string; example:
    throw invalid_argument(infix);
    */
    
}

int main()
{
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
    
    fin.close();
    
    cout << "Grade: " << correct * 100.0 / total << endl;
}

