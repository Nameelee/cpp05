#include "Intern.h"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern& copy)
{
    (void)copy;//@@what is this? 
}

Intern & Intern::operator=(const Intern & other) 
{
    (void)other;//@@what is this?
    return *this;
}

Intern::~Intern() 
{
};

AForm* Intern::makeShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);//@@why there is 'new' keyword?
}

AForm* Intern::makeRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidential(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    //static을 붙여서 프로그램 수명 주기 동안 딱 '한 번'만 배열을 생성합니다!
    static const std::string formNames[3] = {
        "shrubbery creation", 
        "robotomy request", 
        "presidential pardon"
    };

    //함수 포인터 배열도 static으로 만들어 메모리 낭비를 원천 차단합니다!
    static AForm* (Intern::*formMakers[3])(std::string) = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };//@@What is function pointer? 

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formMakers[i])(target); 
        }
    }

    std::cout << "Intern cannot create " << formName << " because it doesn't exist." << std::endl;
    return NULL;
}