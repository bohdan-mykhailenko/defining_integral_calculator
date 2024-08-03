#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;
#include "global.h"
#include "tokens.h"
#include "check.h"
#include "input.h"
tokens parsedExpression;
extern string expr;

tokens parseExpression() {
	while(1) {
		tokens postfixExpr, tokenExpr;
		bool check;
		inputExpression();
	  createTokensNames(expr, tokenExpr);
	  createTokensTypes(tokenExpr);
	  check = checkFunction(tokenExpr);
	  if(!check) {
	  	wcout << "Недопустиме значення!(невірний запис функції)";
			wcout << "\n" << "\n" << "\n" << "\n";
			wcout << "Натисніть будь-яку клавішу, щоб повернутися до вводу...";
			system("pause>NUL");
			system("cls");
	  	continue;
		} 
  	parsedExpression = createPolishRecord(tokenExpr, postfixExpr);
  	break;
  }
  return parsedExpression;
}
