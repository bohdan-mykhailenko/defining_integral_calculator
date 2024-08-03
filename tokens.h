#ifndef TOKENS_H
#define TOKENS_H

tokens createTokensNames(string &expr, tokens &tokenExpr);
tokens createTokensTypes(tokens &tokenExpr);
tokens createPolishRecord(tokens &tokenExpr, tokens &postfixExpr);

#endif
