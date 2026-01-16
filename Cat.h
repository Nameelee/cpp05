#ifndef CAT_H
# define CAT_H

# include <iostream>
# include <string>
# include "Animal.h"

class Cat : public Animal {

    public:
        Cat();
        Cat(const Cat& copy);
        Cat& operator=(const Cat& assign);
        virtual ~Cat();

    public:
        virtual void makeSound() const;
};

#endif