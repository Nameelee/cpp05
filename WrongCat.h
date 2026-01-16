#ifndef WRONGCAT_H
# define WRONGCAT_H

# include <iostream>
# include <string>
# include "WrongAnimal.h"

class WrongCat : public WrongAnimal {

    public:
        WrongCat();
        WrongCat(const WrongCat& copy);
        WrongCat& operator=(const WrongCat& assign);
        ~WrongCat();

    public:
        void makeSound() const;
};

#endif