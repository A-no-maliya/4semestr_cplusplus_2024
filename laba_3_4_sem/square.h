#pragma once
#include <iostream>
#include "shape2d.h"

// Concrete class for a Square
class Square : public Shape2D {
private:
    float side;
public:
    Square(float side) : side(side) {
        CalculateArea();
    }

    void Scale(float scaleFactor) override {
        side *= scaleFactor;
        CalculateArea();
    }

    void ShowInfo() const override {
        std::cout << "� �������!" << std::endl;
        std::cout << "��� ������� = " << area << std::endl;
        std::cout << "����� ������� = " << side << std::endl;
    }

    std::string GetName() const override {
        return "Square";
    }

    void CalculateArea() override {
        area = side * side;
    }
};
