#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm()
  : AForm("PresidentialPardonForm", 72, 45), _target("default_target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target)
 : AForm("PresidentialPardonForm", 72, 45), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & copy)
 : AForm(copy), _target(copy._target)
{

}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
    if(this != & other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    checkRequirement(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}