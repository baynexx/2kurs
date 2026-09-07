#include <iostream>   // Для ввода/вывода (cout, endl)
#include <cstdlib>    // Для rand() и srand() - генерация случайных чисел
#include <ctime>      // Для time() - инициализация генератора случайных чисел
#include <iomanip>    // Для setprecision() и fixed - форматирование вывода
#include <vector>     // Для vector - динамические массивы
using namespace std;

// Создаем псевдоним для типа "матрица" (вектор векторов double)
using Matrix = vector<vector<double>>;

// 1. Функция посадки растений
// Заполняет поле случайными высотами от minHeight до maxHeight
void plantCrop(Matrix& field, int rows, int cols, double minHeight, double maxHeight) {
    // Перебираем все строки
    for (int i = 0; i < rows; i++) {
        // Перебираем все столбцы
        for (int j = 0; j < cols; j++) {
            // Генерируем случайное число от minHeight до maxHeight
            // static_cast<double>(rand()) / RAND_MAX - дает число от 0 до 1
            field[i][j] = minHeight + static_cast<double>(rand()) / RAND_MAX * (maxHeight - minHeight);
        }
    }
}

// 2. Функция полива строки
// Добавляет waterAmount ко всем элементам указанной строки
void irrigate(Matrix& field, int rowIndex, double waterAmount) {
    // Проверяем, что индекс строки не выходит за границы
    if (rowIndex < 0 || rowIndex >= static_cast<int>(field.size())) {
        return;  // Если индекс неверный - выходим из функции
    }

    // Проходим по всем столбцам в выбранной строке
    for (size_t j = 0; j < field[rowIndex].size(); j++) {
        field[rowIndex][j] += waterAmount;  // Увеличиваем высоту растений
    }
}

// 3. Функция сбора урожая
// Обнуляет все элементы в указанном столбце
void harvest(Matrix& field, int colIndex) {
    // Проходим по всем строкам
    for (size_t i = 0; i < field.size(); i++) {
        // Проверяем, что индекс столбца существует в текущей строке
        if (colIndex >= 0 && colIndex < static_cast<int>(field[i].size())) {
            field[i][colIndex] = 0.0;  // Обнуляем элемент
        }
    }
}

// 4. Функция поиска самого высокого растения
// Возвращает максимальную высоту и записывает её координаты в outRow и outCol
double findMaxPlant(const Matrix& field, int rows, int cols, int& outRow, int& outCol) {
    // Проверяем, что поле не пустое
    if (rows <= 0 || cols <= 0 || field.empty() || field[0].empty()) {
        outRow = -1;   // Устанавливаем -1 если поле пустое
        outCol = -1;
        return 0.0;    // Возвращаем 0
    }

    // Начинаем с первой клетки
    outRow = 0;
    outCol = 0;
    double maxHeight = field[0][0];  // Текущий максимум

    // Проходим по всему полю
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Если нашли растение выше текущего максимума
            if (field[i][j] > maxHeight) {
                maxHeight = field[i][j];  // Обновляем максимум
                outRow = i;               // Запоминаем строку
                outCol = j;               // Запоминаем столбец
            }
        }
    }

    return maxHeight;  // Возвращаем максимальную высоту
}

// 5. Функция проверки засухи вокруг клетки
// Проверяет 4 соседних клетки (вверх, вниз, влево, вправо)
// Возвращает true, если хотя бы у одного соседа высота меньше threshold
bool isDroughtSpot(const Matrix& field, int x, int y, double threshold) {
    // Проверяем, что клетка (x,y) существует
    if (x < 0 || x >= static_cast<int>(field.size()) || 
        y < 0 || y >= static_cast<int>(field[0].size())) {
        return false;  // Если клетка не существует - возвращаем false
    }

    // Массивы смещений для 4 направлений
    int dx[] = {-1, 1, 0, 0};  // Смещения по строкам (вверх, вниз, влево, вправо)
    int dy[] = {0, 0, -1, 1};  // Смещения по столбцам

    // Проверяем каждого соседа
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];  // Новая строка соседа
        int ny = y + dy[k];  // Новый столбец соседа

        // Проверяем, что сосед существует (не выходит за границы)
        if (nx < 0 || nx >= static_cast<int>(field.size()) || 
            ny < 0 || ny >= static_cast<int>(field[0].size())) {
            continue;  // Если сосед за границей - пропускаем его
        }

        // Если у соседа высота меньше порога - есть засуха
        if (field[nx][ny] < threshold) {
            return true;  // Возвращаем true (есть засуха)
        }
    }

    return false;  // Все соседи выше порога - засухи нет
}

// Главная функция - точка входа в программу
int main() {
    // Инициализируем генератор случайных чисел текущим временем
    // Это гарантирует, что каждый запуск будут разные случайные числа
    srand(static_cast<unsigned int>(time(0)));

    // Задаем размеры поля
    const int ROWS = 5;
    const int COLS = 5;
    
    // Создаем матрицу 5x5 (вектор из 5 векторов, каждый по 5 элементов)
    Matrix field(ROWS, vector<double>(COLS));

    // 1. Сажаем растения (заполняем поле случайными высотами)
    plantCrop(field, ROWS, COLS, 10.0, 50.0);

    // Выводим поле после посадки
    cout << "Поле после посадки:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // fixed - фиксированное количество знаков после запятой
            // setprecision(1) - один знак после запятой
            cout << fixed << setprecision(1) << field[i][j] << "\t";
        }
        cout << endl;  // Переход на новую строку
    }
    cout << endl;

    // 2. Поливаем строку 2 (индексация с 0)
    irrigate(field, 2, 5.0);
    cout << "После полива строки 2 (прибавили 5.0):" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << fixed << setprecision(1) << field[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // 3. Собираем урожай в столбце 3 (индексация с 0)
    harvest(field, 3);
    cout << "После сбора урожая в столбце 3 (обнулили):" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << fixed << setprecision(1) << field[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // 4. Находим самое высокое растение на поле
    int maxRow, maxCol;  // Переменные для координат
    double maxHeight = findMaxPlant(field, ROWS, COLS, maxRow, maxCol);
    cout << "Самое высокое растение: " << fixed << setprecision(1) << maxHeight
         << " см на позиции [" << maxRow << "][" << maxCol << "]" << endl;
    cout << endl;

    // 5. Проверяем засуху вокруг клетки (2,2)
    int x = 2, y = 2;          // Координаты проверяемой клетки
    double threshold = 15.0;   // Порог высоты (ниже - засуха)
    
    if (isDroughtSpot(field, x, y, threshold)) {
        cout << "Вокруг клетки [" << x << "][" << y << "] есть засуха!" << endl;
    } else {
        cout << "Вокруг клетки [" << x << "][" << y << "] все хорошо" << endl;
    }

    return 0;  // Программа завершена успешно
}