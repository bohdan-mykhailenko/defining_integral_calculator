#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#include "global.h"

bool checkFunction(tokens tokenExpr) {
	int countOpenBrackets = 0;
  int countClosedBrackets = 0;
	for(int i = 0; i < tokenExpr.size(); i++) {
		if(tokenExpr[i].type == errorValue) {
			return false;
		}
    if(tokenExpr[i].type == number) {
    	bool dot = true;
    	if(tokenExpr[i].name[0] == '0'  && tokenExpr[i].name[1] != '.' && tokenExpr[i].name.size() > 1) {
    		return false;
    	}
    	for (int k = 0; k < tokenExpr[i].name.length(); k++) {
    		if(!isdigit(tokenExpr[i].name[k]) ) {
    			if((tokenExpr[i].name[k] != '.') ||  tokenExpr[i].name[tokenExpr[i].name.length() - 1] == '.' || (!dot)) {
    				return false;
    			} else {
    				dot = false;
    				break;
					}
    		}
			}
		}
		if(tokenExpr[i].type == function) {
    	if(tokenExpr.size() == 1 || tokenExpr.size() <= (i + 1)) {
    		return false;
			} else if(tokenExpr[i + 1].name[0] != '(') {
        return false;
    	}
    	string  avaibleValues[] = {"unary ", "sin", "cos", "tg", "ctg", "arcsin", "arccos", "arctg", "arcctg", "sh", "ch", "th" ,"cth", "exp", "ln" ,"lg"};
			bool function = false;
			for (int k = 0; k < 17; k++) {
				if(tokenExpr[i].name == avaibleValues[k]) {
					function = true;
				}	
			}
			if(!function) {
				return false;
			}
    }
		if(tokenExpr[i].type == openBracket) {
			if(tokenExpr[i + 1].type == closedBracket) {
				return false;
			}
			countOpenBrackets++;
		}
		if(tokenExpr[i].type == closedBracket) {
			if(tokenExpr[i + 1].type == openBracket) {
				return false;
			}
			countClosedBrackets++;
		}
  	if((tokenExpr[i].type == var) && (i == 0 && tokenExpr.size() > 1)) {
  		if(tokenExpr[i + 1].type != operation) {
  			wcout << tokenExpr[i + 1].type;
  			wcout << tokenExpr[i - 1].type;
  			return false;
			}
		} else if((tokenExpr[i].type == var) && (i > 0)) {
			if(tokenExpr[i + 1].type != operation && tokenExpr[i - 1].type != operation && tokenExpr[i - 1].type != openBracket && tokenExpr[i + 1].type != closedBracket) {
				return false;
			}
		}
		if(tokenExpr[i].name == "unary" && (tokenExpr[i + 1].type == operation || tokenExpr[i + 1].type == closedBracket)) {
				return false;
		}
		if(tokenExpr[i].type == operation && i > 0 && tokenExpr[i].name != "unary") {
			if(tokenExpr[i + 1].type == operation  || tokenExpr[i - 1].type == openBracket || tokenExpr[i + 1].type == closedBracket) {
				return false;
			} 
		} else if(tokenExpr[i].type == operation && i == 0 && tokenExpr[i].name != "unary") {
				return false;
		}	
		if(tokenExpr[i].type == operation && i == tokenExpr.size() - 1 ) {
				return false;
			}
		if(countOpenBrackets < countClosedBrackets) {
			return false;
		}		
	}
	if(countOpenBrackets != countClosedBrackets) {
			return false;
	}
 return true;
}
