#include <iostream>
#include <memory>

#include "Person.h"

int main() {

  std::cout << "Hello Native Library" << std::endl;
  std::shared_ptr<Person> p1 = std::make_shared<Person>("Sam", "Nelson", "12 @ Mars", 31);
  std::cout << p1->ToString() << std::endl;
  return 0;
}