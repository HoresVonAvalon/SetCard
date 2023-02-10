// Abstract factory
class ShapeFactory {
    createShape(type) {
        throw new Error("This method must be overridden.");
    }
}

// Concrete factories
class CircleFactory extends ShapeFactory {
    createShape(type) {
        switch (type) {
            case "small":
                return new SmallCircle();
            case "large":
                return new LargeCircle();
            default:
                throw new Error(`Unknown circle type: ${type}`);
        }
    }
}

class RectangleFactory extends ShapeFactory {
    createShape(type) {
        switch (type) {
            case "square":
                return new Square();
            case "rectangle":
                return new Rectangle();
            default:
                throw new Error(`Unknown rectangle type: ${type}`);
        }
    }
}

// Abstract shape
class Shape {
    draw() {
        throw new Error("This method must be overridden.");
    }
}

// Concrete shapes
class SmallCircle extends Shape {
    draw() {
        console.log("Drawing a small circle.");
    }
}

class LargeCircle extends Shape {
    draw() {
        console.log("Drawing a large circle.");
    }
}

class Square extends Shape {
    draw() {
        console.log("Drawing a square.");
    }
}

class Rectangle extends Shape {
    draw() {
        console.log("Drawing a rectangle.");
    }
}

// Client
class Client {
    main() {
        const circleFactory = new CircleFactory();
        const rectangleFactory = new RectangleFactory();

        const smallCircle = circleFactory.createShape("small");
        smallCircle.draw();

        const largeCircle = circleFactory.createShape("large");
        largeCircle.draw();

        const square = rectangleFactory.createShape("square");
        square.draw();

        const rectangle = rectangleFactory.createShape("rectangle");
        rectangle.draw();
    }
}

const client = new Client();
client.main();
