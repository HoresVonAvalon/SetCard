using System;

class CarBuilder
{
    private string make;
    private string model;
    private int year;
    private string color;

    public CarBuilder SetMake(string make)
    {
        this.make = make;
        return this;
    }

    public CarBuilder SetModel(string model)
    {
        this.model = model;
        return this;
    }

    public CarBuilder SetYear(int year)
    {
        this.year = year;
        return this;
    }

    public CarBuilder SetColor(string color)
    {
        this.color = color;
        return this;
    }

    public Car Build()
    {
        return new Car(make, model, year, color);
    }
}

class Car
{
    public string Make { get; set; }
    public string Model { get; set; }
    public int Year { get; set; }
    public string Color { get; set; }

    public Car(string make, string model, int year, string color)
    {
        Make = make;
        Model = model;
        Year = year;
        Color = color;
    }
}

class Program
{
    static void Main(string[] args)
    {
        CarBuilder builder = new CarBuilder();
        Car car = builder.SetMake("Toyota").SetModel("Camry").SetYear(2020).SetColor("Red").Build();

        Console.WriteLine("Make: " + car.Make);
        Console.WriteLine("Model: " + car.Model);
        Console.WriteLine("Year: " + car.Year);
        Console.WriteLine("Color: " + car.Color);
    }
}
