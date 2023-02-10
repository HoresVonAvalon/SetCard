# Abstract factory in java script

The above code is an example of an abstract factory design pattern in JavaScript. 
It creates a factory function for creating geometric shapes. 
The factory function is called GeometricShapeFactory and it has two methods: getShape and getColor.

The getShape method takes a string parameter that represents the type of shape that the user wants to create. 
It returns an object that implements the Shape interface and has a method called draw that is used to draw the shape.

The getColor method takes a string parameter that represents the color that the user wants to use for the shape. 
It returns an object that implements the Color interface and has a method called fill that is used to fill the shape with the specified color.

By using the abstract factory pattern, the code can be easily extended to add more shapes or 
colors in the future without having to modify the existing code.
