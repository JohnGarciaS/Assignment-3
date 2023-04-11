#pragma once
#include <iostream>
#include <stack>
#include <string>
#include "functions.h"

// Function declarations
using namespace std;

bool ParethPair(char Op, char Cl);


bool IsInfixBalanced(string infix);


int Order(char sym);

bool isOperator(char ch);


string infixToPostfix(string infix);

