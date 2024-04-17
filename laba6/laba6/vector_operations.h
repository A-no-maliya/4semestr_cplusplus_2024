#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H

#include <vector>
#include <string>

// Чтение целочисленного одномерного вектора из файла
void readFromFile(std::vector<int>& vec, const std::string& filename);

// Реверсирование последовательности элементов вектора
void reverseVector(std::vector<int>& vec);

// Нахождение минимального элемента в векторе
int findMinElement(const std::vector<int>& vec);

// Удаление из вектора всех четных элементов
void removeEvenNumbers(std::vector<int>& vec);

// Сортировка вектора в убывающей или возрастающей последовательности
void sortVector(std::vector<int>& vec, bool ascending);

// Вставка произвольного элемента в вектор без нарушения сортировки
void insertElement(std::vector<int>& vec, int element);

// Определение индекса заданного элемента в векторе
int findElementIndex(const std::vector<int>& vec, int element);

// Удаление дублированных элементов из вектора
void removeDuplicates(std::vector<int>& vec);

#endif /* VECTOR_OPERATIONS_H */
