#include "ShrubberyCreationForm.h"
#include "Bureaucrat.h"
#include <fstream>//to make file

ShrubberyCreationForm::ShrubberyCreationForm()
 : AForm("ShrubberyCreationForm", 145, 137), _target("default_target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target)
 : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & copy)
 : AForm(copy), _target(copy._target)
{

}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
    if(this != & other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkRequirement(executor);
    std::string filename = this->_target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    //std::ofstream: Output File Stream의 약자로, **"파일에 무언가를 출력(쓰기)하겠다"**
    //c_str():파일 입출력 함수는 무조건 C 스타일의 문자열(const char*)만 받도록 옛날 방식으로 만들어져 있습니다. 
    //그래서 std::string을 C 스타일로 변환해 주는 마법의 함수 .c_str()을 붙여준 것
    if(!outfile.is_open())
    {
        std::cerr << "Error:Could not open file " << filename << std::endl;
        return;
    }

    //ASCII picture
    outfile << "               ,@@@@@@@," << std::endl;
    outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    outfile << "       |o|        | |         | |" << std::endl;
    outfile << "       |.|        | |         | |" << std::endl;
    outfile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

    outfile.close();// 파일 닫기
}