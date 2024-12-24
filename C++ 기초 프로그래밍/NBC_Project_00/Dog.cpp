#include "Dog.h"

Dog::Dog()
{
	bark = "Woof!Woof!";
}

void Dog::makeSound()
{
	cout << "강아지가 짖습니다. " << bark << endl;
}
