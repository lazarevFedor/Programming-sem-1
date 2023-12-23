#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;
//����������
void insert(int size, int arr[]) {
    int buff, j;
    for (int i = 1; i < size; i++) {
        buff = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > buff) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = buff;
    }
}

void shell(int size, int arr[]) {
    int i, j, step;
    int tmp;
    for (step = size / 2; step > 0; step = step / 2)
        for (i = step; i < size; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step; j = j - step)
            {
                if (tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
        }


}
//�������� �����
int bSearch(int size, int arr[], int value) {
    int left = 0;
    int right = size - 1;
    int middle;
    while (left <= right) {
        middle = (left + right) / 2;
        if (value == arr[middle]) {
            return middle;
        }
        else if (value > arr[middle]) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return -1;
}
//���������� ����� ������ value
void lessValue(int size, int arr[], int& value, int& count) {
    count = 0;
    insert(size, arr);
    int index = bSearch(size, arr, value);
    index++;
    for (int i = 0; i < index; i++) {
        if (arr[i] < value) {
            count += 1;
        }
    }
}
//���������� ����� ������ value
void moreValue(int size, int arr[], int& value, int& count) {
    count = 0;
    insert(size, arr);
    int index = bSearch(size, arr, value);
    index++;
    for (int i = index; i < size; i++) {
        if (arr[i] > value) {
            count += 1;
        }
    }
}
// ����� ���������
void normalSearch(int size, int arr[], int& value) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] == value) {
            cout << "������ �����: " << i << "\n";
            break;
        }
    }

}
//����� ��������� �� �������
void exchangeElements(int size, int arr[], int& indexA, int& indexB) {
    swap(arr[indexA], arr[indexB]);
}

void printArr(int size, int arr[]) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main2() {
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    setlocale(LC_ALL, "RU");
    srand(time(0));
    int choise, value, min, max, index, indexA, indexB, count = 0;
    const int SIZE = 100;
    int arr[SIZE];

    cout << "�������� �������: ";
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 198 - 99;
        cout << arr[i] << " ";
    }

    while (true) {
        cout << "\n\n�������� ����� : \n" <<
            "1) ���������� �������\n" <<
            "2) ���������� ������������ ��� ������������� ��������\n" <<
            "3) ������� �������� ������������ � ������������� ��������\n" <<
            "4) ���������� ���������, ������� ����� 'A'\n" <<
            "5) ���������� ��������� ������ ����� 'B'\n" <<
            "6) ����� ���������\n" <<
            "7) ����� ����� � �������\n" <<
            "8) �������� ������\n" <<
            "9) ����� � ������� ����\n" <<
            "--->>> ";
        cin >> choise;

        if (choise == 1) {
            cout << "\n\n�������� ������ ����������:\n" <<
                "1) insert sort\n" <<
                "2) shell sort" << "\n������� ������: ";
            cin >> choise;
            switch (choise) {
            case 1:
                start = steady_clock::now();
                insert(SIZE, arr);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "\n���������� ������ " << result.count() << " �������\n\n��������������� ������:";
                printArr(SIZE, arr);
                break;

            case 2:
                start = steady_clock::now();
                shell(SIZE, arr);
                end = steady_clock::now();
                result = duration_cast<nanoseconds>(end - start);
                cout << "���������� ������ " << result.count() << " �������\n";
                cout << "\n��������������� ������: ";
                printArr(SIZE, arr);
                break;
            default:
                cout << "\n�������� ������";
            }
        }
        else if (choise == 2) {
            // � �����������������
            min = arr[0];
            max = arr[0];
            start = steady_clock::now();
            for (int i = 1; i < SIZE; i++) {
                if (arr[i] < min)
                    min = arr[i];
                if (arr[i] > max)
                    max = arr[i];
            }

            end = steady_clock::now();
            cout << "\n����������� ��������: " << min << "\n������������ ��������: " << max << "\n";
            result = duration_cast<nanoseconds>(end - start);
            cout << "����� ���������� � ����������������� ������� :  " << result.count() << " �������\n";
            // � ���������������
            insert(SIZE, arr);
            start = steady_clock::now();
            min = arr[0];
            max = arr[SIZE - 1];
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "\n����������� ��������: " << min << "\n������������ ��������: " << max << "\n";
            cout << "����� ���������� � ��������������� ������� :  " << result.count() << " �������\n";


        }
        else if (choise == 3) {
            insert(SIZE, arr);
            min = arr[0];
            max = arr[SIZE - 1];
            int avMinMax = round(((min + max) / 2.0));
            cout << endl << "������� ��������: " << avMinMax << endl;

            start = steady_clock::now();
            index = bSearch(SIZE, arr, avMinMax);
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);

            if (index == -1) {
                cout << "����� " << avMinMax << " ��� � �������\n����� ������ " << result.count() << " �������\n";
            }
            else {
                cout << "������ ����� " << avMinMax << " = " << index << "\n����� ������ " << result.count() << " �������\n";
            }
        }
        else if (choise == 4) {
            cout << "������� �����: ";
            cin >> value;
            lessValue(SIZE, arr, value, count);
            cout << "\n\n���������� ��������� ������ 'A' = " << count << "\n";
        }
        else if (choise == 5) {
            cout << "������� �����: ";
            cin >> value;
            moreValue(SIZE, arr, value, count);
            cout << "\n\n���������� ��������� ������ 'B' = " << count << "\n";
        }
        else if (choise == 6) {
            cout << "������� ������ ������: ";
            cin >> indexA;
            cout << "\n������� ������ ������: ";
            cin >> indexB;

            start = steady_clock::now();
            exchangeElements(SIZE, arr, indexA, indexB);
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "\n����� ����� " << result.count() << " �������";
            cout << "\n������ ����� ������ : ";
            printArr(SIZE, arr);

        }
        else if (choise == 7) {
            insert(SIZE, arr);
            cout << "\n������� �����: ";
            cin >> value;

            start = steady_clock::now();
            index = bSearch(SIZE, arr, value);
            if (index == -1) {
                cout << "����� " << value << " ��� � �������" << "\n";
            }
            else {
                cout << "������ ����� " << value << " - " << index << "\n";
            }
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "�������� ����� ����� " << result.count() << " �������\n";

            start = steady_clock::now();
            normalSearch(SIZE, arr, value);
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "������� ����� " << result.count() << " �������\n";
        }
        else if (choise == 8) {
            system("cls");
            cout << "\n�������� �������: ";
            for (int i = 0; i < SIZE; i++) {
                arr[i] = rand() % 198 - 99;
                cout << arr[i] << " ";
            }
        }
        else if (choise == 9) {
            return 0;
        }
        else {
            cout << "\n������!���������� �����\n";
        }
    }
    return 0;
}