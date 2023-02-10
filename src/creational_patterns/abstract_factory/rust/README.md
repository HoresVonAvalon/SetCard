# Abstract factory in Rust

The code providec is an implementation of the abstract factory pattern in Rust programming language.

It defines an abstract Shape trait, which acts as the common interface for all the shapes. 
It defines a method area() that returns the area of the shape.

Next, it implements two concrete shape types, Circle and Rectangle, which implement the Shape trait. 
They have their own implementations of the area method, which returns the area of the respective shapes.

Finally, the code defines an abstract ShapeFactory trait and two concrete shape factory types, 
CircleFactory and RectangleFactory, which implement the ShapeFactory trait. They have a create() method, 
which creates and returns an instance of a specific shape.

This implementation of the abstract factory pattern in Rust allows the client code to get an instance
of a specific shape from a factory without having to know the specific implementation details of the shapes. 
The client only interacts with the common interface provided by the Shape trait and gets the desired shape from the factory using the create method.
