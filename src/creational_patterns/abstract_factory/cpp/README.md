# Abstract Factory example in C++

The code above is an example of the Abstract Factory design pattern in C++. 
It defines a set of abstract classes that define the interface for creating objects in a super-class 
but allow sub-classes to alter the type of objects that will be created.

The code defines an abstract class called Shape which acts as the base class for different shapes that can be drawn. 
It has a pure virtual function called draw() which must be implemented by concrete classes that derive from it.

The Circle and Rectangle classes are concrete implementations of the Shape class and they both override the draw() method
to provide a specific implementation for drawing a circle and a rectangle, respectively.

The AbstractFactory class is the abstract factory class and it defines the interface for creating objects. 
It has two pure virtual functions createCircle() and createRectangle() that must be implemented by concrete factories.

The ShapeFactory class is the concrete factory class and it derives from the AbstractFactory class. 
It implements the createCircle() and createRectangle() methods to return new instances of Circle and Rectangle respectively.

In the main function, an instance of ShapeFactory is created and it is used to create instances of Circle and Rectangle. 
The draw method is called on these instances to demonstrate how they can be used.

The Abstract Factory pattern allows for the creation of objects without specifying the exact class of object that will be created. 
This makes it easier to change the objects that are created without having to change the code that uses them.
