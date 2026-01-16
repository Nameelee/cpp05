#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() :type("WrongAnimal") {
    std::cout << "WrongAnimal Constructor called" <<std::endl;
} 

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    *this = copy;
    std::cout << "WrongAnimal Copy Constructor called" <<std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &assign) {
    if (this != &assign) {
        this->type = assign.type;      
    }
    std::cout << "WrongAnimal Copy Assignment Operator called" <<std::endl; 
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Are you talking to me?" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}