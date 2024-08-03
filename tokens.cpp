#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string>
using namespace std;
#include "global.h"
map <string, int> priority;

bool isDelimiter(char symbol) {
	string delimiters = " ()+/*-^!";
	for (int i = 0; i < delimiters.size(); i++) {
    if(symbol == delimiters[i]) {
    	return 1;
		}
	}
  return 0;
}

void createPriorityOfOperations() {
  priority["opposite"] = 1;
  priority["+"] = 1;
  priority["-"] = 1;
  priority["*"] = 2;
  priority["/"] = 2;
  priority["^"] = 3;
  return;
}

tokens createTokensNames(string &expr, tokens &tokenExpr) {
  string expression = expr + " ";
  for(int i = 0; i < expression.size(); i++) {
    string name;
    if (isDelimiter(expression[i])) {
      if (expression[i] == ' ') {
        continue;
      }
      name = expression[i];
    } else {
      while(1) {
      	if(!isDelimiter(expression[i])) {
      		name += expression[i];
       		i++;
       		continue;
				} else {
					i--;
				}
				break;
      }
  	}
    tokenExpr.push_back(token(name, notype));
	}
	return tokenExpr;
}

tokens createTokensTypes(tokens &tokenExpr) {
  for (int j = 0; j < tokenExpr.size(); j++) {
  	if(isdigit(tokenExpr[j].name[0])) {
	    tokenExpr[j].type = number;
    } else if(tokenExpr[j].name[0] == '(') {
      tokenExpr[j].type = openBracket;
    } else if(tokenExpr[j].name[0] == ')') {
      tokenExpr[j].type = closedBracket;
    } else if(tokenExpr[j].name == "x") {
    	tokenExpr[j].type = var;
		} else if(isalpha(tokenExpr[j].name[0])) {
      tokenExpr[j].type = function;
    } else if(tokenExpr[j].name[0] == '+' || tokenExpr[j].name[0] == '-' || tokenExpr[j].name[0] == '/' ||
	  	tokenExpr[j].name[0] == '*' || tokenExpr[j].name[0] == '^') {
	    tokenExpr[j].type = operation;
  	} else {
    	tokenExpr[j].type = errorValue;
		}
  }
  for (int j = 0; j < tokenExpr.size(); j++) {
    if (tokenExpr[j].name == "-" && (j == 0 || tokenExpr[j - 1].type == openBracket))
      tokenExpr[j].name = "unary";
  }
  return tokenExpr;;
}

tokens createPolishRecord(tokens &tokenExpr, tokens &postfixExpr) {
	stack <token> tokenStack;
  createPriorityOfOperations();
  for (int i = 0; i < tokenExpr.size(); i++) {
  	if(tokenExpr[i].type == number || tokenExpr[i].type == var) {
  		postfixExpr.push_back(tokenExpr[i]);
		} else if(tokenExpr[i].type == openBracket) {
			tokenStack.push(tokenExpr[i]);
		} else if(tokenExpr[i].type == closedBracket) {
			while (tokenStack.top().type != openBracket) {
	        postfixExpr.push_back(tokenStack.top());
	        tokenStack.pop();
	      }
	    tokenStack.pop();
		} else if(tokenExpr[i].type == operation) {
			if (tokenStack.size()) {
	      while (tokenStack.size() && 
				((tokenStack.top().type == operation && priority[tokenExpr[i].name] <= priority[tokenStack.top().name]) || tokenStack.top().type == function)) {
	        postfixExpr.push_back(tokenStack.top());
	        tokenStack.pop();
	      }
	    }
	    tokenStack.push(tokenExpr[i]);
		} else if(tokenExpr[i].type == function) {
			while (tokenStack.size() && tokenStack.top().type == function) {
	      postfixExpr.push_back(tokenStack.top());
	      tokenStack.pop();
	    }
	    tokenStack.push(tokenExpr[i]);
		} 
  }
  while(tokenStack.size() != 0) {
    postfixExpr.push_back(tokenStack.top());
    tokenStack.pop();
  }
  return postfixExpr;
}
