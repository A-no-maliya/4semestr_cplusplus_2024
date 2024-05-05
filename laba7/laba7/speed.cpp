#include <iostream> 
#include <vector>   
#include <list>     
#include <chrono>   // ��� ��������� ������� ����������
#include <iomanip>  // ��� �������������� ������
#include <memory>   // ��� ������ � �������

int main() {
    std::setlocale(LC_ALL, "Russian"); 

    const int numElements = 100000; // ���������� ���������� ��������� ��� �������

    // ������ � ��������
    std::vector<int> vector;                                                    // ������ ������ ���� int
    auto start = std::chrono::high_resolution_clock::now();                     // ���������� ��������� �����
    for (int i = 0; i < numElements; ++i) {                                     // ���� ��� ������� ���������
        vector.insert(vector.begin(), i);                                       // ��������� � ������ �������, ��� ������ ��������
    }
    auto end = std::chrono::high_resolution_clock::now();                                               // ���������� �������� �����
    std::chrono::duration<double> vectorTime = end - start;                                             // ��������� ������������ ��������
    std::cout << "����� ������� � ������ �������: " << vectorTime.count() << " ������" << std::endl;    // ������� �����

    // ������ �� �������
    std::list<int> list;                                                        // ������ ������ ���� int
    start = std::chrono::high_resolution_clock::now();                          // ���������� ��������� �����
    for (int i = 0; i < numElements; ++i) {                                     // ���� ��� ������� ���������
        list.push_front(i);                                                     // ������� � ������ ������, ��� ������ �������
    }
    end = std::chrono::high_resolution_clock::now();                                                // ���������� �������� �����
    std::chrono::duration<double> listTime = end - start;                                           // ��������� ������������ ��������
    std::cout << "����� ������� � ������ ������: " << listTime.count() << " ������" << std::endl;   // ������� �����

    // ������ ������ ������������ ������
    size_t vectorMemoryUsage = vector.capacity() * sizeof(int);                                         // ��������� ����� ������, ���������� ��������
    size_t listMemoryUsage = list.size() * sizeof(int) + list.size() * 2 * sizeof(void*);               // ���� ������� ������ � ������

    // ������������� �������� ������ � ������� ������������ ����� ������
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "����� ������, ���������� ��������: " << vectorMemoryUsage / (1024.0 * 1024.0) << " ��" << std::endl;
    std::cout << "����� ������, ���������� �������: " << listMemoryUsage / (1024.0 * 1024.0) << " ��" << std::endl;

    return 0;
}
