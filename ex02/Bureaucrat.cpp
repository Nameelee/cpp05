#include "Bureaucrat.h"
#include "AForm.h"

/* ==========Orthodox Canonical Form========== */

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != & other) {
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

/* ==========Member Functions========== */

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() // throw works as kind of return. if it is caught in throw, it will skip other code lines.
{
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << " happily.\n" << std::endl; 
    }
    catch (std::exception & e)
    {
        std::cout << this-> _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl; 
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << this->_name << "couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

/* ==========Exception Classes========== */

const char* Bureaucrat::GradeTooHighException::what() const throw()
 //부모(std::exception)가 물려준 what()이라는 기능을 자식(GradeTooHighException)이 자기 방식대로 재정의.
 //[return "Grade is too high"] is overriding
 //what() const throw()================throw() looks like function but this is not
 //this is 'Exception Specification'
 //void myFunc() throw(int, char) 
 //의미: "이 함수는 int나 char 타입의 예외만 던질 수 있어."
 //void myFunc() throw(std::exception)
 //의미: "이 함수는 std::exception 타입의 예외만 던질 수 있어."
 //void myFunc() throw()
 //의미: "이 함수는 던질 수 있는 예외 목록이 없어. 즉, 절대 예외를 던지지 않을 거야!"
 //
 // [반환타입]  [함수이름]  [파라미터] [상수여부] [예외사양]
 //const char* what       ()      const      throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
