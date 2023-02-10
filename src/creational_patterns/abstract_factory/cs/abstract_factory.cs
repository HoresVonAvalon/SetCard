using System;

// Abstract Factory
abstract class ShapeFactory
{
    public abstract Shape GetShape(string shapeType);
}

// Concrete Factory
class CircleShapeFactory : ShapeFactory
{
    public override Shape GetShape(string shapeType)
    {
        if (shapeType.Equals("Circle", StringComparison.OrdinalIgnoreCase))
        {
            return new Circle();
        }

        return null;
    }
}

// Concrete Factory
class RectangleShapeFactory : ShapeFactory
{
    public override Shape GetShape(string shapeType)
    {
        if (shapeType.Equals("Rectangle", StringComparison.OrdinalIgnoreCase))
        {
            return new Rectangle();
        }

        return null;
    }
}

// Abstract Product
abstract class Shape
{
    public abstract void Draw();
}

// Concrete Product
class Circle : Shape
{
    public override void Draw()
    {
        Console.WriteLine("Drawing Circle");
    }
}

// Concrete Product
class Rectangle : Shape
{
    public override void Draw()
    {
        Console.WriteLine("Drawing Rectangle");
    }
}

class Program
{
    static void Main(string[] args)
    {
        ShapeFactory factory = new CircleShapeFactory();
        Shape circle = factory.GetShape("Circle");
        circle.Draw();

        factory = new RectangleShapeFactory();
        Shape rectangle = factory.GetShape("Rectangle");
        rectangle.Draw();
    }
}
