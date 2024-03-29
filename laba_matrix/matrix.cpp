#include <iostream>
#include "matrix.h"


int main()
{
	Matrix matrix1(3, 3); // Создаем матрицы 3х3
	Matrix matrix2(3, 3);

	matrix1.fillRandom(); // Заполняем случайными числами
	matrix2.fillRandom();

	std::cout << " ---- Showcases ----" << std::endl;
	std::cout << "1) First random matrix: " << "\n" << matrix1 << std::endl; // Тест вывода в виде таблицы
	std::cout << "2) Second random matrix: " << "\n" << matrix2 << std::endl;

	std::cout << "3) Addition: " << "\n" << matrix1 + matrix2 << std::endl; // Тест сложения

	Matrix matrix3(3, 3); // Создаем третью нулевую матрицу
	matrix3.fillZeros();
	matrix3 += matrix1; // 1 = 3 матрице при сложении

	std::cout << "4) In-place addition: " << "\n" << matrix3 << std::endl; // Тут это видно
	std::cout << "5) Grab value by index: " << "\n" << matrix1[0][0] << std::endl; // Взятие по индексу

	matrix3[0][0] = 9999; // Изменение по индексу

	std::cout << "6) Change value by index: " << "\n" << matrix3 << std::endl;

	std::cout << "7) Subtraction: " << "\n" << matrix1 - matrix2 << std::endl;

	matrix3 -= matrix1;

	std::cout << "8) In-place subtraction: " << "\n" << matrix3 << std::endl;
	std::cout << "9) Multiplication: " << matrix1 * matrix2 << std::endl;

	matrix1.fillZeros(); //=?
	matrix2.fillZeros();

	bool is_equal = matrix1 == matrix2;
	std::cout << "10) Equality test: " << "\n" << is_equal << std::endl; // Выведет 1

	matrix1[0][0] = 4389; // Меняем элемент
	bool is_not_equal = matrix1 != matrix2;
	std::cout << "11) Inequality test: " << "\n" << is_not_equal << std::endl; // Выведет 1
}
