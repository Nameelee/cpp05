#pragma once//??
#include "AForm.h"
#include <string>

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string & target);
        PresidentialPardonForm(const PresidentialPardonForm & copy);
        PresidentialPardonForm & operator=(const PresidentialPardonForm & other);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const & executor) const;
};