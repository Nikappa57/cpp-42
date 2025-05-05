#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		std::cout << "----------------------\nCat, Dog, WrongCat\n" << std::endl;
		const Cat* i = new Cat();
		const Dog* j = new Dog();
		const WrongCat* k = new WrongCat();

		std::cout << "Cat type: " << *i << ", make sound: ";
		i->makeSound();

		std::cout << "Dog type: " << *j << ", make sound: ";
		j->makeSound();

		std::cout << "WrongCat type: " << *k << ", make sound: ";
		k->makeSound();

		delete i;
		delete j;
		delete k;
	}
	{
		std::cout << "----------------------\nWrongAnimal\n" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << "WrongAnimal WrongCat type: " << *i << ", make sound: ";
		i->makeSound();
		
		std::cout << "WrongAnimal type: " << *meta << ", make sound: ";
		meta->makeSound();

		delete meta;
		delete i;
	}
	{
		std::cout << "----------------------\nAnimal\n" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		

		std::cout << "Animal Dog type: " << *j << ", make sound: ";
		j->makeSound();

		std::cout << "Animal Cat type: " << *i << ", make sound: ";
		i->makeSound();
		
		std::cout << "Animal type: " << *meta << ", make sound: ";
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	

	return (0);
}