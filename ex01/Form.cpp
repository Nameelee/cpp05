#include "Form.h"
#include "Bureaucrat.h"//even you did 'circular reference', you need to write this in *.cpp 

/* ==========Orthodox Canonical Form========== */

Form::Form() : _name("Default Name"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string & name, int gradeToSign, int gradeToExecute)
    :_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
//const variable should be initialized by Initializer List
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form & other) : _name(other._name), _isSigned(other._isSigned), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
//예외 처리(유효성 검사) 코드를 넣지 않은 이유는, 들어오는 other 객체가 
//"이미 검증이 끝난 완벽하게 안전한 객체"라는 것이 100% 보장되기 때문입니다.
{
}

Form& Form::operator=(const Form & other)
{
    if(this != &other)
    {
        this->_isSigned = other.getIsSigned();
        // _name, _gradeToSign, _gradeToExecute는 복사 불가 == unchangeable
        // 오직 서명 여부만 가져올 수 있습니다. Parce que those are consonat
        //actually this is useless but I wrote just for meeting 'the Orthodox Canonical Form'
    }
    return *this;
}

Form::~Form()
{
}

/* ==========Getters========== */

std::string Form::getName() const 
{ 
    return _name; 
}

bool Form::getIsSigned() const 
{ 
    return _isSigned;
}

int Form::getGradeToSign() const 
{ 
    return _gradeToSign; 
}

int Form::getGradeToExecute() const 
{ 
    return _gradeToExecute; 
}

/* ==========Main Functionality========== */
void Form::beSigned(const Bureaucrat& bureaucrat)
//@@this is the heart of this subject. interaction with other class
{
    if (bureaucrat.getGrade() > _gradeToSign)
    {
        throw Form::GradeTooLowException();
    }
    _isSigned = true;
}

/* ==========Exceptions========== */
const char* Form::GradeTooHighException::what() const throw() 
{
    //'throw()' means this function will not give at any chance
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() 
{
    return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName() 
       << ", Status: " << (form.getIsSigned() ? "Signed" : "Not Signed")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}