#include "Bureaucrat.h"
#include <iostream>

int main(void)
{
    // -------------------------------------------------------------------------
    // TEST 1: Normal increment
    // -------------------------------------------------------------------------
    std::cout << "\n===Test 1: Normal Operation===\n" << std::endl;
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        std::cout << "Incrementing grade..." << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;

        std::cout << "Decrementing grade..." << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        //cerr is standard error <==> std::cout
    }

    // -------------------------------------------------------------------------
    // TEST 2: Constructor Exception : Grade too high
    // -------------------------------------------------------------------------

    std::cout << "\n===Test 2: Constructor (Grade too high)===\n" << std::endl;
    try 
    {
        Bureaucrat simon("Simon", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 3: Constructor Exception : Grade is too low
    // -------------------------------------------------------------------------

    std::cout << "\n===Test 3: Constructor (Grade too low)===\n" << std::endl;
    try 
    {
        Bureaucrat eva("Eva", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 4: Over Upgrading : Increment Limit
    // -------------------------------------------------------------------------

    std::cout << "\n===Test 4: Increment Limit===\n" << std::endl;
    try 
    {
        Bureaucrat dia("Dia", 1);
        std::cout << dia << std::endl;
        std::cout << "Attempting to increment grade 1..." << std::endl;
        dia.incrementGrade();
        std::cout << "This line should not be printed!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    // TEST 5: Over Downgrading : Decrement Limit
    // -------------------------------------------------------------------------

    std::cout << "\n===Test 5: Decrement Limit===\n" << std::endl;
    try 
    {
        Bureaucrat deva("Deva", 150);
        std::cout << deva << std::endl;
        std::cout << "Attempting to decrement grade 150..." << std::endl;
        deva.decrementGrade();
        std::cout << "This line should not be printed!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return (0);
}
