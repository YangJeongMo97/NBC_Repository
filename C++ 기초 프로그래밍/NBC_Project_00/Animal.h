#pragma once
#include <iostream>

using namespace std;

class Animal
{
public:
	Animal();
	~Animal();

	virtual void makeSound() = 0;

protected:
	string bark;
};

