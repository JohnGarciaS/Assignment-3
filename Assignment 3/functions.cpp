#include <iostream>
#include "functions.h"
#include <stack>
#include <string>

using namespace std;

//Establish the pairs for the parentheses check that will be used
bool ParethPair(char Op, char Cl)
{
	if (Op == '(' && Cl == ')')
		return true;
	else if (Op == '[' && Cl == ']')
		return true;
	else if (Op == '{' && Cl == '}')
		return true;
	return false;
}


/*Cycles through the infix by character and if there is a match 
for parentheses it will be pushed to stack*/
bool IsInfixBalanced(string infix)
{
	stack<char> Stck;
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '(' || infix[i] == '[' || infix[i] == '{')
		{
			Stck.push(infix[i]);
		}
        /*If the match is for end paraenthese and it matches the criteria
        it will be pop in stack*/
		else if (infix[i] == ')' || infix[i] == ']' || infix[i] == '}')
		{
			if (Stck.empty() || !ParethPair(Stck.top(), infix[i]))
			{
				return false;
			}

			else
			{
				Stck.pop();
			}
		}
	}

    //Return based on the empty
	return Stck.empty() ? true : false;
}


/*Heiarchy of the order for symbols that will be used like PEMDAS*/
int Order(char sym)
{
	if (sym == '%' || sym == '*' || sym == '/')
	{
		return 2;
	}
	else if (sym == '+' || sym == '-')
	{
		return 1;
	}

	else
	{
		return -1;
	}
}


//Operators that we are looking for
bool isOperator(char symbol)
{
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%';
}



/*If the infix passed the parentheses check this will convert to postfix,
loops for the characters in the infix and if its anything other than symbol or 
parentheses it will  update the final answer with the character other wise
it will be put into the stack to eventally be put in the correct order*/
string infixToPostfix(string infix) {
    stack<char> Stack;
    string Answer = "";

    for (char ch : infix) {
        if (!isOperator(ch) && ch != '(' && ch != ')' && ch != '[' && ch != ']' && ch != '{' && ch != '}') {
            Answer += ch;
        }
        else if (ch == '(' || ch == '[' || ch == '{') {
            Stack.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            char opposite;
            if (ch == ')') {
                opposite = '(';
            }
            else if (ch == ']') {
                opposite = '[';
            }
            else if (ch == '}') {
                opposite = '{';
            }

            while (!Stack.empty() && Stack.top() != opposite) {
                Answer += Stack.top();
                Stack.pop();
            }
            if (!Stack.empty()) {
                Stack.pop();
            }
        }
        else if (isOperator(ch)) {
            while (!Stack.empty() && Order(Stack.top()) >= Order(ch)) {
                Answer += Stack.top();
                Stack.pop();
            }
            Stack.push(ch);
        }
    }
    while (!Stack.empty()) {
        Answer += Stack.top();
        Stack.pop();
    }

    return Answer;
}