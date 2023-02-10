trait ShapeFactory {
    fn create_rectangle(&self) -> Box<dyn Rectangle>;
    fn create_square(&self) -> Box<dyn Square>;
}

trait Rectangle {
    fn draw(&self);
}

trait Square {
    fn draw(&self);
}

struct ConcreteRectangle {
    width: u32,
    height: u32,
}

impl Rectangle for ConcreteRectangle {
    fn draw(&self) {
        println!("Drawing rectangle with width: {} and height: {}", self.width, self.height);
    }
}

struct ConcreteSquare {
    side: u32,
}

impl Square for ConcreteSquare {
    fn draw(&self) {
        println!("Drawing square with side: {}", self.side);
    }
}

struct ConcreteShapeFactory {
    width: u32,
    height: u32,
}

impl ShapeFactory for ConcreteShapeFactory {
    fn create_rectangle(&self) -> Box<dyn Rectangle> {
        Box::new(ConcreteRectangle { width: self.width, height: self.height })
    }

    fn create_square(&self) -> Box<dyn Square> {
        Box::new(ConcreteSquare { side: self.width })
    }
}

fn main() {
    let shape_factory = ConcreteShapeFactory { width: 10, height: 20 };
    let rectangle = shape_factory.create_rectangle();
    rectangle.draw();
    let square = shape_factory.create_square();
    square.draw();
}
