#include <iostream>
#include <string>

class Car {
 public:
  Car(std::string color, std::string model, std::string engine)
      : color_(color), model_(model), engine_(engine) {}
  std::string color_;
  std::string model_;
  std::string engine_;
};

class CarBuilder {
 public:
  CarBuilder& setColor(std::string color) {
    color_ = color;
    return *this;
  }
  CarBuilder& setModel(std::string model) {
    model_ = model;
    return *this;
  }
  CarBuilder& setEngine(std::string engine) {
    engine_ = engine;
    return *this;
  }
  Car build() { return Car(color_, model_, engine_); }

 private:
  std::string color_;
  std::string model_;
  std::string engine_;
};

int main() {
  CarBuilder builder;
  builder.setColor("Red").setModel("Sedan").setEngine("V8");
  Car car = builder.build();

  std::cout << "Car color: " << car.color_ << std::endl;
  std::cout << "Car model: " << car.model_ << std::endl;
  std::cout << "Car engine: " << car.engine_ << std::endl;

  return 0;
}
