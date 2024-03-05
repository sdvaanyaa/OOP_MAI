#include "../include/trapezoid.hpp"
#include "../include/square.hpp"
#include "../include/rectangle.hpp"
#include "../include/array.hpp"
#include <memory>

int main(){

    Array<std::shared_ptr<Shape<double>>> shapes{
        std::make_shared<Square<double>>(),
        std::make_shared<Rectangle<double>>(),
        std::make_shared<Trapezoid<double>>()
    };

    double totalSurface = 0;
    for (int i = 0; i < shapes.size(); ++i){
        shapes[i]->readCin();
        shapes[i]->printCout();
        std::cout << i+1 << "-shape's center: " << shapes[i]->center() << std::endl;
        std::cout << i+1 << "-shape's surface: " << shapes[i]->surface() << std::endl;
        totalSurface += shapes[i]->surface();
    }
    std::cout << "Total surface: " << totalSurface << std::endl;

    std::cout << "Enter the index of element to delete: " << std::endl;
    int delIdx;
    std::cin >> delIdx;
    
    shapes.eraseElem(delIdx);

    for (int i = 0; i < shapes.size(); ++i){
        shapes[i]->printCout();
    }

    return 0;
}
