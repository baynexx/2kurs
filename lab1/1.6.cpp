#include <iostream>   // Для cout
#include <iomanip>    // Для setprecision() и fixed
using namespace std;

// Функция анализа оценок
void analyzeGrades(const int grades[], int size) {
    
    // Проверка на пустой массив
    if (size == 0) {
        cout << "Массив пуст" << endl;
        return;
    }
    
    // Массив-счетчик для оценок от 2 до 5
    // Индексы: 0,1,2,3,4,5 (0 и 1 не используются)
    int counter[6] = {0};  // Все элементы равны 0
    
    int sum = 0;  // Для подсчета суммы всех оценок
    
    // Проходим по всем оценкам
    for (int i = 0; i < size; i++) {
        sum += grades[i];  // Суммируем для среднего балла
        
        // Проверяем, что оценка от 2 до 5
        if (grades[i] >= 2 && grades[i] <= 5) {
            counter[grades[i]]++;  // Увеличиваем счетчик для этой оценки
        }
    }
    
    // 1. Средний балл
    // (double) - преобразуем в число с плавающей точкой для точности
    double average = (double)sum / size;
    
    // 2. Количество несдавших (оценка 2)
    int failed = counter[2];
    
    // 3. Самый частый балл (мода)
    int maxCount = 0;     // Максимальное количество повторений
    int mostFrequent = 2; // Самая частая оценка (начинаем с 2)
    
    // Перебираем оценки от 2 до 5
    for (int i = 2; i <= 5; i++) {
        if (counter[i] > maxCount) {
            maxCount = counter[i];   // Запоминаем новое максимальное значение
            mostFrequent = i;        // Запоминаем оценку
        }
    }
    
    // Выводим результаты
    // fixed - фиксированное количество знаков после запятой
    // setprecision(2) - два знака после запятой
    cout << "Средний балл: " << fixed << setprecision(2) << average << endl;
    cout << "Количество несдавших (оценка 2): " << failed << endl;
    cout << "Самый частый балл: " << mostFrequent 
         << " (встречается " << maxCount << " раз)" << endl;
}

int main() {
    // Массив оценок студентов
    int grades[] = {4, 5, 3, 4, 2, 5, 4, 3, 4, 5, 2, 4};
    int size = 12;  // Количество оценок
    
    analyzeGrades(grades, size);
    
    return 0;
}