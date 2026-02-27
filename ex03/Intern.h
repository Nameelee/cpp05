#ifndef INTERN_H
#define INTERN_H
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <string>

class Intern {

    private:
        AForm* makeShrubbery(std::string target);
        AForm* makeRobotomy(std::string target);
        AForm* makePresidential(std::string target);
        
    public:
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm * makeForm(std::string formName, std::string target);
};

#endif