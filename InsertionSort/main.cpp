#include <iostream>
#include <string>
using namespace std;

/*
Patr�n�jamies k�rtot un mekl�t priek� eks�mena!
*/

void insertionSort(int* arr, int length);
int takeNextFromUnsorted(int* arr, int sortedUpTo);
void moveEverythingByOne(int* arr, int from, int to);
void printArr(int* arr, int length);

int main()
{
	const int arrLen = 10;
	int arr[arrLen] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	insertionSort(arr, arrLen);
	printArr(arr, arrLen);

	char readKey;
	cin >> readKey;
}

void printArr(int* arr, int length) {
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insertionSort(int* arr, int length)
{
	// K�rt�jo nesak�rtot�s da�as elementu iesprau�am pareizaj� viet�
	// pie�emam, ka pirmais ir jau sak�rtots
	int sortedUpTo = 1; // neieskaitot


	while (sortedUpTo != length)
	{
		int nextUnsorted = takeNextFromUnsorted(arr, sortedUpTo);
		// tagad jaatrod �st� vieta m�su nextUnsorted no 0 l�dz sortedUpTo
		int targetPos = -1;
		sortedUpTo++;

		for (int i = 0; i < sortedUpTo; i++) {
			if (nextUnsorted > arr[i])
				continue;
			else {
				targetPos = i;
				break;
			}
		}

		moveEverythingByOne(arr, targetPos, sortedUpTo - 1);
		arr[targetPos] = nextUnsorted;
	}
}

int takeNextFromUnsorted(int* arr, int sortedUpTo)
{
	return arr[sortedUpTo];
}

void moveEverythingByOne(int* arr, int from, int to)
{
	while (from < to) {
		arr[to] = arr[to - 1];
		to--;
	}
}