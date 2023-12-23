#include "Header.h"
#include <iostream>
#include "Windows.h"
#include <ctime>

using namespace std;

int choise;
const int SIZEARR = 6;

int randArr(int x) {
    return (rand() % (x * x)) + 1;
}


void printArr(int arr[][SIZEARR]) {
    system("cls");
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < SIZEARR; i++) {
        for (int j = 0; j < SIZEARR; j++) {
            destCoord.X = j * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(*(arr + i) + j);
        }
        cout << "\n";
    }
}

void fillSnake(int arr[][SIZEARR]) {
    system("cls");
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int top = 0, bottom = SIZEARR - 1, left = 0, right = SIZEARR - 1;
    while (left <= right && top <= bottom) {
        // ������ ����
        for (int i = top; i <= bottom; i++) {
            destCoord.X = left * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + i) + left) = randArr(SIZEARR);
            cout << *(*(arr + i) + left);
            cout.flush();
            Sleep(100);
        }
        left++;
        // ����� �����
        for (int i = bottom; i >= top; i--) {
            destCoord.X = left * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + i) + left) = randArr(SIZEARR);
            cout << *(*(arr + i) + left);
            cout.flush();
            Sleep(100);
        }
        left++;
    }
    destCoord.X = 0;
    destCoord.Y = SIZEARR * 2;
    SetConsoleCursorPosition(hStdout, destCoord);
}

void fillSpiral(int arr[][SIZEARR]) {
    system("cls");
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int num = 0;
    int top = 0, bottom = SIZEARR - 1, left = 0, right = SIZEARR - 1;
    while (left <= right && top <= bottom) {
        //������� ������
        for (int i = left; i <= right; i++) {
            destCoord.X = i * 4;
            destCoord.Y = top * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + top) + i) = randArr(SIZEARR);
            cout << *(*(arr + top) + i);
            cout.flush();
            Sleep(100);
        }
        top++;
        //������ �������
        for (int i = top; i <= bottom; i++) {
            destCoord.X = right * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + i) + right) = randArr(SIZEARR);
            cout << *(*(arr + i) + right);
            cout.flush();
            Sleep(100);
        }
        right--;
        //������ ������
        for (int i = right; i >= left; (i--)) {
            destCoord.X = i * 4;
            destCoord.Y = bottom * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + bottom) + i) = randArr(SIZEARR);
            cout << *(*(arr + bottom) + i);
            cout.flush();
            Sleep(100);
        }
        bottom--;
        //����� �������
        for (int i = bottom; i >= top; i--) {
            destCoord.X = left * 4;
            destCoord.Y = i * 2;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(*(arr + i) + left) = randArr(SIZEARR);
            cout << *(*(arr + i) + left);
            cout.flush();
            Sleep(100);
        }
        left++;
    }
    destCoord.X = 0;
    destCoord.Y = SIZEARR * 2;
    SetConsoleCursorPosition(hStdout, destCoord);
}

void moveBlocs(int arr[][SIZEARR]) {
    cout << "\n�������� ������ �����\n" <<
        "1) �� �����\n" <<
        "2) �� ���������\n" <<
        "3) ������ � �������\n" <<
        "4) ������ � ������\n-->> ";
    cin >> choise;
    // �� ����� �����
    if (choise == 1) {
        for (int i = 0; i < SIZEARR / 2; i++) {
            for (int j = 0; j < (SIZEARR / 2); j++) {
                swap(*(*(arr + i) + j), *(*(arr + i) + j + (SIZEARR / 2)));
            }
        }
        for (int i = 0; i < (SIZEARR / 2); i++) {
            for (int j = 0; j < SIZEARR; j++) {
                if (j < (SIZEARR / 2)) {
                    swap(*(*(arr + i) + j), *(*(arr + i + (SIZEARR / 2)) + j + (SIZEARR / 2)));
                }
            }
        }
        for (int i = 0; i < (SIZEARR / 2); i++) {
            for (int j = 0; j < SIZEARR / 2; j++) {
                swap(*(*(arr + i) + j), *(*(arr + i + (SIZEARR / 2)) + j));
            }
        }

    }
    // �� ��������� �����
    else if (choise == 2) {
        for (int i = 0; i < (SIZEARR / 2); i++) {
            for (int j = 0; j < SIZEARR; j++) {
                if (j < (SIZEARR / 2)) {
                    swap(*(*(arr + i) + j), *(*(arr + i + (SIZEARR / 2)) + j + (SIZEARR / 2)));
                }
                else {
                    swap(*(*(arr + i) + j), *(*(arr + i + (SIZEARR / 2)) + j - (SIZEARR / 2)));
                }
            }
        }
    }
    // ������� � ������ �����
    else if (choise == 3) {
        for (int i = 0; i < (SIZEARR / 2); i++) {
            for (int j = 0; j < SIZEARR; j++) {
                swap(*(*(arr + i) + j), *(*(arr + i + (SIZEARR / 2)) + j));
            }
        }
    }
    // ������ � ����� �����
    else if (choise == 4) {
        for (int i = 0; i < SIZEARR; i++) {
            for (int j = 0; j < (SIZEARR / 2); j++) {
                swap(*(*(arr + i) + j), *(*(arr + i) + j + (SIZEARR / 2)));
            }
        }
    }
    else {
        cout << "\n����������� ������ ������";
    }
}

