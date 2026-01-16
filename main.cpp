#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include <iostream>

int main(void)
{
    std::cout << "\n===1. Subject Test (Polymorphism)===\n" << std::endl;

    const Animal *meta = new Animal();
    const Animal *j      = new Dog();//This is upcasting. look below
    const Animal *i      = new Cat();

    std::cout << std::endl;

    std::cout << j-> getType() << " " << std::endl;
    std::cout << i-> getType() << " " << std::endl;
    i-> makeSound();
    j-> makeSound();
    meta -> makeSound();

    std::cout << std::endl;

    delete i;
    delete j;
    delete meta;

    std::cout << "\n===2. Wrong Class Test (No polymorphism) ===\n" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << std::endl;

    std::cout << "WrongCat make sound like this=====>";
    wrongCat->makeSound();
    std::cout << "WrongMeta make sound like this=====>";
    wrongMeta->makeSound();

    std::cout << std::endl;

    delete wrongCat;
    delete wrongMeta;

    return (0);
}

/*
// Animal* 하나로 개와 고양이를 동시에 관리 가능 (매우 효율적)
Animal* zoo[2];

zoo[0] = new Dog(); // Dog -> Animal* (업캐스팅)
zoo[1] = new Cat(); // Cat -> Animal* (업캐스팅)
*/