#include "AForm.h"
#include "Bureaucrat.h"//even you did 'circular reference', you need to write this in *.cpp 

/* ==========Orthodox Canonical Form========== */

AForm::AForm() : _name("Default Name"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(const std::string & name, int gradeToSign, int gradeToExecute)
    :_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
//const variable should be initialized by Initializer List
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm & other) : _name(other._name), _isSigned(other._isSigned), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
//예외 처리(유효성 검사) 코드를 넣지 않은 이유는, 들어오는 other 객체가 
//"이미 검증이 끝난 완벽하게 안전한 객체"라는 것이 100% 보장되기 때문입니다.
{
}

AForm& AForm::operator=(const AForm & other)
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

AForm::~AForm()//even in header it is declared as 'virtual', should not put virtual in *.cpp 
{
}

/* ==========Getters========== */

std::string AForm::getName() const 
{ 
    return _name; 
}

bool AForm::getIsSigned() const 
{ 
    return _isSigned;
}

int AForm::getGradeToSign() const 
{ 
    return _gradeToSign; 
}

int AForm::getGradeToExecute() const 
{ 
    return _gradeToExecute; 
}

/* ==========Main Functionality========== */
void AForm::beSigned(const Bureaucrat& bureaucrat)
//@@this is the heart of this subject. interaction with other class
{
    if (bureaucrat.getGrade() > _gradeToSign)
    {
        throw AForm::GradeTooLowException();
    }
    _isSigned = true;
}

/* ==========Exceptions========== */
const char* AForm::GradeTooHighException::what() const throw() 
{
    //'throw()' means this function will not give at any chance
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() 
{
    return "Grade is too low!";
}

const char* AForm::NotSignedException::what() const throw() 
{
    return "This isn't signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName() 
       << ", Status: " << (form.getIsSigned() ? "Signed" : "Not Signed")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}