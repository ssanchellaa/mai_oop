#include <iostream>
#include "src/farray.hpp"

int main () {
    Farray *array = create_arr();

    std::cout << "Трапеция:" << std::endl;
    Point t1(1, 1), t2(3, 4), t3(6, 4), t4(8, 1);
    Trapezoid Trapezoid(t1, t2, t3, t4);
    if (Trapezoid.is_correct()) {
        add_figure(array, Trapezoid);
        std::cout << "Площадь:" << std::endl;
        std::cout << array->arr[0]->getArea() << std::endl;
        std::cout << "Текущая сумма площадей:" << std::endl;
        std::cout << sum_area(array) << std::endl;
        Point с(array->arr[0]->center());
        std::cout << "Центр трапеции: " << с << std::endl;
    }
    else {
        std::cout << "Некорректная фигура!" << std::endl;
        return 1;
    }
    std::cout << std::endl;

    std::cout << "Ромб:" << std::endl;
    Point r1(3, 1), r2(1, 4), r3(3, 7), r4(5, 4);
    Rhomb rh(r1, r2, r3, r4);
    if (rh.is_correct()) {
        add_figure(array, rh);
        std::cout << "Площадь:" << std::endl;
        std::cout << array->arr[1]->getArea() << std::endl;
        std::cout << "Текущая сумма площадей:" << std::endl;
        std::cout << sum_area(array) << std::endl;
        Point c_1(array->arr[1]->center());
        std::cout << "Центр ромба: " << c_1 << std::endl;
    }
    else {
        std::cout << "Некорректная фигура!" << std::endl;
        return 1;
    }
    std::cout << std::endl;
    
    std::cout << "Пятиугольник:" << std::endl;
    Point p1(2, 1), p2(1, 4), p3(4, 6), p4(7, 4), p5(6, 1);
    Pentagon pen(p1, p2, p3, p4, p5);
    if (pen.is_correct()) {
        add_figure(array, pen);
        std::cout << "Площадь:" << std::endl;
        std::cout << array->arr[2]->getArea() << std::endl;
        std::cout << "Текущая сумма площадей:" << std::endl;
        std::cout << sum_area(array) << std::endl;
        Point c_3(array->arr[2]->center());
        std::cout << "Центр пятиугольника: " << c_3 << std::endl;
    }
    else {
        std::cout << "Некорректная фигура!" << std::endl;
        return 1;
    }
    std::cout << std::endl;
    
    std::cout << "Фигуры в текущем массиве:" << std::endl;
    for (int i = 0; i < array->size; i++) {
        std::cout << array->arr[i] << std::endl;
    }
    
    std::cout << "Массив после удаления 1-го элемента:" << std::endl;
    array->arr = rm_figure(array, 0);
    array->size--;
    int s = array->size;
    for (int i = 0; i < s; i++) {
        std::cout << array->arr[i] << std::endl;
    }

    std::cout << "Текущая сумма площадей:" << std::endl;
    std::cout << sum_area(array) << std::endl;
    rm_arr(array);
}