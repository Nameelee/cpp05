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
        //=0 means "이 함수는 껍데기만 있고 알맹이(구현부)는 없어!"
        //강력한 강제성: 부모인 AForm은 알맹이가 없으므로, 자식들(Shrubbery, Robotomy, Presidential)은 
        //살아남으려면 예외 없이 자기만의 execute() 함수를 직접 만들어야 합니다. 
        //안 만들면 컴파일러가 에러를 뿜으며 빌드를 거부합니다.

        //Getters
        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        //Main Functionality
        void        beSigned(const Bureaucrat& Bureaucrat);
        void        checkRequirement(Bureaucrat const & executor) const;

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