#include <iostream>
using namespace std;

int countEven(const int arr[], int size) {
    int count = 0;                      // Счетчик четных чисел
    
    for (int i = 0; i < size; i++) {    // Перебираем все элементы
        if (arr[i] % 2 == 0) {          // Если число делится на 2 без остатка
            count++;                    // То увеличиваем счетчик
        }
    }
    
    return count;                       // Возвращаем результат
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};    // Исходный массив
    int size = 6;                       // Размер массива
    
    cout << "Четных чисел: " << countEven(arr, size);  // Вывод результата
    return 0;
}
