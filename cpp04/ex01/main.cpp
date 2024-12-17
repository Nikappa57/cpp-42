#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

# define ARR_N 5

int main() {
	Dog *dog = new Dog();
	Cat *cat = new Cat();

	std::cout << "----------------------\nPart 1\n" << std::endl;

	std::cout << "Dog type: " << *dog << ", make sound: ";
	dog->makeSound();

	std::cout << "Cat type: " << *cat << ", make sound: ";
	cat->makeSound();

	Brain *dogBrain;
	Brain *catBrain;

	dogBrain = dog->getBrain();
	catBrain = cat->getBrain();

	for (int i = 0; i < 10; i++) {
		dogBrain->setIdea(i, "idea");
		catBrain->setIdea(i, "idea");
	}

	std::cout << "Dog brain: " << *dogBrain << std::endl;
	std::cout << "Cat brain: " << *catBrain << std::endl;

	std::cout << "----------------------\nPart 2\n" << std::endl;

	Dog *dog2 = new Dog(*dog);
	Cat *cat2 = new Cat(*cat);

	std::cout << "Dog type: " << *dog2 << ", make sound: ";
	dog2->makeSound();

	std::cout << "Cat type: " << *cat2 << ", make sound: ";
	cat2->makeSound();

	delete dog;
	delete cat;

	std::cout << "Dog brain: " << *dog2->getBrain() << std::endl;
	std::cout << "Cat brain: " << *cat2->getBrain() << std::endl;

	std::cout << "----------------------\nPart 3\n" << std::endl;

	Dog *dog3 = new Dog();
	Cat *cat3 = new Cat();

	*dog3 = *dog2;
	*cat3 = *cat2;

	delete dog2;
	delete cat2;

	std::cout << "Dog type: " << *dog3 << ", make sound: ";
	dog3->makeSound();

	std::cout << "Cat type: " << *cat3 << ", make sound: ";
	cat3->makeSound();

	std::cout << "Dog brain: " << *dog3->getBrain() << std::endl;
	std::cout << "Cat brain: " << *cat3->getBrain() << std::endl;

	delete dog3;
	delete cat3;

	std::cout << "----------------------\nPart 4\n" << std::endl;

	Animal *animals[ARR_N];

	for (int i = 0; i < ARR_N; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < ARR_N; i++) {
		std::cout << "Animal type: " << *animals[i] << ", make sound: ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < ARR_N; i++)
		delete animals[i];

	return (0);
}