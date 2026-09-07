#include <iostream>
using namespace std;

// Функция переворачивает массив
void reverseArray(int arr[], int size) {
    // Идем только до середины массива
    for (int i = 0; i < size / 2; i++) {
        // Меняем местами элементы с начала и с конца
        int temp = arr[i];                    // Сохраняем левый элемент
        arr[i] = arr[size - 1 - i];           // Левый = правый
        arr[size - 1 - i] = temp;             // Правый = сохраненный левый
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};  // Создаем массив
    int size = 6;                     // Размер массива
    
    reverseArray(arr, size);          // Переворачиваем
    
    // Выводим результат
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}