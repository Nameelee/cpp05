#ifndef DOG_H
# define DOG_H

# include <iostream>
# include <string>
# include "Animal.h"

class Dog : public Animal {

    public:
        Dog();
        Dog(const Dog& copy);
        Dog& operator=(const Dog& assign);
        virtual ~Dog();

    public:
        virtual void makeSound() const;
};

#endif