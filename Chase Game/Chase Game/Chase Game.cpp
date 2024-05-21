#include <iostream>
#include <iomanip>
#include <conio.h>
#include <random>
#include <Windows.h>
#include <cassert>
#include "Character.h"
#include "Arena.h"
#include "Predator.h"
#include "Prey.h"
#include "Console.h"

unsigned int ask_distance() {
	unsigned int distance;
	setCursorPosition(35, 35);
	std::cout << "Дистанция: "; std::cin >> distance;
	assert(std::cin); // Убеждаемся, что ввели не букву, а цифру
	setCursorPosition(0, 0);
	return distance;
}

int main()
{
	unsigned short int player_choice;
	char dir_choice = ' ';
	bool game_over = false;
	Arena arena(30, 30);
	Predator predator(1, 1);
	Prey prey(15, 15);
	// Инициализация всего, что потребуется
	arena.placeCharacter(predator, "**");
	arena.placeCharacter(prey, "()");

	std::cout << "Выбери игрока:\n1 --- Жертва ()\n2 --- Охотник **\nВыбор: ";
	std::cin >> player_choice;
	assert(std::cin); // Убеждаемся, что ввели не букву, а цифру
	
	setCursorPosition(0, 0);
	switch (player_choice)
	{
	case 2:
		arena.Draw();
		while (!game_over) {
			// Пока не конец игры
			unsigned int distance = 0; // Инициализируем дистанцию
			dir_choice = _getch(); // Получаем направление движения без нажатия Enter

			// Получаем предыдущие координаты
			int prev_x = predator.getPosition().x;
			int prev_y = predator.getPosition().y;

			//Инициализируем новую точку
			Point2D new_pos(prev_x, prev_y);
			setCursorPosition(0, 0);
			switch (dir_choice) {

			case 'w':
				distance = ask_distance();
				if (distance <= 3) {
					prev_y -= distance;	
				}
				break;

			case 'a':
				distance = ask_distance();
				if (distance <= 3) {
					prev_x -= distance;
				}
				break;

			case 'x':
				distance = ask_distance();
				if (distance <= 3) {
					prev_y += distance;
				}
				break;

			case 'd':
				distance = ask_distance();
				if (distance <= 3) {
					prev_x += distance;
				}
				break;

			case 'l':
				setCursorPosition(40, 40);
				std::cout << "Выключение... ";
				exit(0);
			default:
				break;
			}
			new_pos.Change_coords(prev_x, prev_y);
			predator.Move(new_pos, arena);
			prey.moveRandomly(arena);

			arena.Draw();
			Point2D pred_pos = predator.getPosition();
			Point2D prey_pos = prey.getPosition();

			// Если расстояние между игроками < 2, игра окончена
			game_over = sqrt(pow((pred_pos.x - prey_pos.x), 2) + pow((pred_pos.y - prey_pos.y), 2)) <= 2.0;
		}
		std::cout << "Ты выиграл! ";
		break;

	case 1:
		arena.Draw();
		while (!game_over) {
			unsigned int distance = 0;
			dir_choice = _getch();
			int prev_x = prey.getPosition().x;
			int prev_y = prey.getPosition().y;
			Point2D new_pos(prev_x, prev_y);
			setCursorPosition(0, 0);
			switch (dir_choice) {

			case 'q': prev_x--; prev_y--; break;
			case 'w':           prev_y--; break;
			case 'e': prev_x++; prev_y--; break;
			case 'd': prev_x++;           break;
			case 'c': prev_x++; prev_y++; break;
			case 'x':           prev_y++; break;
			case 'z': prev_x--; prev_y++; break;
			case 'a': prev_x--;           break;
			case 'l':
				setCursorPosition(40, 40);
				std::cout << "Выключение... ";
				exit(0);
			default:
				break;
			}
			setCursorPosition(0, 0);
			new_pos.Change_coords(prev_x, prev_y);
			prey.Move(new_pos, arena);
			
			predator.moveTowards(prey.getPosition(), arena);
			setCursorPosition(0, 0);
			arena.Draw();
			Point2D pred_pos = predator.getPosition();
			Point2D prey_pos = prey.getPosition();

			game_over = sqrt(pow((pred_pos.x - prey_pos.x), 2) + pow((pred_pos.y - prey_pos.y), 2)) <= 1.0;
		}
		std::cout << "Ты проиграл... ";
		break;

	default:
		std::cout << "Нет такой опции!\n";
		break;
	}
}
