#include <iostream>

using namespace std;

int main1() {
    setlocale(LC_ALL, "RU");
    int numOption, number, num, mask, order;
    while (true) {
        cout << "����� �������:\n" << 
            "1) ���������� ������\n" <<
            "2) �������� ������������� ������ �����\n" <<
            "3) �������� ������������� ���.�����\n" <<
            "4) ����� � ������� ����\n-->> ";
        cin >> numOption;
        switch (numOption) {
        case 1:
            cout <<
                "\n\n���������� ���������� ������ ���������� ������ ������:\n" <<
                "int: " << sizeof(int) << "\n" <<
                "short int: " << sizeof(short int) << "\n" <<
                "long int: " << sizeof(long int) << "\n" <<
                "float: " << sizeof(float) << "\n" <<
                "double: " << sizeof(double) << "\n" <<
                "long double: " << sizeof(long double) << "\n" <<
                "char: " << sizeof(char) << "\n" <<
                "bool: " << sizeof(bool) << "\n\n";
            break;

        case 2:
            cout << "\n\n������� ����� �����: ";
            cin >> number;
            num = number;
            order = sizeof(number) * 8 - 1;
            mask = 1 << order;
            cout << "\n�������� ������������� �����: ";

            for (int i = 0; i <= order; i++) {
                cout << ((number & mask) ? 1 : 0);
                number = number << 1;

                if (!i)
                    cout << " ";
            }
            cout << "\n\n";
            break;

        case 3:
            order = sizeof(int) * 8 - 1;
            mask = 1 << order;
            union
            {
                int intI;
                float floatF;
            };
            cout << "\n\n������� ������������ �����: ";
            cin >> floatF;
            num = intI;
            cout << "\n�������� �������������: ";
            for (int i = 0; i <= order; i++) {
                cout << ((intI & mask) ? 1 : 0);
                intI = intI << 1;

                if (!i || i == 8)
                    cout << " ";

            }
            cout << "\n\n";
            break;
        case 4:
            return 0;
        default:
            cout << "\n������! ���������� �����\n";
        }
    }
    return 0;
}