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
