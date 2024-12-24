#include "Zoo.h"
#include "Animal.h"

Zoo::~Zoo()
{
	for (int i = 0; i < animalCount; i++)
	{
		delete animals[i];
	}
}

void Zoo::addAnimal(Animal* animal)
{
	if (animalCount < 10)
	{
		animals[animalCount] = animal;
		animalCount++;
	}
	else cout << "더 이상 추가할 수 없습니다." << endl;
}

void Zoo::performActions()
{
	for (int i = 0; i < animalCount; i++)
	{
		animals[i]->makeSound();
	}
}

int Zoo::GetCount()
{
	return animalCount;
}
