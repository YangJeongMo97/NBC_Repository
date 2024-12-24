#include <iostream>
#include <vector>

using namespace std;

int* InsertNumArray(const int nSize);
void PrintArray(int* nInArray, int nSize);
void SortArray(int* nInArray, int nSize, bool bIsReverse);

int main()
{
	int nArraySize = 5, nType;
	int* nNumArray;

	nNumArray = InsertNumArray(nArraySize);

	PrintArray(nNumArray, nArraySize);
START:
	cout << "1. 오름차순 정렬    2. 내림차순 정렬" << endl;
	cin >> nType;

	switch (nType)
	{
	case 1:
		SortArray(nNumArray, nArraySize, false);
		break;
	case 2:
		SortArray(nNumArray, nArraySize, true);
		break;
	defalt:
		cout << "잘못된 입력값입니다." << endl;
		goto START;
	}

	PrintArray(nNumArray, nArraySize);

	return 0;
}

int* InsertNumArray(const int nSize)
{
	int* nArray = (int*)malloc(nSize * sizeof(int));

	for (int i = 0; i < nSize; i++)
	{
		cout << i + 1 << "번째 숫자를 입력하세요. : ";
		cin >> nArray[i];
	}

	return nArray;
}

void PrintArray(int* nInArray, int nSize)
{
	cout << "[";
	for (int i = 0; i < nSize; i++)
	{
		cout << nInArray[i];
		if (i != nSize - 1) cout << ", ";
	}
	cout << "]" << endl;
}

void SortArray(int* nInArray, int nSize, bool bIsReverse)
{
	int temp, idx, min = INT32_MAX, max = INT32_MIN;
	for (int i = 0; i < nSize; i++)
	{
		for (int j = i + 1; j < nSize; j++)
		{
			if (min > nInArray[j] && !bIsReverse)
			{
				min = nInArray[j];
				idx = j;
			}
			if (max < nInArray[j] && bIsReverse)
			{
				max = nInArray[j];
				idx = j;
			}
		}
		if (min < nInArray[i] && !bIsReverse)
		{
			temp = nInArray[i];
			nInArray[i] = nInArray[idx];
			nInArray[idx] = temp;
		}
		if (max > nInArray[i] && bIsReverse)
		{
			temp = nInArray[i];
			nInArray[i] = nInArray[idx];
			nInArray[idx] = temp;
		}
		min = INT32_MAX;
		max = INT32_MIN;
	}
}
