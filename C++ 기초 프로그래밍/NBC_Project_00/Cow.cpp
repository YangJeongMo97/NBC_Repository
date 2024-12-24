#include "Cow.h"

Cow::Cow()
{
	bark = "Moooooooo~~";
}

void Cow::makeSound()
{
	cout << "소가 울음소리를 냅니다." << bark << endl;
}
