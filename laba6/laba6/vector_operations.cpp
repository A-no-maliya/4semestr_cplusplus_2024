#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void readFromFile(std::vector<int>& vec, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    int num;
    while (file >> num) {
        vec.push_back(num);
    }

    file.close();
}

int main() {
    setlocale(LC_ALL, "Rus");


    std::vector<int> vec;
    readFromFile(vec, "input_data.txt");

    // Реверсируйте последовательность элементов вектора
    std::reverse(vec.begin(), vec.end());
    std::cout << "1. Реверсирование последовательности элементов вектора: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Найдите минимальный элемент
    int minElement = *std::min_element(vec.begin(), vec.end());
    std::cout << "2. Минимальный элемент: " << minElement << std::endl;

    // Удалите из вектора все четные элементы
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int num) { return num % 2 == 0; }), vec.end());
    std::cout << "3. Удаление всех четных элементов: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Отсортируйте вектор в убывающей последовательности
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    std::cout << "4. Сортировка вектора в убывающей последовательности: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Вставьте в вектор произвольный элемент, не нарушая сортировку
    int elementToInsert = 42;
    vec.insert(std::lower_bound(vec.begin(), vec.end(), elementToInsert), elementToInsert);
    std::cout << "5. Вставка элемента " << elementToInsert << ": ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Определите индекс заданного элемента
    int elementToFindIndex = 42;
    auto it = std::find(vec.begin(), vec.end(), elementToFindIndex);
    if (it != vec.end()) {
        int index = std::distance(vec.begin(), it);
        std::cout << "6. Индекс элемента " << elementToFindIndex << ": " << index << std::endl;
    }
    else {
        std::cout << "6. Элемент " << elementToFindIndex << " не найден" << std::endl;
    }

    // Удалите из вектора дублированные элементы
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    std::cout << "7. Удаление дублированных элементов: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
