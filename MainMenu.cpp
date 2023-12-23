#include "Header.h"
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int numLab;
	while (true) {
		system("cls");
		cout << "Главное меню\n" <<
			"1) Работа с памятью\n" <<
			"2) Работа с массивами\n" <<
			"3) Работа с указателями\n" <<
			"4) Работа со строками\n" <<
			"5) Выход\n" <<
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
			cout << "Неправильно введен номер\n";
		}
	}
	return 0;
}