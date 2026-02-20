#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>

int main(void)
{
    // -------------------------------------------------------------------------
    // TEST 1: Success with Sign
    // -------------------------------------------------------------------------
    std::cout << "\n===Test 1: Success with Sign===\n" << std::endl;
    try {
        Bureaucrat bob("Bob", 2);
        Form taxForm("Tax Form", 20, 20);

        std::cout << bob << std::endl;//a
        std::cout << taxForm << std::endl;//b
        //a & b is different class so when it is called in one main.cpp they call their own operator <<
        //that is called 'Operator Overloading'

        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;//to check if the status of sign is changed
    }
    catch (std::exception &e) 
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 2: Fail with Sign : Bureaucrat's grade is too low
    // -------------------------------------------------------------------------

    std::cout << "\n===Test 2: Fail with Sign : Bureaucrat's grade is too low===\n" << std::endl;
    try 
    {
        Bureaucrat alice("Alice", 50);
        Form whiteForm("White Form", 10, 10);

        std::cout << alice << std::endl;
        std::cout << whiteForm << std::endl;

        alice.signForm(whiteForm);
        //std::cout << failForm << std::endl; //no needs this line
        //this line will be executed not like Test3. Because signForm has its own 'catch' (continue)
        //so signForm takes care of all the bomb(error) and then main function is relaxed and go to next line
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 3: Fail with Form : Form's grade is too high
    // -------------------------------------------------------------------------

    std::cout << "\n===Test 3: Fail with Form : Form's grade is too high===\n" << std::endl;
    try 
    {
        Bureaucrat eva("Eva", 10);
        Form impossibleForm("Impossible Form", 0, 50);

        //from here it should be skipped
        //@@@this is difficult. Because in constructor it just 'throw' and there is no 'catch' line. 
        //so when 'Form impossibleForm("Impossible Form", 0, 50); 'throw'errors, there is no 'catch' line
        //so the bomb from 'Form' constructor came to catch of this main fucntion. 
        //so That's why from here the codes below will not be executed

        std::cout << eva << std::endl;
        std::cout << impossibleForm << std::endl;

        eva.signForm(impossibleForm);
        std::cout << impossibleForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught from generating form: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 4: Success with Edge : Grade is deadline
    // -------------------------------------------------------------------------

    std::cout << "\n===Test 4: Sucees with Edge : Form's grade is same===\n" << std::endl;
    try 
    {
        Bureaucrat vic("Vic", 10);
        Form wetForm("Wet Form", 10, 10);

        std::cout << vic << std::endl;
        std::cout << wetForm << std::endl;

        vic.signForm(wetForm);
        std::cout << wetForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}
