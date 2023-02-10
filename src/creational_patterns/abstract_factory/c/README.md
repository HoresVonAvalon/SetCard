# Abstract Factory in C

The code I provided is an example of the Abstract Factory design pattern in C programming language.

In this code, the Abstract Factory interface ShapeFactory has two methods, CreateCircle and CreateRectangle,
which are both pure virtual functions and need to be implemented by concrete implementations. 
The concrete factory implementations, RoundedShapeFactory and ShapeFactoryImpl, both provide specific implementations of these methods.

The Shape struct represents the abstract product and has a Draw method. The concrete products, Circle and Rectangle, 
both implement the Shape struct and override the Draw method to provide their specific implementation.

In the main function, the GetShapeFactory function returns an instance of either the RoundedShapeFactory or the ShapeFactoryImpl
depending on the input parameter. The returned factory is then used to create an instance of either a Circle or a Rectangle 
and the Draw method is called on it.