void insert(int* ptr, int* end) {
    int j;
    for (int* i = ptr + 1; i <= end; i++) {
        if (*i < *(i - 1)) {
            for (j = *i; i > ptr && *(i - 1) > j; i--) {
                *i = *(i - 1);
            }
            *i = j;
        }

    }
}

void mathActions(int arr[][SIZEARR]) {
    char sign;
    int number;
    cout << "\n������� ��������('+', '-', '*', '/') � �����\n";
    cin >> sign >> number;

    if (sign == '+') {
        for (int i = 0; i < SIZEARR; i++) {
            for (int j = 0; j < SIZEARR; j++)
                *(*(arr + i) + j) += number;
        }
    }
    else if (sign == '-') {
        for (int i = 0; i < SIZEARR; i++) {
            for (int j = 0; j < SIZEARR; j++)
                *(*(arr + i) + j) -= number;
        }
    }
    else if (sign == '*') {
        for (int i = 0; i < SIZEARR; i++) {
            for (int j = 0; j < SIZEARR; j++)
                *(*(arr + i) + j) *= number;
        }
    }
    else if (sign == '/') {
        for (int i = 0; i < SIZEARR; i++) {
            for (int j = 0; j < SIZEARR; j++)
                *(*(arr + i) + j) /= number;
        }
    }
    else {
        cout << "������������ ����� ��� ����";
    }
}

void subMatrix(int arr[SIZEARR][SIZEARR]) {
    system("cls");
    printArr(arr);
    int subArr[SIZEARR][SIZEARR];
    cout << "\n������ �������:\n";
    for (int i = 0; i < SIZEARR; i++) {
        for (int j = 0; j < SIZEARR; j++) {
            *(*(subArr + i) + j) = randArr(SIZEARR);
            cout << *(*(subArr + i) + j) << "  ";
            Sleep(100);
        }
        cout << "\n\n";
    }
    cout << "\n������� ���������:\n";
    for (int i = 0; i < SIZEARR; i++) {
        for (int j = 0; j < SIZEARR; j++) {
            cout << *(*(arr + i) + j) << "-" << *(*(subArr + i) + j) << "  ";
            *(*(arr + i) + j) -= *(*(subArr + i) + j);
            Sleep(100);
        }
        cout << "\n\n";
    }
    cout << "\n���������� �������:\n";
    for (int i = 0; i < SIZEARR; i++) {
        for (int j = 0; j < SIZEARR; j++) {
            cout << *(*(arr + i) + j) << "  ";
            Sleep(100);
        }
        cout << "\n\n";
    }
}



int main3() {
    setlocale(0, "RU");
    int arr[SIZEARR][SIZEARR];
    int* ptr = *arr, * end = *arr + SIZEARR * SIZEARR - 1;

    while (true) {
        cout << "����� ����� �� ������ �������?\n" <<
            "1) ��������� ������\n" <<
            "2) �������� ����� �������\n" <<
            "3) �������������\n" <<
            "4) �������� � ��������\n" <<
            "5) ������� ������\n" <<
            "6) ��������� ������\n" <<
            "7) ����� � ������� ����\n-->> ";
        cin >> choise;
        switch (choise) {
        case 1:
            cout << "\n����� ������� ���������?\n" <<
                "1) �������\n" <<
                "2) ��������\n-->> ";
            cin >> choise;
            if (choise == 1) {
                fillSnake(arr);
            }
            else if (choise == 2) {
                fillSpiral(arr);
            }
            else
                cout << "\n����������� ������� �����\n";
            break;
        case 2:
            printArr(arr);
            moveBlocs(arr);
            cout << "\n";
            for (int i = 0; i < SIZEARR; i++) {
                for (int j = 0; j < SIZEARR; j++) {
                    cout << *(*(arr + i) + j) << "  ";
                    Sleep(100);
                }
                cout << "\n\n";
            }
            break;
        case 3:
            insert(ptr, end);
            printArr(arr);
            break;
        case 4:
            mathActions(arr);
            printArr(arr);
            break;
        case 5:
            printArr(arr);
            break;
        case 6:
            subMatrix(arr);
            break;
        case 7:
            return 0;
        default:
            cout << "������! ���������� �����\n";
            break;
        }
    }
    return 0;
}