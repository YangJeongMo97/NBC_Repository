#pragma once
#include <iostream>

using namespace std;
class Zoo
{
public:
	~Zoo();

	void addAnimal(class Animal* animal);
	void performActions();
	int GetCount();

private:
	class Animal* animals[10];
	int animalCount = 0;
};

