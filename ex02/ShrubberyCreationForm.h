#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
#include "AForm.h"
#include <string>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;//name of yard to put Shrubbery tree in 

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string & target);
        ShrubberyCreationForm(const ShrubberyCreationForm & copy);
        ShrubberyCreationForm & operator=(const ShrubberyCreationForm & other);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;

};

#endif