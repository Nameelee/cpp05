#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; //Forward Declaration. You should not do #include Bureaucrat. That leads 'circular dependency'

class AForm 
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm & obj);
        AForm& operator=(const AForm & obj);
        virtual ~AForm();

        virtual void execute(Bureaucrat const & executor) const = 0;

        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        void        beSigned(const Bureaucrat& Bureaucrat);
        void        checkRequirement(Bureaucrat const & executor) const;

        //Exception Classes
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class NotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        }; 
};

std::ostream & operator<<(std::ostream& os, const AForm & aform);

#endif