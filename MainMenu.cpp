#include "Header.h"
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int numLab;
	while (true) {
		system("cls");
		cout << "������� ����\n" <<
			"1) ������ � �������\n" <<
			"2) ������ � ���������\n" <<
			"3) ������ � �����������\n" <<
			"4) ������ �� ��������\n" <<
			"5) �����\n" <<
			"-->> ";
		cin >> numLab;
		switch (numLab) {
		case 1:
			system("cls");
			main1();
			break;
		case 2:
			system("cls");
			main2();
			break;
		case 3:
			system("cls");
			main3();
			break;
		case 4:
			system("cls");
			main4();
			break;
		case 5:
			exit(0);
			break;
		default:
			cout << "����������� ������ �����\n";
		}
	}
	return 0;
}