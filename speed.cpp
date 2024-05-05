#include <iostream> 
#include <vector>   
#include <list>     
#include <chrono>   // Для измерения времени выполнения
#include <iomanip>  // Для форматирования вывода
#include <memory>   // Для работы с памятью

int main() {
    std::setlocale(LC_ALL, "Russian"); 

    const int numElements = 100000; // Определяем количество элементов для вставки

    // Работа с вектором
    std::vector<int> vector;                                                    // Создаём вектор типа int
    auto start = std::chrono::high_resolution_clock::now();                     // Запоминаем начальное время
    for (int i = 0; i < numElements; ++i) {                                     // Цикл для вставки элементов
        vector.insert(vector.begin(), i);                                       // Вставляем в начало вектора, что обычно медленно
    }
    auto end = std::chrono::high_resolution_clock::now();                                               // Запоминаем конечное время
    std::chrono::duration<double> vectorTime = end - start;                                             // Вычисляем длительность операции
    std::cout << "Время вставки в начало вектора: " << vectorTime.count() << " секунд" << std::endl;    // Выводим время

    // Работа со списком
    std::list<int> list;                                                        // Создаём список типа int
    start = std::chrono::high_resolution_clock::now();                          // Запоминаем начальное время
    for (int i = 0; i < numElements; ++i) {                                     // Цикл для вставки элементов
        list.push_front(i);                                                     // Вставка в начало списка, что обычно быстрее
    }
    end = std::chrono::high_resolution_clock::now();                                                // Запоминаем конечное время
    std::chrono::duration<double> listTime = end - start;                                           // Вычисляем длительность операции
    std::cout << "Время вставки в начало списка: " << listTime.count() << " секунд" << std::endl;   // Выводим время

    // Оценка объёма используемой памяти
    size_t vectorMemoryUsage = vector.capacity() * sizeof(int);                                         // Вычисляем объём памяти, занимаемый вектором
    size_t listMemoryUsage = list.size() * sizeof(int) + list.size() * 2 * sizeof(void*);               // Учтём двойные ссылки в списке

    // Устанавливаем точность вывода и выводим используемый объём памяти
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Объём памяти, занимаемый вектором: " << vectorMemoryUsage / (1024.0 * 1024.0) << " МБ" << std::endl;
    std::cout << "Объём памяти, занимаемый списком: " << listMemoryUsage / (1024.0 * 1024.0) << " МБ" << std::endl;

    return 0;
}
