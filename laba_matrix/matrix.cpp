#include <iostream>
#include "matrix.h"


int main()
{
	Matrix matrix1(3, 3); // ������� ������� 3�3
	Matrix matrix2(3, 3);

	matrix1.fillRandom(); // ��������� ���������� �������
	matrix2.fillRandom();

	std::cout << " ---- Showcases ----" << std::endl;
	std::cout << "1) First random matrix: " << "\n" << matrix1 << std::endl; // ���� ������ � ���� �������
	std::cout << "2) Second random matrix: " << "\n" << matrix2 << std::endl;

	std::cout << "3) Addition: " << "\n" << matrix1 + matrix2 << std::endl; // ���� ��������

	Matrix matrix3(3, 3); // ������� ������ ������� �������
	matrix3.fillZeros();
	matrix3 += matrix1; // 1 = 3 ������� ��� ��������

	std::cout << "4) In-place addition: " << "\n" << matrix3 << std::endl; // ��� ��� �����
	std::cout << "5) Grab value by index: " << "\n" << matrix1[0][0] << std::endl; // ������ �� �������

	matrix3[0][0] = 9999; // ��������� �� �������

	std::cout << "6) Change value by index: " << "\n" << matrix3 << std::endl;

	std::cout << "7) Subtraction: " << "\n" << matrix1 - matrix2 << std::endl;

	matrix3 -= matrix1;

	std::cout << "8) In-place subtraction: " << "\n" << matrix3 << std::endl;
	std::cout << "9) Multiplication: " << matrix1 * matrix2 << std::endl;

	matrix1.fillZeros(); //=?
	matrix2.fillZeros();

	bool is_equal = matrix1 == matrix2;
	std::cout << "10) Equality test: " << "\n" << is_equal << std::endl; // ������� 1

	matrix1[0][0] = 4389; // ������ �������
	bool is_not_equal = matrix1 != matrix2;
	std::cout << "11) Inequality test: " << "\n" << is_not_equal << std::endl; // ������� 1
}
