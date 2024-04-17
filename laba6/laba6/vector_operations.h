#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H

#include <vector>
#include <string>

// Чтение целочисленного одномерного вектора из файла
// Функция принимает ссылку на вектор и имя файла
void readFromFile(std::vector<int>& vec, const std::string& filename);

// Реверсирование последовательности элементов вектора
// Функция принимает ссылку на вектор
void reverseVector(std::vector<int>& vec);

// Нахождение минимального элемента в векторе
// Функция принимает константную ссылку на вектор и возвращает минимальный элемент
int findMinElement(const std::vector<int>& vec);

// Удаление из вектора всех четных элементов
// Функция принимает ссылку на вектор
void removeEvenNumbers(std::vector<int>& vec);

// Сортировка вектора в убывающей или возрастающей последовательности
// Функция принимает ссылку на вектор и булевое значение, указывающее на порядок сортировки
void sortVector(std::vector<int>& vec, bool ascending);

// Вставка произвольного элемента в вектор без нарушения сортировки
// Функция принимает ссылку на вектор и элемент для вставки
void insertElement(std::vector<int>& vec, int element);

// Определение индекса заданного элемента в векторе
// Функция принимает константную ссылку на вектор и элемент, индекс которого нужно найти
// Возвращает индекс элемента или -1, если элемент не найден
int findElementIndex(const std::vector<int>& vec, int element);

// Удаление дублированных элементов из вектора
// Функция принимает ссылку на вектор
void removeDuplicates(std::vector<int>& vec);

#endif /* VECTOR_OPERATIONS_H */


/*readFromFile(std::vector<int>& vec, const std::string& filename) - открывает файл, считывает целые числа из него и добавляет их в вектор.

reverseVector(std::vector<int>& vec) - реверсирует порядок элементов в векторе.

findMinElement(const std::vector<int>& vec) - находит минимальный элемент в векторе.

removeEvenNumbers(std::vector<int>& vec) - удаляет все четные элементы из вектора.

sortVector(std::vector<int>& vec, bool ascending) - сортирует вектор в убывающем или возрастающем порядке в зависимости от значения ascending.

insertElement(std::vector<int>& vec, int element) - вставляет элемент в вектор, сохраняя сортировку.

findElementIndex(const std::vector<int>& vec, int element) - находит индекс заданного элемента в векторе.

removeDuplicates(std::vector<int>& vec) - удаляет дублированные элементы из вектора.*/
