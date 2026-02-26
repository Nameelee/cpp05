#include "RobotomyRequestForm.h"
#include "Bureaucrat.h"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm()  : AForm("RobotomyRequestForm", 72, 45), _target("default_target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & copy) : AForm(copy), _target(copy._target)
{

}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
    if(this != & other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
    {
        throw AForm::NotSignedException();
    }

    if (executor.getGrade() > this->getGradeToExecute())
    {
        throw AForm::GradeTooLowException();
    }

    std::cout << "Drrrrrrrrrrr... Bzzzzzt..." << std::endl;

    if(rand() % 2 == 0)
    {
        std::cout << this->_target << "has been robotomized successfully!" << std::endl;
    } 
    else
    {
        std::cout << "The robotomy on " << this->_target << " failed." << std::endl;
    } 
}