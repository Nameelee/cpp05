#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat () : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << type << " constructor called" << std::endl;
} 

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    *this = copy;
    std::cout << type << "Copy constructor called" <<std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& assign)
{
    if (this != &assign) {
        WrongAnimal::operator=(assign);
        std::cout << type << " Copy Assignment operator called" <<std::endl;       
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << type << " Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongMew WrongMew!" << std::endl;
}
