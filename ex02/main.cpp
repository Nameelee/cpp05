#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <iostream>

int main(void)
{
    // -------------------------------------------------------------------------
    // TEST 1: Shrubbery Creation Success
    // -------------------------------------------------------------------------
    std::cout << "\n===Test 1: Shrubbery Creation Success===\n" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm tree("home");

        std::cout << boss << std::endl;//a
        std::cout << tree << std::endl;//b
        //a & b is different class so when it is called in one main.cpp they call their own operator <<
        //that is called 'Operator Overloading'

        boss.signForm(tree);
        tree.execute(boss);
        std::cout << "Check if there is 'home _shrubbery file" << std::endl;//to check if the status of sign is changed
    }
    catch (std::exception &e) 
    {
        std::cerr << "Error caught: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 2: Fail with Execute : Execute without signing
    // -------------------------------------------------------------------------

    std::cout << "\n===Test 2: Fail with Execute : Execute without signing===\n" << std::endl;
    try 
    {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm tree("garden");

        tree.execute(boss);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error caught: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 3: Fail with Execute : Grade too low to execute
    // -------------------------------------------------------------------------

    std::cout << "\n===Test 3: Fail with Execute : Grade too low to execute===\n" << std::endl;
    try 
    {
        Bureaucrat newbie("Newbie", 140);
        ShrubberyCreationForm tree("park");

        newbie.signForm(tree);
        tree.execute(newbie);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error caught: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 4: Robotomy Request (50% random)
    // -------------------------------------------------------------------------

    std::cout << "\n=== Test 4: Robotomy Request (50% random) ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot("Bender");

        boss.signForm(robot);

        std::cout << "\n[ Trying surgery 4 times! ]\n";
        boss.executeForm(robot);//boss is Bureaucrat class. I was confused with RobotomyRequestForm::execute
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);

    } catch (std::exception &e) {
        std::cerr << "Error caught: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 5: Presidential Pardon Form
    // -------------------------------------------------------------------------

    std::cout << "\n=== TEST 5: Presidential Pardon Form===" << std::endl;
    try {
        Bureaucrat peter("Peter", 1);
        PresidentialPardonForm white("White");

        peter.signForm(white);
        peter.executeForm(white);
        
    } catch (std::exception &e) {
        std::cerr << "Error caught: " << e.what() << std::endl;
    }

    return (0);
}



    