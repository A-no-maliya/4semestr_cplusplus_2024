#include <iostream>
#include <windows.h>  // для Sleep()
#include <ctime>  // для std::time и std::srand
#include <cstdlib>  // для std::rand и std::abs

using namespace std;

class Point2D {
public:
    int x;
    int y;

    Point2D(int x = 0, int y = 0) : x(x), y(y) {}

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    int distanceTo(const Point2D& other) const {
        return static_cast<int>(std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y)));
    }
};

class Character {
public:
    Point2D position;

    Character(int x = 0, int y = 0) : position(x, y) {}

    void setPosition(int x, int y) {
        position.x = x;
        position.y = y;
    }

    Point2D getPosition() const {
        return position;
    }

    virtual void move(int dx, int dy) {
        position.move(dx, dy);
    }
};

class Prey : public Character {
public:
    Prey(int x = 0, int y = 0) : Character(x, y) {}

    void autoMove(int width, int height) {
        // Логика автоматического движения жертвы 
        int random = std::rand() % 4;
        switch (random) {
        case 0: move(0, 1); break;    // двигается вниз
        case 1: move(0, -1); break;   // двигается вверх
        case 2: move(1, 0); break;    // двигается вправо
        case 3: move(-1, 0); break;   // двигается влево
        }

        // Проверка границ, чтобы жертва не вышла за пределы арены
        if (position.x < 0)
            position.x = 0;
        else if (position.x >= width)
            position.x = width - 1;

        if (position.y < 0)
            position.y = 0;
        else if (position.y >= height)
            position.y = height - 1;
    }
};

class Predator : public Character {
public:
    Predator(int x = 0, int y = 0) : Character(x, y) {}

    void moveTowardPrey(const Point2D& preyPos) {
        // Логика движения по направлению к жертве
        int step = 1; // Маленький шаг для более точного перемещения
        if (abs(preyPos.x - position.x) > abs(preyPos.y - position.y)) {
            if (preyPos.x < position.x)
                position.x -= step;
            else
                position.x += step;
        }
        else {
            if (preyPos.y < position.y)
                position.y -= step;
            else
                position.y += step;
        }
    }
};

class Arena {
public:
    const int width;
    const int height;
    const int movesLimit;
    Prey prey;
    Predator predator;

    Arena(int width, int height, int movesLimit)
        : width(width), height(height), movesLimit(movesLimit), prey(), predator() {
        std::srand(std::time(NULL));
        prey.setPosition(std::rand() % width, std::rand() % height);

        int max_distance = static_cast<int>(std::sqrt(width * width + height * height)) / 2;
        int distance = std::rand() % max_distance + 1;

        do {
            predator.setPosition(std::rand() % width, std::rand() % height);
        } while (prey.getPosition().distanceTo(predator.getPosition()) < distance);
    }

    void display() const {
        system("cls");
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (x == predator.getPosition().x && y == predator.getPosition().y)
                    std::cout << "H "; // HUNTER (хищник)
                else if (x == prey.getPosition().x && y == prey.getPosition().y)
                    std::cout << "P "; // PREY (жертва)
                else
                    std::cout << ". ";
            }
            std::cout << std::endl;
        }
        std::cout << "Prey - P    Predator - H" << std::endl;
    }

    bool checkCollision() const {
        return prey.getPosition().x == predator.getPosition().x && prey.getPosition().y == predator.getPosition().y;
    }
};

