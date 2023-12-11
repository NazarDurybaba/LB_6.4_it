#include <iostream>
#include <Windows.h>
using namespace std;

// Функція для формування масиву
int* createArray(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

// Функція для виведення масиву
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Функція для обчислення добутку елементів масиву з парними номерами
int productOfEvenIndexElements(int* arr, int n) {
    int product = 1;
    for (int i = 1; i < n; i += 2) {
        if (arr[i] != 0) {
            product *= arr[i];
        }
    }
    return product;
}

// Функція для обчислення суми елементів масиву, розташованих між першим і останнім нульовими елементами
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

// Функція для перетворення масиву
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
    cout << "Введіть розмір масиву: ";
    cin >> n;

    int* arr = createArray(n);

    printf("Початковий масив: ");
    printArray(arr, n);

    int product = productOfEvenIndexElements(arr, n);
    printf("Добуток елементів масиву з парними номерами: %d\n", product);

    int sum = sumBetweenFirstAndLastZero(arr, n);
    printf("Сума елементів масиву, розташованих між першим і останнім нульовими елементами: %d\n", sum);

    transformArray(arr, n);

    printf("Модифікований масив: ");
    printArray(arr, n);

    delete[] arr;

    return 0;
}
