#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>
using namespace std;
string expr;
double a;
double b;
double n;

void showExpression() {
	wcout << "ϳ����������� �������:" << endl;
	wcout << "b" << "\n" << L"\u222b";
	bool digit = true;
	for(int i = 0; i < expr.length(); i++ ) {
		if(!isdigit(expr[i])) {
			digit = false;
		}
	}
	if(expr.length() > 1 && !digit) {
		wcout << "(" << wstring(expr.begin(), expr.end()) << ")";
	} else {
		wcout  << wstring(expr.begin(), expr.end());
	}
	wcout << "dx" << "\n" << "a" << "\n" << endl;
}
void showLowLimit() {
	wcout << "����� ����:" << endl;
	wcout << "a = " << a << "\n" << endl;
}
void showHighLimit() {
	wcout << "������ ����:" << endl;
	wcout << "b = " << b << "\n" << endl;
}
void showCountOfSteps() {
	wcout << "ʳ������ ���������:" << endl;
	wcout << "n = " << n << "\n" <<  endl;
}

void inputExpression() {
	while(1) {
	  	wcout << "������ �������:" << "\n";
		  cin.clear();
		  cin.sync();
		  getline(cin, expr);
		  for(int i = 0; i < expr.length(); ) {
		  	if(expr[i] == ' ') {
		  		expr.erase(i, 1);
		  		continue;
				}
				i++;
			};
		  if(expr == "") {
		  	wcout << "����������� ��������!(������� �����)";
				wcout << "\n" << "\n" << "\n" << "\n";
				wcout << "�������� ����-��� ������, ��� ����������� �� �����...";
				system("pause>NUL");
				system("cls");
		  	continue;
			}
			break;
		}
	return;
}

double checkLowLimit() {
	system("cls");
	showExpression();
	bool digit;
  do {	
  	bool dot = false;
  	digit = true;
  	string str;
		wcout << "������ �(����� ���� ������������):" << "\n";
	  cin >> str;
	  for(int i = 0; i < str.length(); i++) {
	  	if(!isdigit(str[i])) {
	  		if((str[i] != '.' && str[i] != '-') || (i != 0 && str[i] == '-') || dot || (i == 0 && str[i] == '.')  || (i == str.length() - 1 && str[i] == '.')) {
		  		digit = false;
			  } else {
			  	dot = true;
				}
			}
		}
		if(digit) {
			a = atof(str.c_str());
		}	else {
			wcout << "����������� ��������!(������� ����� ������� �����)";
			wcout << "\n" << "\n" << "\n" << "\n";
			wcout << "�������� ����-��� ������, ��� ����������� �� �����...";
			system("pause>NUL");
			system("cls");
			showExpression();
			continue;
		}
	} while(!digit);
	return a;
}

double checkHighLimit() {
	system("cls");
	showExpression();
	showLowLimit();
	bool digit;
  do {
  	bool dot = false;
  	digit = true;
  	string str;
	  wcout << "������ b(������ ���� ������������):" << "\n";
	  cin >> str;
	  for(int i = 0; i < str.length(); i++) {
	  	if(!isdigit(str[i])) {
	  		if((str[i] != '.' && str[i] != '-') || (i != 0 && str[i] == '-') || dot || (i == 0 && str[i] == '.')  || (i == str.length() - 1 && str[i] == '.')) {
		  		digit = false;
			  } else {
			  	dot = true;
				}
			}
		}
		if(digit) {
			b = atof(str.c_str());
			if(b <= a) {
				digit = false;
				wcout << "����������� ��������!(b ������ ����� �� a)";
				wcout << "\n" << "\n" << "\n" << "\n";
				wcout << "�������� ����-��� ������, ��� ����������� �� �����...";
				system("pause>NUL");
				system("cls");
				showExpression();
				showLowLimit();
				continue;
			}
		}	else {
			wcout << "����������� ��������!(������� ����� ������� �����)";
			wcout << "\n" << "\n" << "\n" << "\n";
			wcout << "�������� ����-��� ������, ��� ����������� �� �����...";
			system("pause>NUL");
			system("cls");
			showExpression();
			showLowLimit();
			continue;
		}
	} while(!digit);
	return b;
}

double checkCountOfSteps() {
	system("cls");
	showExpression();
	showLowLimit();
	showHighLimit();
	bool digit;
  do {
  	digit = true;
  	string str;
	  wcout << "������ n(������� ��������� ���������):" << "\n";
	  cin >> str;
	  for(int i = 0; i < str.length(); i++) {
	  	if(!isdigit(str[i]) || str[0] == '0') {
		  		digit = false;
			}
		}
		if(digit) {
			n = atof(str.c_str());
		}	else {
			wcout << "����������� ��������!(������� ����� ������������ �����)";
			wcout << "\n" << "\n" << "\n" << "\n";
			wcout << "�������� ����-��� ������, ��� ����������� �� �����...";
			system("pause>NUL");
			system("cls");
			showExpression();
			showLowLimit();
			showHighLimit();
			continue;
		}
	} while(!digit);
	system("cls");
	showExpression();
	showLowLimit();
	showHighLimit();
	showCountOfSteps();
	return n;
}
