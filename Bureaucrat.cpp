#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    *this = copy;
    std::cout << type << "Copy constructor called" <<std::endl;
}

Cat& Cat::operator=(const Cat& assign)
{
    if (this != &assign) {
        Animal::operator=(assign);
        std::cout << type << " Copy Assignment operator called" <<std::endl;       
    }
    return *this;
}

Cat::~Cat() {
    std::cout << type << " Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Mew Mew!" << std::endl;
}
