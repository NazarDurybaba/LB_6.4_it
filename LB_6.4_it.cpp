#include <iostream>
#include <Windows.h>
using namespace std;

// ������� ��� ���������� ������
int* createArray(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

// ������� ��� ��������� ������
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ������� ��� ���������� ������� �������� ������ � ������� ��������
int productOfEvenIndexElements(int* arr, int n) {
    int product = 1;
    for (int i = 1; i < n; i += 2) {
        if (arr[i] != 0) {
            product *= arr[i];
        }
    }
    return product;
}

// ������� ��� ���������� ���� �������� ������, ������������ �� ������ � ������� ��������� ����������
int sumBetweenFirstAndLastZero(int* arr, int n) {
    int firstZeroIndex = -1, lastZeroIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            if (firstZeroIndex == -1) firstZeroIndex = i;
            lastZeroIndex = i;
        }
    }
    int sum = 0;
    for (int i = firstZeroIndex + 1; i < lastZeroIndex; i++) {
        sum += arr[i];
    }
    return sum;
}

// ������� ��� ������������ ������
void transformArray(int* arr, int n) {
    int i = 0, j = n - 1;
    while (i <= j) {
        while (i <= j && arr[i] >= 0) i++;
        while (i <= j && arr[j] < 0) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
}

int main() {
    SetConsoleOutputCP(1251);
    int n;
    cout << "������ ����� ������: ";
    cin >> n;

    int* arr = createArray(n);

    printf("���������� �����: ");
    printArray(arr, n);

    int product = productOfEvenIndexElements(arr, n);
    printf("������� �������� ������ � ������� ��������: %d\n", product);

    int sum = sumBetweenFirstAndLastZero(arr, n);
    printf("���� �������� ������, ������������ �� ������ � ������� ��������� ����������: %d\n", sum);

    transformArray(arr, n);

    printf("������������� �����: ");
    printArray(arr, n);

    delete[] arr;

    return 0;
}
