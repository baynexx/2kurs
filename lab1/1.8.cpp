#include <iostream>
using namespace std;

// Функция проверки массива на симметрию (палиндром)
// Принимает: массив и его размер
// Возвращает: true - если симметричный, false - если нет
bool isSymmetric(const int arr[], int size) {
    
    // Идем только до середины массива
    // Для размера 5: i < 2 (проверяем пары 0-4 и 1-3)
    // Для размера 6: i < 3 (проверяем пары 0-5, 1-4, 2-3)
    for (int i = 0; i < size / 2; i++) {
        
        // Сравниваем элемент с начала и элемент с конца
        // arr[i] - элемент слева
        // arr[size - 1 - i] - элемент справа
        if (arr[i] != arr[size - 1 - i]) {
            return false;  // Если не равны - сразу возвращаем false
        }
    }
    
    return true;  // Все пары совпали - массив симметричный
}

int main() {
    // Пример 1: Симметричный массив
    int arr1[] = {1, 2, 9, 2, 1};
    int size1 = 5;
    
    // Пример 2: Не симметричный массив
    int arr2[] = {1, 2, 3};
    int size2 = 3;
    
    // Проверяем первый массив
    cout << "Массив 1: ";
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    if (isSymmetric(arr1, size1)) {
        cout << "Симметричный (палиндром)" << endl;
    } else {
        cout << "Не симметричный" << endl;
    }
    
    cout << endl;
    
    // Проверяем второй массив
    cout << "Массив 2: ";
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    if (isSymmetric(arr2, size2)) {
        cout << "Симметричный (палиндром)" << endl;
    } else {
        cout << "Не симметричный" << endl;
    }
    
    return 0;
}