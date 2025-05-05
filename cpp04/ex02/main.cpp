#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	{
		Cat c;
		Dog d;

		std::cout << "Cat type: " << c.getType() << ", make sound: ";
		c.makeSound();

		std::cout << "Dog type: " << d.getType() << ", make sound: ";
		d.makeSound();
	}
	{
		AAnimal *c = new Cat();
		AAnimal *d = new Dog();

		std::cout << "Cat type: " << c->getType() << ", make sound: ";
		c->makeSound();

		std::cout << "Dog type: " << d->getType() << ", make sound: ";
		d->makeSound();
	}

	// This is not possible because AAnimal is an abstract class:
	//
	// {
	// 	AAnimal *aa1 = new AAnimal();
	// 	AAnimal aa2;

	// 	std::cout << "Animal type: " << aa1->getType() << ", make sound: ";
	// 	aa1->makeSound();

	// 	std::cout << "Animal type: " << aa2.getType() << ", make sound: ";
	// 	aa2.makeSound();
	// }
}