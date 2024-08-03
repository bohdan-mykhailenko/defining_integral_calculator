#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#include "global.h"
#include "parser.h"
#include "info.h"
#include "methods.h"
#include "windows.h"
#include <fcntl.h>  
#include <io.h> 

int main() {
	SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  _setmode(_fileno(stdout), _O_U16TEXT);
  int comand;
  int method;
	do {
		do {
			string str;
			wcout << "����������� ��� ����������� ���������" << endl;
			wcout << "1. ��������� ��������" << endl;
			wcout << "2. ��� ��������" << endl;
			wcout << "3. ��� ������" << endl;
			wcout << "4. ��������" << endl;
			wcout << "5. �����" << endl;
			getline(cin, str);
			cout << str << endl;
			if(str == "1"  || str == "2" || str == "3" || str == "4" || str == "5") {
				cin.clear();
				cin.sync();
			} else {
				cin.clear();
				cin.sync();
				wcout << "���������� ��������, �������������� ���� �������: 1, 2, 3, 4, 5" << endl;
				wcout << "\n" << "\n" << "\n" << "\n";
				wcout << "�������� ����-��� ������, ��� ����������...";
				system("pause>NUL");
				system("cls");
				continue;
			}
			comand = atoi(str.c_str());
			system("cls");
			break;
		}	while(1);	
		switch(comand) {
			case 1: {
				bool menu = false;
				do {
					do {
						cin.clear();
						cin.sync();	
						string str;
						wcout << "������ ����� ������������: \n";
						wcout << "1. ����� ���� ������������ \n";
						wcout << "2. ����� ������ ������������ \n";
						wcout << "3. ����� ������� ������������ \n";
						wcout << "4. ����� �������� \n";
						wcout << "5. ����� ������� \n";
						wcout << "6. ������� ���� \n";
						getline(cin, str);
						if(str == "1"  || str == "2" || str == "3" || str == "4" || str == "5" || str == "6") {
							cin.clear();
						  cin.sync();	
						} else {
								cin.clear();
								cin.sync();
								wcout << "���������� ��������, �������������� ���� �������: 1, 2, 3, 4, 5, 6" << endl;
								wcout << "\n" << "\n" << "\n" << "\n";
								wcout << "�������� ����-��� ������, ��� ����������...";
								system("pause>NUL");
								system("cls");
								continue;
						}
						method = atoi(str.c_str());
						system("cls");
						break;
					} while(1);
					char info;
					switch(method) {
						case 1: {
							wcout << "�������� ��� ,���� ������ ������������� � ����������� ����������� �� ����-��� ���� ������, ���� �" << endl;
							cin >> info;
							if(info == 'i') {
								system("cls");
								showInfoAboutLeftRectangles();
								wcout << "\n" << "\n" << "\n" << "\n";
								wcout << "�������� ����-��� ������, ��� ����������...";
								system("pause>NUL");
								system("cls");
							} else {
								system("cls");
							}
							parseExpression();
							methodOfLeftRectangles();
							wcout << "\n" << "\n" << "\n" << "\n";
							wcout << "�������� ����-��� ������, ��� ����������...";
							system("pause>NUL");
							system("cls");
							break;
						}
						case 2: {
							wcout << "�������� ��� ,���� ������ ������������� � ����������� ����������� �� ����-��� ���� ������, ���� �" << endl;
							cin >> info;
							if(info == 'i') {
								system("cls");
								showInfoAboutRightRectangles();
								wcout << "\n" << "\n" << "\n" << "\n";
								wcout << "�������� ����-��� ������, ��� ����������...";
								system("pause>NUL");
								system("cls");
							} else {
								system("cls");
							}
							parseExpression();
							methodOfRightRectangles();
							wcout << "\n" << "\n" << "\n" << "\n";
							wcout << "�������� ����-��� ������, ��� ����������...";
							system("pause>NUL");
							system("cls");
							break;
						}
						case 3: {
							wcout << "�������� ��� ,���� ������ ������������� � ����������� ����������� �� ����-��� ���� ������, ���� �" << endl;
							cin >> info;
							if(info == 'i') {
								system("cls");
								showInfoAboutAverageRectangles();
								wcout << "\n" << "\n" << "\n" << "\n";
								wcout << "�������� ����-��� ������, ��� ����������...";
								system("pause>NUL");
								system("cls");
							} else {
								system("cls");
							}
							parseExpression();
							methodOfAverageRectangles();
							wcout << "\n" << "\n" << "\n" << "\n";
							wcout << "�������� ����-��� ������, ��� ����������...";
							system("pause>NUL");
							system("cls");
							break;
						}
						case 4: {
							wcout << "�������� ��� ,���� ������ ������������� � ����������� ����������� �� ����-��� ���� ������, ���� �" << endl;
							cin >> info;
							if(info == 'i') {
								system("cls");
								showInfoAboutTrapezes();
								wcout << "\n" << "\n" << "\n" << "\n";
								wcout << "�������� ����-��� ������, ��� ����������...";
								system("pause>NUL");
								system("cls");
							} else {
								system("cls");
							}
							parseExpression();
							methodOfTrapezes();
							wcout << "\n" << "\n" << "\n" << "\n";
							wcout << "�������� ����-��� ������, ��� ����������...";
							system("pause>NUL");
							system("cls");
							break;
						}
						case 5: {
							wcout << "�������� ��� ,���� ������ ������������� � ����������� ����������� �� ����-��� ���� ������, ���� �" << endl;
							cin >> info;
							if(info == 'i') {
								system("cls");
								showInfoAboutParabolas();
								wcout << "\n" << "\n" << "\n" << "\n";
								wcout << "�������� ����-��� ������, ��� ����������...";
								system("pause>NUL");
								system("cls");
							} else {
								system("cls");
							}
							parseExpression();
							methodOfParabolas();
							wcout << "\n" << "\n" << "\n" << "\n";
							wcout << "�������� ����-��� ������, ��� ����������...";
							system("pause>NUL");
							system("cls");
							break;
						}
						case 6: {
							menu = true;
							system("cls");
						}
					}
				} while(!menu);
				break;
			}
			case 2: {
				showInfoAboutProgramme();
				wcout << "\n" << "\n" << "\n" << "\n";
				wcout << "�������� ����-��� ������, ��� ����������...";
				system("pause>NUL");
				system("cls");
				break;
			}
			case 3: {
				showInfoAboutAuthor();
				wcout << "\n" << "\n" << "\n" << "\n";
				wcout << "�������� ����-��� ������, ��� ����������...";
				system("pause>NUL");
				system("cls");
				break;
			}
			case 4: {
				showHelpInfo();
				wcout << "\n" << "\n" << "\n" << "\n";
				wcout << "�������� ����-��� ������, ��� ����������...";
				system("pause>NUL");
				system("cls");
				break;
			}
			case 5: {
				return 0;
			}
		}
	} while(1);
}
