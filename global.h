#ifndef GLOBAL_H
#define GLOBAL_H

enum tokenType {
  number, openBracket, closedBracket, operation, var, function, errorValue, notype
};
struct token {
  string name;
  tokenType type;
  token(string s, tokenType t) {
    name = s;
    type = t;
  }
  token() {}
};
typedef vector <token> tokens;
typedef double (*functionType)(stack <double> &);
typedef map <string, functionType> operationsMap;
extern operationsMap operations;
extern tokens parsedExpression;

#endif
