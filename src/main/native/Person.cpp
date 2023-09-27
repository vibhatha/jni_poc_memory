#include "Person.h"
#include <sstream>

 Person::Person(std::string firstName, std::string lastName, std::string address, int age)
  : firstName_(firstName), lastName_(lastName), address_(address), age_(age) {}

 std::string Person::getFirstName() {
  return firstName_;
 }

 std::string Person::getLastName() {
  return lastName_;
 }

 std::string Person::getAddress() {
  return address_;
 }

 int Person::getAge() {
  return age_;
 }

 std::string Person::ToString() {
     std::ostringstream oss;
     oss << "Name: " << firstName_ << " " << lastName_ << ", Address: " << address_ << ", Age: " << age_;
     return oss.str();
 }
