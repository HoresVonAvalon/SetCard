# Abstract factory in java

In this example, the abstract factory interface AbstractFactory defines a method getShape which returns a Shape object. 
The ShapeFactory class implements the AbstractFactory interface and returns a Circle, Rectangle, or Square object 
based on the shape type passed to the getShape method.

The FactoryProducer class provides a static method getFactory which returns an instance of the AbstractFactory interface. 
The main method uses the FactoryProducer class to get an instance of the ShapeFactory and then uses it to create objects of concrete shapes.

This code demonstrates the use of the abstract factory pattern to create objects of concrete shapes. 
The client code uses the abstract factory interface to create objects, and the concrete factory implementation 
is responsible for creating the concrete objects. This makes the code more flexible and easier to maintain.
