#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "Zoo.h"
#include "Cat.h"
#include "Cow.h"
#include "Dog.h"

Animal* createRandomAnimal()
{
    Animal* newAnimal;

    switch (rand() % 3)
    {
    case 0:
        newAnimal = new Cat();
        cout << "고양이가 추가되었습니다." << endl;
        break;
    case 1:
        newAnimal = new Cow();
        cout << "소가 추가되었습니다." << endl;
        break;
    case 2:
        newAnimal = new Dog();
        cout << "강아지가 추가되었습니다." << endl;
        break;
    default:
        newAnimal = nullptr;
    }

    return newAnimal;
}

int main()
{
    Zoo* mainZoo = new Zoo();
    int count, maxCount = 10;
    char Input;
    cout << "1. 동물 추가\t2. 동물 불러오기\tAnykey. 종료" << endl;
START:
    Input = _getch();

    system("cls");

    switch (Input - 48)
    {
    case 1:
        cout << "몇 마리를 추가하겠습니까? (최대 " << maxCount - mainZoo->GetCount() << "마리) : ";
        cin >> count;
        if (count > maxCount - mainZoo->GetCount())
        {
            cout << "최대값을 넘었습니다. 초기 화면으로 돌아갑니다." << endl;
            break;
        }
        for(int i = 0; i < count; i++)
            mainZoo->addAnimal(createRandomAnimal());
        break;
    case 2:
        mainZoo->performActions();
        break;
    case 3:
        mainZoo->~Zoo();
        return 0;
    default:
        cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
        break;
    }

    cout << "1. 동물 추가\t2. 동물 불러오기\t3. 종료" << endl;
    goto START;

    return 0;
}