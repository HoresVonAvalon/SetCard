interface Shape {
    public function draw();
}

class Circle implements Shape {
    public function draw() {
        echo "Drawing a Circle\n";
    }
}

class Square implements Shape {
    public function draw() {
        echo "Drawing a Square\n";
    }
}

interface Color {
    public function fill();
}

class Red implements Color {
    public function fill() {
        echo "Filling with Red\n";
    }
}

class Green implements Color {
    public function fill() {
        echo "Filling with Green\n";
    }
}

abstract class AbstractFactory {
    abstract function getShape($shapeType);
    abstract function getColor($colorType);
}

class ShapeFactory extends AbstractFactory {
    public function getShape($shapeType) {
        if ($shapeType == "CIRCLE") {
            return new Circle();
        } else if ($shapeType == "SQUARE") {
            return new Square();
        }

        return null;
    }

    public function getColor($colorType) {
        return null;
    }
}

class ColorFactory extends AbstractFactory {
    public function getShape($shapeType) {
        return null;
    }

    public function getColor($colorType) {
        if ($colorType == "RED") {
            return new Red();
        } else if ($colorType == "GREEN") {
            return new Green();
        }

        return null;
    }
}

class FactoryProducer {
    public static function getFactory($choice) {
        if ($choice == "SHAPE") {
            return new ShapeFactory();
        } else if ($choice == "COLOR") {
            return new ColorFactory();
        }

        return null;
    }
}

$shapeFactory = FactoryProducer::getFactory("SHAPE");
$shape1 = $shapeFactory->getShape("CIRCLE");
$shape1->draw();

$colorFactory = FactoryProducer::getFactory("COLOR");
$color1 = $colorFactory->getColor("RED");
$color1->fill();
