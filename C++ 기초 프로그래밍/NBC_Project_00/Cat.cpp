#include "Cat.h"

Cat::Cat()
{
	bark = "Meow~!";
}

void Cat::makeSound()
{
	cout << "고양이가 울고있습니다. " << bark << endl;
}
