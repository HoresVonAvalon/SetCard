#include <stdio.h>
#include <string.h>

typedef struct {
  char name[30];
  int age;
  char city[30];
} Person;

typedef struct {
  Person person;
  char job[30];
  float salary;
} Employee;

typedef struct {
  Employee (*create)(char *, int, char *, char *, float);
} EmployeeBuilder;

Employee newEmployee(char *name, int age, char *city, char *job, float salary) {
  Employee employee;
  strcpy(employee.person.name, name);
  employee.person.age = age;
  strcpy(employee.person.city, city);
  strcpy(employee.job, job);
  employee.salary = salary;
  return employee;
}

Employee createEmployee(EmployeeBuilder *builder, char *name, int age, char *city, char *job, float salary) {
  return builder->create(name, age, city, job, salary);
}

int main() {
  EmployeeBuilder builder;
  builder.create = newEmployee;

  Employee employee = createEmployee(&builder, "John Doe", 30, "New York", "Developer", 50000.0);

  printf("Name: %s\n", employee.person.name);
  printf("Age: %d\n", employee.person.age);
  printf("City: %s\n", employee.person.city);
  printf("Job: %s\n", employee.job);
  printf("Salary: %.2f\n", employee.salary);
  return 0;
}
