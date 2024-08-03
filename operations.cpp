#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;
#include "global.h"
operationsMap operations;

double plusFunction(stack <double> &temp) {
  double a, b;
  a = temp.top();
  temp.pop();
  b = temp.top();
  temp.pop();
  return a + b;
}
double minusFunction(stack <double> &temp) {
  double a, b;
  a = temp.top();
  temp.pop();
  b = temp.top();
  temp.pop();
  return b - a;
}
double multiplyFunction(stack <double> &temp){
  double a, b;
  a = temp.top();
  temp.pop();
  b = temp.top();
  temp.pop();
  return a * b;
}
double divisionFunction(stack <double> &temp) {
  double a, b;
  a = temp.top();
  temp.pop();
  b = temp.top();
  temp.pop();
  return b / a;
}
double degreeFunction(stack <double> &temp) {
  double a, b;
  a = temp.top();
  temp.pop();
  b = temp.top();
  temp.pop();
  return pow(b, a);
}
double unaryFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return -a;
}
double lnFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return log(a);
}
double lgFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return log10(a);
}
double sinFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return sin(a);
}
double cosFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return cos(a);
}
double tgFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return tan(a);
}
double ctgFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return 1 / tan(a);
}
double arcsinFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return asin(a);
}
double arccosFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return acos(a);
}
double arctgFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return atan(a);
}
double arcctgFunction(stack <double> &temp) {
  double pi = 3.14159265359;
  double a;
  a = temp.top();
  temp.pop();
  return pi / 2 - atan(a);
}
double shFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return sinh(a);
}
double chFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return cosh(a);
}
double thFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return tanh(a);
}
double cthFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return 1 / tanh(a);
}
double expFunction(stack <double> &temp) {
  double a;
  a = temp.top();
  temp.pop();
  return exp(a);
}

double createOperations() {
  operations["+"] = plusFunction;
  operations["-"] = minusFunction;
  operations["*"] = multiplyFunction;
  operations["/"] = divisionFunction;
  operations["^"] = degreeFunction;
  operations["unary"] = unaryFunction;
  operations["exp"] = expFunction;
  operations["ln"] = lnFunction;
  operations["lg"] = lgFunction;
  operations["sin"] = sinFunction;
  operations["cos"] = cosFunction;
  operations["tg"] = tgFunction;
  operations["ctg"] = ctgFunction;
  operations["arcsin"] = arcsinFunction;
  operations["arccos"] = arccosFunction;
  operations["arctg"] = arctgFunction;
  operations["arcctg"] = arcctgFunction;
  operations["sh"] = shFunction;
  operations["ch"] = chFunction;
  operations["th"] = thFunction;
  operations["cth"] = cthFunction;
}
