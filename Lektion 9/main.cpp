#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
using namespace std;

template<typename T> 
void selectionSort(T array[], int size);

template<typename T>
void insertionSort(T array[], int size);

template<typename T>
void sort(T array[], int size);

template<typename T>
void printArray(T array[], int size);

template<typename T>
int linearSearch(T find, T array[], int size);

template<typename T>
int binarySearch(T find, T array[], int size);

int main()
{
	srand((unsigned)time(0));

	const int SIZE = 8;
	int numbers[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		numbers[i] = rand() % 100;
	}

	printArray(numbers, SIZE);
	sort(numbers, SIZE);
	printArray(numbers, SIZE);

	const int NAME_SIZE = 3;
	string names[NAME_SIZE] = { "Bob", "Charles", "Alice" };	
	
	printArray(names, NAME_SIZE);
	sort(names, NAME_SIZE);
	printArray(names, NAME_SIZE);

	system("pause");
	return 0;
}

template<typename T>
void printArray(T array[], int size)
{
	cout << array[0];
	for (int i = 1; i < size; i++)
	{
		cout << ", " << array[i];
	}
	cout << endl;
}

template<typename T>
void selectionSort(T array[], int size)
{
	T temp;
	int minIndex;
	for (int i = 0; i < size; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
	}
}

template<typename T>
void insertionSort(T array[], int size)
{
	T temp;
	int pos;
	for (int i = 1; i < size; i++)
	{
		temp = array[i];
		pos = i;

		while (pos > 0 && temp < array[pos - 1])
		{
			array[pos] = array[pos - 1];
			pos--;
		}

		array[pos] = temp;
	}
}

template<typename T>
void sort(T array[], int size)
{
	T temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - (i+1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

template<typename T>
int linearSearch(T find, T array[], int size)
{
	int index = -1;
	for (int i = 0; i < size && index == -1; i++)
	{
		if (find == array[i])
		{
			index = i;
		}
	}

	return index;
}

template<typename T>
int binarySearch(T find, T array[], int size)
{
	int middle = size / 2;
	int start = 0;
	int end = size - 1;

	while (array[middle] != find && end >= start)
	{
		if (find < array[middle])
		{
			end = middle - 1;
		}
		else
		{
			start = middle + 1;
		}

		middle = (start + end) / 2;
	}

	if (start > end)
	{
		middle = -1;
	}
	return middle;
}