#include <iostream>
#include "calculate.h"
#include "math.h"
#include "input.h"
using namespace std;

double methodOfLeftRectangles() {
  double x1, x2;
  double a, b, n;
  double integral;
  double test = 1;
  a = checkLowLimit();
	b = checkHighLimit();
	n = checkCountOfSteps();
	double h = (b - a) / n;
  for (int i = 0; i <= n - 1; i++) {
    x1 = a + i * h;
    x2 = a + (i + 1) * h;
    integral += calculateExpression(x1) * (x2 - x1);
  }
  if(fabs(integral) < 1e-300) {
  	wcout << "РЕЗУЛЬТАТ: 0" << "(методом лівих прямокутників)";
	} else if(isinf(integral)) {
  	wcout << "РЕЗУЛЬТАТ: Infinity" << "(методом лівих прямокутників)";
	} else if(isnan(integral)) {
  	wcout << "РЕЗУЛЬТАТ: NaN" << "(методом лівих прямокутників)";
	} else {
		wcout << "РЕЗУЛЬТАТ: " << integral << "(методом лівих прямокутників)";
	}
  return 0;
}

double methodOfRightRectangles() {
  double x1, x2;
  double a, b, n;
  double integral;
  a = checkLowLimit();
	b = checkHighLimit();
	n = checkCountOfSteps();
  double h = (b - a) / n;
  for (int i = 1; i <= n; i++) {
    x1 = a + i * h;
    x2 = a + (i + 1) * h;
    integral += calculateExpression(x1) * (x1 - x2);
  }
  integral *= -1;
  if(fabs(integral) < 1e-300) {
  	wcout << "РЕЗУЛЬТАТ: 0" << "(методом правих прямокутників)";
	} else if(isinf(integral)) {
  	wcout << "РЕЗУЛЬТАТ: Infinity" << "(методом правих прямокутників)";
	} else if(isnan(integral)) {
  	wcout << "РЕЗУЛЬТАТ: NaN" << "(методом правих прямокутників)";
	} else {
  	wcout << "РЕЗУЛЬТАТ: " << integral << "(методом правих прямокутників)";
	}
  return 0;
}

double methodOfAverageRectangles() {
	double f;
  double x1, x2;
  double a, b, n;
  double integral;
  a = checkLowLimit();
	b = checkHighLimit();
	n = checkCountOfSteps();
  double h = (b - a) / n;
  for (int i = 1; i <= n; i++) {
    x1 = a + i * h;
    x2 = a + (i - 1) * h;
    f = ((x1 + x2) / 2);
    integral += calculateExpression(f) * (x1 - x2);
  }
  if(fabs(integral) < 1e-300) {
  	wcout << "РЕЗУЛЬТАТ: 0" << "(методом середніх прямокутників)";
	} else if(isinf(integral)) {
  	wcout << "РЕЗУЛЬТАТ: Infinity" << "(методом середніх прямокутників)";
	} else if(isnan(integral)) {
  	wcout << "РЕЗУЛЬТАТ: NaN" << "(методом середніх прямокутників)" ;
	} else {
		wcout << "РЕЗУЛЬТАТ: " << integral << "(методом середніх прямокутників)";
	}
  return 0;
}

double methodOfTrapezes() {
  double x1, x2;
  double a, b, n;
  double integral;
  a = checkLowLimit();
	b = checkHighLimit();
	n = checkCountOfSteps();
  double h = (b - a) / n;
  for (int i = 0; i <= n - 1; i++) {
    x1 = a + i * h;
    x2 = a + (i + 1) * h;
    integral += ((calculateExpression(x1) + calculateExpression(x2)) / 2) * (x2 - x1);
  }
  if(fabs(integral) < 1e-300) {
  	wcout << "РЕЗУЛЬТАТ: 0" << "(методом трапецій)";
	} else if(isinf(integral)) {
  	wcout << "РЕЗУЛЬТАТ: Infinity" << "(методом трапецій)";
	} else if(isnan(integral)) {
  	wcout << "РЕЗУЛЬТАТ: NaN" << "(методом трапецій)";
	} else {
		wcout << "РЕЗУЛЬТАТ: " << integral << "(методом трапецій)";
	}
  return 0;
}

double methodOfParabolas() {
  double x1, x2, x3;
  double a, b, n;
  double integral;
  a = checkLowLimit();
	b = checkHighLimit();
	n = checkCountOfSteps();
  double N = 2 * n;
  double h = (b - a) / N;
  for (int i = 1; i <= N - 1; i += 2) {
    x1 = a + i * h;
    x2 = a + (i + 1) * h;
    x3 = a + (i - 1) * h;
    integral += (calculateExpression(x2) + 4 * calculateExpression(x1) + calculateExpression(x3));
  }
  integral *= h / 3;
  if(fabs(integral) < 1e-300) {
  	wcout << "РЕЗУЛЬТАТ: 0" << "(методом парабол)";
	} else if(isinf(integral)) {
  	wcout << "РЕЗУЛЬТАТ: Infinity" << "(методом парабол)";
	} else if(isnan(integral)) {
  	wcout << "РЕЗУЛЬТАТ: NaN" << "(методом парабол)";
	} else {
		wcout << "РЕЗУЛЬТАТ: " << integral << "(методом парабол)";
	}
  return 0;
}
