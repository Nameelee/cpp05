#include "Bureaucrat.h"
#include "Intern.h"
#include <iostream>

int main(void)
{
    Intern someRandomInter;
    Bureaucrat boss("Boss", 1);
    AForm * rrf;

    std::cout << "===TEST 1: Robotomy Request Success===" << std::endl;
    rrf = someRandomInter.makeForm("robotomy request", "Bender");
    
    if (rrf != NULL)
    {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "===TEST 2: President Pardon Success===" <<std::endl;
    rrf = someRandomInter.makeForm("presidential pardon", "Ronald Reagan");

    if (rrf != NULL)
    {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "===TEST 3: Wrong Name of form===" <<std::endl;
    rrf = someRandomInter.makeForm("presidental pardon", "Ronald Reagan");

    if (rrf != NULL)
    {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    else
    {
        std::cout << "You input wrong letter of form" <<std::endl;//it will be reached when makeForm failed. 
    }

    return 0; 
}



    