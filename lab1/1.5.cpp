#include <iostream>   // Для cout
#include <string>     // Для string
#include <cctype>     // Для isalpha()
using namespace std;

// Функция подсчета статистики по строке
// line - входная строка
// letters, vowels, consonants - выходные параметры (передаются по ссылке)
void getStats(const string& line, int& letters, int& vowels, int& consonants) {
    
    // Обнуляем счетчики
    letters = 0;
    vowels = 0;
    consonants = 0;
    
    // Строка со всеми гласными (заглавные и строчные)
    string vowelList = "aeiouAEIOU";
    
    // Перебираем все символы строки
    for (char c : line) {
        
        // Проверяем: является ли символ буквой?
        if (isalpha(c)) {
            letters++;  // Увеличиваем счетчик букв
            
            // Проверяем: есть ли символ в строке гласных?
            // string::npos означает "не найдено"
            if (vowelList.find(c) != string::npos) {
                vowels++;  // Это гласная
            } else {
                consonants++;  // Это согласная
            }
        }
        // Если не буква (пробел, цифра, знак) - пропускаем
    }
}

int main() {
    string text = "Hello World";  // Тестовая строка
    int letters, vowels, consonants;  // Переменные для результатов
    
    // Вызываем функцию (передаем переменные по ссылке)
    getStats(text, letters, vowels, consonants);
    
    // Выводим результаты
    cout << "Букв: " << letters << endl;
    cout << "Гласных: " << vowels << endl;
    cout << "Согласных: " << consonants << endl;
    
    return 0;
}