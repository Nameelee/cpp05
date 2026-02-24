#pragma once//??
#include "AForm.h"
#include <string>

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string & target);
        RobotomyRequestForm(const RobotomyRequestForm & copy);
        RobotomyRequestForm & operator=(const RobotomyRequestForm & other);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const;
};