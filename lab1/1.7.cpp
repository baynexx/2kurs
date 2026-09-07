#include <iostream>
using namespace std;

// Функция поиска седловой точки в матрице
// matrix - матрица (4 столбца)
// rows, cols - размеры матрицы
// outValue, rowIndex, colIndex - выходные параметры (передаются по ссылке)
// Возвращает: true если найдена, false если нет
bool findSaddlePoint(const int matrix[][4], int rows, int cols, int& outValue, int& rowIndex, int& colIndex) {
    
    // Перебираем все строки матрицы
    for (int i = 0; i < rows; i++) {
        
        // Находим минимальный элемент в текущей строке i
        int minInRow = matrix[i][0];  // Начинаем с первого элемента
        int colOfMin = 0;              // Запоминаем столбец минимума
        
        // Проходим по всем элементам строки i
        for (int j = 1; j < cols; j++) {
            // Если нашли элемент меньше текущего минимума
            if (matrix[i][j] < minInRow) {
                minInRow = matrix[i][j];  // Обновляем минимум
                colOfMin = j;             // Запоминаем его столбец
            }
        }
        
        // Теперь проверяем: является ли этот минимум максимальным в своем столбце?
        bool isMaxInCol = true;  // Предполагаем, что да
        
        // Проходим по всем строкам в столбце colOfMin
        for (int k = 0; k < rows; k++) {
            // Если нашли элемент больше нашего минимума
            if (matrix[k][colOfMin] > minInRow) {
                isMaxInCol = false;  // Значит это НЕ максимальный в столбце
                break;               // Можно выходить из цикла
            }
        }
        
        // Если минимум в строке является максимумом в столбце
        if (isMaxInCol) {
            // Сохраняем результат в выходные параметры
            outValue = minInRow;
            rowIndex = i;
            colIndex = colOfMin;
            return true;  // Седловая точка найдена
        }
    }
    
    return false;  // Седловая точка не найдена
}

int main() {
    const int ROWS = 3;
    const int COLS = 4;
    
    // Создаем матрицу 3x4
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int value, row, col;  // Переменные для результата
    
    // Ищем седловую точку
    if (findSaddlePoint(matrix, ROWS, COLS, value, row, col)) {
        cout << "Седловая точка найдена!" << endl;
        cout << "Значение: " << value << endl;
        cout << "Строка: " << row << ", Столбец: " << col << endl;
    } else {
        cout << "Седловая точка не найдена" << endl;
    }
    
    return 0;
}