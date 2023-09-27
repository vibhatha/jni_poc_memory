#include <string>

class Person {

  public:
   Person(std::string firstName, std::string lastName, std::string address, int age);

   std::string getFirstName();

   std::string getLastName();

   std::string getAddress();

   int getAge();

   std::string ToString();

  private:
    std::string firstName_;
    std::string lastName_;
    std::string address_;
    int age_;
};