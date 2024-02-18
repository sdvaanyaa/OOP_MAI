#include "../include/trapezoid.h"
#include "../include/square.h"
#include "../include/rectangle.h"
#include <iostream>

#define SHAPE_COUNT 3

void erase(Shape** &shapes, int &shapesSize, int index);
void printElemsAndTotalSurface(Shape** shapes, int shapesSize);
void pushBack(Shape** &shapes,int &shapesCap, int &shapesSize, Shape* shape);

int main(){
    
    Shape** shapes = new Shape*[SHAPE_COUNT];
    int shapesCap = SHAPE_COUNT;
    int shapesSize = 0;

    Square sq;
    pushBack(shapes, shapesCap, shapesSize, &sq);

    Rectangle rect;
    pushBack(shapes, shapesCap, shapesSize, &rect);

    Trapezoid trap;
    pushBack(shapes, shapesCap, shapesSize, &trap);

    printElemsAndTotalSurface(shapes, shapesSize);

    std::cout << "Enter the index of element to delete: " << std::endl;
    int delIdx;
    std::cin >> delIdx;
    
    erase(shapes, shapesSize, delIdx);

    printElemsAndTotalSurface(shapes, shapesSize);

    return 0;
}

void pushBack(Shape** &shapes,int &shapesCap, int &shapesSize, Shape* shape){
    if (shapesSize == shapesCap){
        Shape** tmp = new Shape*[shapesCap*2];
        for (int i = 0; i < shapesCap; ++i){
            tmp[i] = shapes[i];
        }
        delete[] shapes;
        shapes = tmp;
        shapesCap *= 2;
    }
    shapes[shapesSize] = shape;
    shapesSize += 1;
}

void erase(Shape** &shapes, int &shapesSize, int delIdx){
    if (delIdx >= shapesSize && delIdx < 0){
        std::cout << "Invalid index!" << std::endl;
    }
    if (delIdx == shapesSize - 1){
        shapesSize -= 1;
        return;
    }

    Shape** tmp = new Shape*[shapesSize - 1];
    int i, j = 0; //i - for shapes, j - for tmp
    for (; i < SHAPE_COUNT; ++i, ++j){
        if (i == delIdx){
            --j;
            continue;
        }
        tmp[j] = shapes[i];
    }

    delete[] shapes;
    shapes = tmp;
    shapesSize -= 1;
}

void printElemsAndTotalSurface(Shape** shapes, int shapesSize){
    double totalSurface = 0;
    for (int i = 0; i < shapesSize; ++i){
        shapes[i]->readCin();
        shapes[i]->printCout();
        std::cout << i+1 << "-shape's center: " << shapes[i]->center() << std::endl;
        std::cout << i+1 << "-shape's surface: " << shapes[i]->surface() << std::endl;
        totalSurface += shapes[i]->surface();
    }
    std::cout << "Total surface: " << totalSurface << std::endl;
}
