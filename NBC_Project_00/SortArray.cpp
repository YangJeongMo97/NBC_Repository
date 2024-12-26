#include <iostream>
#include <vector>

using namespace std;

int SumArray(int* InArray, const int nSize);
double AverageArray(int InSum, const int nSize);
int* InsertNumArray(const int nSize);
void PrintArray(int* nInArray, const int nSize);
void SortArray(int* nInArray, const int nSize, bool bIsReverse);

int main()
{
	int nArraySize, nType;
	int* nNumArray;

	cout << "�迭�� ũ�⸦ �Է��ϼ���. : " ;
	cin >> nArraySize;

	nNumArray = InsertNumArray(nArraySize);

	PrintArray(nNumArray, nArraySize);
START:
	cout << "1. ��\t2. ��հ�\t3. �������� ����\t4. �������� ����" << endl;
	cin >> nType;

	switch (nType)
	{
	case 1:
		cout << "Result = " << SumArray(nNumArray, nArraySize) << endl;
		break;
	case 2:
		cout << "Result = " << AverageArray(SumArray(nNumArray, nArraySize), nArraySize) << endl;
		break;
	case 3:
		SortArray(nNumArray, nArraySize, false);
		PrintArray(nNumArray, nArraySize);
		break;
	case 4:
		SortArray(nNumArray, nArraySize, true);
		PrintArray(nNumArray, nArraySize);
		break;
	default:
		cout << "�߸��� �Է°��Դϴ�. ���α׷��� �����մϴ�." << endl;
		return 0;
	}

	goto START;

	return 0;
}

int SumArray(int* InArray, const int nSize)
{
	int result = 0;

	for (int i = 0; i < nSize; i++)
	{
		result += InArray[i];
	}

	return result;
}

double AverageArray(int InSum, const int nSize)
{
	return (double)InSum / (double)nSize;
}

int* InsertNumArray(const int nSize)
{
	int* nArray = (int*)malloc(nSize * sizeof(int));

	for (int i = 0; i < nSize; i++)
	{
		cout << i + 1 << "��° ���ڸ� �Է��ϼ���. : ";
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
