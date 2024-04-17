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

    // ������������ ������������������ ��������� �������
    std::reverse(vec.begin(), vec.end());
    std::cout << "1. �������������� ������������������ ��������� �������: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // ������� ����������� �������
    int minElement = *std::min_element(vec.begin(), vec.end());
    std::cout << "2. ����������� �������: " << minElement << std::endl;

    // ������� �� ������� ��� ������ ��������
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int num) { return num % 2 == 0; }), vec.end());
    std::cout << "3. �������� ���� ������ ���������: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // ������������ ������ � ��������� ������������������
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    std::cout << "4. ���������� ������� � ��������� ������������������: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // �������� � ������ ������������ �������, �� ������� ����������
    int elementToInsert = 42;
    vec.insert(std::lower_bound(vec.begin(), vec.end(), elementToInsert), elementToInsert);
    std::cout << "5. ������� �������� " << elementToInsert << ": ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // ���������� ������ ��������� ��������
    int elementToFindIndex = 42;
    auto it = std::find(vec.begin(), vec.end(), elementToFindIndex);
    if (it != vec.end()) {
        int index = std::distance(vec.begin(), it);
        std::cout << "6. ������ �������� " << elementToFindIndex << ": " << index << std::endl;
    }
    else {
        std::cout << "6. ������� " << elementToFindIndex << " �� ������" << std::endl;
    }

    // ������� �� ������� ������������� ��������
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    std::cout << "7. �������� ������������� ���������: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
