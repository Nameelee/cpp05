#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <string>
# include <iostream>

class WrongAnimal {

    protected:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal& operator=(const WrongAnimal &assign);
        ~WrongAnimal();

        void makeSound()const;
        std::string getType() const;
};

#endif