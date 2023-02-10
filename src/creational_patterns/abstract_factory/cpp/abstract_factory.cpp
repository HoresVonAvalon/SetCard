#include <iostream>

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() {
        std::cout << "Drawing a rectangle." << std::endl;
    }
};

class AbstractFactory {
public:
    virtual Shape* createCircle() = 0;
    virtual Shape* createRectangle() = 0;
};

class ShapeFactory : public AbstractFactory {
public:
    Shape* createCircle() {
        return new Circle();
    }
    
    Shape* createRectangle() {
        return new Rectangle();
    }
};

int main() {
    AbstractFactory* factory = new ShapeFactory();
    Shape* circle = factory->createCircle();
    Shape* rectangle = factory->createRectangle();
    
    circle->draw();
    rectangle->draw();
    
    delete circle;
    delete rectangle;
    delete factory;
    
    return 0;
}
