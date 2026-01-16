#include "Dog.h"
#include <iostream>

Dog::Dog () : Animal()
{
    this->type = "Dog";
    std::cout << type << " constructor called" << std::endl;
} 

Dog::Dog(const Dog &copy) : Animal(copy)
{
    *this = copy;
    std::cout << type << "Copy constructor called" <<std::endl;
}

Dog& Dog::operator=(const Dog& assign)
{
    if (this != &assign) {
        Animal::operator=(assign);// 부모 클래스의 대입 연산자 호출 (type 복사)
    }
    return *this;
}

Dog::~Dog() {
    std::cout << type << " Destructor called" << std::endl;
}

void Dog::makeSound() const//'const' here mean: you can't change anything
{
    std::cout << "Woof Woof!" << std::endl;
}
