#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; //Forward Declaration. You should not do #include Bureaucrat. That leads 'circular dependency'

class Form 
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        //Orthodoex Cannonical Form
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form & obj);
        Form& operator=(const Form & obj);
        ~Form();
        //Getters
        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;
};

std::ostream & operator<<(std::ostream& os, const Form & form);

#endif