#include <iostream>   // для cout
#include <string>     // для string
#include <cctype>     // для isupper()
using namespace std;

// Функция подсчета заглавных букв в строке
// Принимает: ссылку на строку (const - не изменяет)
// Возвращает: количество заглавных букв
int countUppercase(const string& text) {
    int count = 0;  // Счетчик заглавных букв
    
    // Проходим по всем символам строки по индексу
    // text.length() - возвращает длину строки
    for (int i = 0; i < text.length(); i++) {
        
        // isupper() проверяет, является ли символ заглавной буквой
        // Возвращает true (не 0) если это заглавная буква
        if (isupper(text[i])) {
            count++;  // Увеличиваем счетчик
        }
    }
    
    return count;  // Возвращаем результат
}

int main() {
    string text = "Hello World! How Are You?";  // Тестовая строка
    
    // Вызываем функцию и выводим результат
    cout << "Количество заглавных букв: " << countUppercase(text);
    
    return 0;
}