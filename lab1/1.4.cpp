#include <iostream>   // Для cout
using namespace std;

// Функция поиска первого вхождения числа в массиве
// Возвращает индекс или -1 если не найдено
int findIndex(const int arr[], int size, int target) {
    
    // Перебираем все элементы массива
    for (int i = 0; i < size; i++) {
        
        // Если нашли нужное число
        if (arr[i] == target) {
            return i;  // Возвращаем его индекс
        }
    }
    
    return -1;  // Если не нашли - возвращаем -1
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 20, 60};  // Массив
    int size = 7;                                // Размер
    int target = 20;                            // Что ищем
    
    int index = findIndex(arr, size, target);   // Поиск
    
    // Вывод результата
    if (index != -1) {
        cout << "Число " << target << " найдено на индексе: " << index;
    } else {
        cout << "Число " << target << " не найдено";
    }
    
    return 0;
}