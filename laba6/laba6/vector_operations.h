#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H

#include <vector>
#include <string>

// ������ �������������� ����������� ������� �� �����
void readFromFile(std::vector<int>& vec, const std::string& filename);

// �������������� ������������������ ��������� �������
void reverseVector(std::vector<int>& vec);

// ���������� ������������ �������� � �������
int findMinElement(const std::vector<int>& vec);

// �������� �� ������� ���� ������ ���������
void removeEvenNumbers(std::vector<int>& vec);

// ���������� ������� � ��������� ��� ������������ ������������������
void sortVector(std::vector<int>& vec, bool ascending);

// ������� ������������� �������� � ������ ��� ��������� ����������
void insertElement(std::vector<int>& vec, int element);

// ����������� ������� ��������� �������� � �������
int findElementIndex(const std::vector<int>& vec, int element);

// �������� ������������� ��������� �� �������
void removeDuplicates(std::vector<int>& vec);

#endif /* VECTOR_OPERATIONS_H */
