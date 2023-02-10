# SetCard
Show off and memo Repo

## Creational Patterns

Creational patterns are design patterns that deal with object creation maechanisms, trying to create objects in a manner suitable to the situation. The basic form of object creation could result in design problems or added complexity to the design. Creational design patterns solve this problem by somehow controlling this object creation.

Here are some of the commen creational patterns:
1. Abstract Factory:  Provides an interface for creating families of related or dependent objects without specifying their concrete classes.
2. Builder: Separates object construction form its representaion, allowing the same construction process to create different representation.
3. Factory Method: Creates objects without specifying the exact class of object that will be created.
4. Prototype: A fully initialized instance to be copied or cloned.
5. Singleton: A class of which only a singel instance can exist.

These patterns provide a convenient way to create objects and help to reduce the complexity in the desgn be breaking down the creation process into smaller, more manageable parts.

### Abstract Factory

Here is an example of the Abstract Factory pattern in C:

```c
#include<stdio.h>

enum ShapeType { CIRCLE, RECTANGLE };

// abstract product A
typedef struct shape_s shape_t;
struct shape_s {
  void (*draw)(shape_t *);
};

// concrete product A1
typedef struct circle_s {
  shape_t shape;
  int x, y, radius;
} circle_t;

void draw_circle(shape_t *shape) {
  circle_t *circle = (circle_t *) shape;
  printf("Circle: x = %d, y = %d, radius = %d\n",
         circle->x, circle->y, circle->radius);
}

// concrete product A2
typedef struct rectangle_s {
  shape_t shape;
  int x, y, width, height;
} rectangle_t;

void draw_rectangle(shape_t *shape) {
  rectangle_t *rectangle = (rectangle_t *) shape;
  printf("Rectangle: x = %d, y = %d, width = %d, height = %d\n",
         rectangle->x, rectangle->y, rectangle->width, rectangle->height);
}

// abstract factory
typedef struct factory_s factory_t;
struct factory_s {
  shape_t* (*create_shape)(factory_t *, ShapeType);
};

// concrete factory 1
typedef struct shape_factory_s {
  factory_t factory;
} shape_factory_t;

shape_t* create_shape(factory_t *factory, ShapeType type) {
  switch (type) {
    case CIRCLE:
      {
        circle_t *circle = malloc(sizeof(circle_t));
        circle->shape.draw = draw_circle;
        circle->x = 0;
        circle->y = 0;
        circle->radius = 0;
        return (shape_t *) circle;
      }
    case RECTANGLE:
      {
        rectangle_t *rectangle = malloc(sizeof(rectangle_t));
        rectangle->shape.draw = draw_rectangle;
        rectangle->x = 0;
        rectangle->y = 0;
        rectangle->width = 0;
        rectangle->height = 0;
        return (shape_t *) rectangle;
      }
    default:
      return NULL;
  }
}

int main() {
  factory_t *factory = (factory_t *) malloc(sizeof(shape_factory_t));
  factory->create_shape = create_shape;
  shape_t *circle = factory->create_shape(factory, CIRCLE);
  shape_t *rectangle = factory->create_shape(factory, RECTANGLE);
  circle->draw(circle);
  rectangle->draw(rectangle);
  free(circle);
  free(rectangle);
  free(factory);
  return 0;
}
```
