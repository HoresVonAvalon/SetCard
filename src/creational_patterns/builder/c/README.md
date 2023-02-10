# Builder pattern in C 

The builder pattern is a creational design pattern that allows for the step-by-step creation of complex objects using a builder object. 
It allows you to create objects in a fluent and readable manner and to separate the construction of a complex object from its representation.

In this example, the EmployeeBuilder struct has a single function create which is used to create an Employee object. 
The createEmployee function is used to create an Employee object by calling the create function on the passed EmployeeBuilder object. 
The main function creates an EmployeeBuilder object, sets its create function to newEmployee, 
and uses the createEmployee function to create an Employee object.
