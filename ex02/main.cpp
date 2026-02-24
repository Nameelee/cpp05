#include "Bureaucrat.h"
#include "ShrubberCreationForm.h"
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
    return (0);
}
