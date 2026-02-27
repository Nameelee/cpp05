#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat {

    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();

        std::string getName() const;//'const' means 'I will never change the value in the getName
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception//I will be inherited by public from 'std::exception' class
        {
            public:
                virtual const char* what() const throw();
                //virtual what() => this is overriding of what() function
                //const char* => this will return 'const char*'
                //const => this will not change the data inside
                //throw() => I will not produce any error from this function itself
        };

        class GradeTooLowException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif