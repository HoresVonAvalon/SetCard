interface Shape {
   void draw();
}

class Circle implements Shape {
   @Override
   public void draw() {
      System.out.println("Drawing Circle");
   }
}

class Rectangle implements Shape {
   @Override
   public void draw() {
      System.out.println("Drawing Rectangle");
   }
}

class Square implements Shape {
   @Override
   public void draw() {
      System.out.println("Drawing Square");
   }
}

interface AbstractFactory {
   Shape getShape(String shapeType);
}

class ShapeFactory implements AbstractFactory {
   @Override
   public Shape getShape(String shapeType) {
      if (shapeType == null) {
         return null;
      }
      if (shapeType.equalsIgnoreCase("CIRCLE")) {
         return new Circle();
      } else if (shapeType.equalsIgnoreCase("RECTANGLE")) {
         return new Rectangle();
      } else if (shapeType.equalsIgnoreCase("SQUARE")) {
         return new Square();
      }
      return null;
   }
}

class FactoryProducer {
   public static AbstractFactory getFactory(String choice) {
      if (choice.equalsIgnoreCase("SHAPE")) {
         return new ShapeFactory();
      }
      return null;
   }
}

public class AbstractFactoryDemo {
   public static void main(String[] args) {
      AbstractFactory shapeFactory = FactoryProducer.getFactory("SHAPE");
      Shape shape1 = shapeFactory.getShape("CIRCLE");
      shape1.draw();
      Shape shape2 = shapeFactory.getShape("RECTANGLE");
      shape2.draw();
      Shape shape3 = shapeFactory.getShape("SQUARE");
      shape3.draw();
   }
}