int main() {
    std::setlocale(LC_ALL, "Russian");

    int width, height, movesLimit;

    // Ввод параметров поля игры
    std::cout << "Введите ширину поля: ";
    std::cin >> width;
    std::cout << "Введите высоту поля: ";
    std::cin >> height;
    std::cout << "Максимальное количество ходов: ";
    std::cin >> movesLimit;

    if (width <= 0 || height <= 0 || movesLimit <= 0) {
        std::cout << "Неверные параметры. Завершение работы программы." << std::endl;
        return 1;
    }

    Arena arena(width, height, movesLimit);
    bool validUserInput;
    char ch;

    do {
        validUserInput = true;
        std::cout << "Выберите героя:" << std::endl;
        std::cout << "1. Хищник" << std::endl;
        std::cout << "2. Жертва" << std::endl;
        std::cin >> ch;

        if (ch == '1') {
            std::cout << "Хищник" << std::endl;
            std::srand(std::time(nullptr));
            int limit = movesLimit;

            while (limit > 0) {
                arena.display();
                int step;
                std::cout << "Сколько шагов (1, 2, 3): ";
                std::cin >> step;
                if (step != 1 && step != 2 && step != 3) {
                    step = 1;
                }

                char direction;
                std::cout << "Направление:" << std::endl;
                std::cout << "               w - вверх" << std::endl;
                std::cout << "a - налево    s - вниз   d - направо" << std::endl;
                std::cin >> direction;

                switch (direction) {
                case 'w':
                    arena.predator.move(0, -step);
                    break;
                case 's':
                    arena.predator.move(0, step);
                    break;
                case 'a':
                    arena.predator.move(-step, 0);
                    break;
                case 'd':
                    arena.predator.move(step, 0);
                    break;
                }

                // Проверка границ
                if (arena.predator.getPosition().x < 0)
                    arena.predator.setPosition(0, arena.predator.getPosition().y);
                else if (arena.predator.getPosition().x >= width)
                    arena.predator.setPosition(width - 1, arena.predator.getPosition().y);

                if (arena.predator.getPosition().y < 0)
                    arena.predator.setPosition(arena.predator.getPosition().x, 0);
                else if (arena.predator.getPosition().y >= height)
                    arena.predator.setPosition(arena.predator.getPosition().x, height - 1);

                if (arena.checkCollision()) {
                    std::cout << "ИГРА ОКОНЧЕНА. ВЫ ПРОИГРАЛИ" << std::endl;
                    Sleep(5000);
                    break;
                }

                arena.prey.autoMove(width, height);

                if (arena.checkCollision()) {
                    std::cout << "ИГРА ОКОНЧЕНА. ВЫ ПРОИГРАЛИ" << std::endl;
                    Sleep(5000);
                    break;
                }

                --limit;
            }
        }
        else if (ch == '2') {
            std::cout << "Жертва" << std::endl;
            std::srand(std::time(nullptr));
            int limit = movesLimit;

            while (limit > 0) {
                arena.display();

                if (arena.checkCollision()) {
                    std::cout << "ИГРА ОКОНЧЕНА. ВЫ ВЫЙГРАЛИ" << std::endl;
                    Sleep(5000);
                    break;
                }

                char direction;
                std::cout << "Направление:" << std::endl;
                std::cout << "q - влево-вверх    w - вверх    e - вправо-вверх" << std::endl;
                std::cout << "a - влево          s - вниз      d - вправо" << std::endl;
                std::cout << "z - влево-вниз               c - вправо-вниз" << std::endl;

                std::cin >> direction;

                switch (direction) {
                case 'w':
                    arena.prey.move(0, -1);
                    break;
                case 's':
                    arena.prey.move(0, 1);
                    break;
                case 'a':
                    arena.prey.move(-1, 0);
                    break;
                case 'd':
                    arena.prey.move(1, 0);
                    break;
                case 'q':
                    arena.prey.move(-1, -1);
                    break;
                case 'e':
                    arena.prey.move(1, -1);
                    break;
                case 'z':
                    arena.prey.move(-1, 1);
                    break;
                case 'c':
                    arena.prey.move(1, 1);
                    break;
                }

                // Проверка границ
                if (arena.prey.getPosition().x < 0)
                    arena.prey.setPosition(0, arena.prey.getPosition().y);
                else if (arena.prey.getPosition().x >= width)
                    arena.prey.setPosition(width - 1, arena.prey.getPosition().y);

                if (arena.prey.getPosition().y < 0)
                    arena.prey.setPosition(arena.prey.getPosition().x, 0);
                else if (arena.prey.getPosition().y >= height)
                    arena.prey.setPosition(arena.prey.getPosition().x, height - 1);

                arena.predator.moveTowardPrey(arena.prey.getPosition());

                if (arena.checkCollision()) {
                    std::cout << "ИГРА ОКОНЧЕНА. ВЫ ПРОИГРАЛИ" << std::endl;
                    Sleep(5000);
                    break;
                }

                --limit;
            }
        }
        else {
            validUserInput = false;
        }
    } while (!validUserInput);
}
