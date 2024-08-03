#include <iostream>
#include <stdlib.h>
#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#include "global.h"
#include "operations.h"
#include "parser.h"

double calculateExpression(double &x) {
  tokens postfixExpr = parsedExpression;
  createOperations();
  stack <double> parsedStack;
  for (int i = 0; i < postfixExpr.size(); i++) {
  	if(postfixExpr[i].type == number) {
  		parsedStack.push(atof(postfixExpr[i].name.c_str()));
		} else if(postfixExpr[i].type == var) {
  		parsedStack.push(x);
		} else if(postfixExpr[i].type == function || postfixExpr[i].type == operation) {
  		operationsMap::iterator temp;
	      for (temp = operations.begin(); temp != operations.end(); temp++) {
	        if (temp->first == postfixExpr[i].name) {
	          parsedStack.push(temp->second(parsedStack));
	          break;
	        }
	      }
		}
  }
  return parsedStack.top();
}
