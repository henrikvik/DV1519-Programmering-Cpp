#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "ArrayStack.h"

void info(int nr);
int faculty(int i);

template<typename T>
int partition(T data[], int start, int end);

template<typename T>
void quickSort(T data[], int start, int end);

template<typename T>
void selectionSort(T data[], int size);

int main()
{
#pragma region Stack


	IStack<int> * stack = new ArrayStack<int>();

	stack->push(5); // 5 <-
	stack->push(7); // 5 7 <-
	stack->push(2); // 5 7 2 <-
	stack->push(8); // 5 7 2 8 <-
	stack->push(1); // 5 7 2 8 1 <-

	std::cout << "Expecting false: " << (stack->isEmpty() ? "true" : "false") << std::endl;
	std::cout << "Expecting 1: " << stack->peek() << std::endl;
	std::cout << "Expecting 1: " << stack->pop() << std::endl;
	std::cout << "Expecting 8: " << stack->pop() << std::endl;
	std::cout << "Expecting 2: " << stack->pop() << std::endl;
	std::cout << "Expecting 7: " << stack->pop() << std::endl;
	std::cout << "Expecting 5: " << stack->peek() << std::endl;
	std::cout << "Expecting 5: " << stack->pop() << std::endl;
	std::cout << "Expecting true: " << (stack->isEmpty() ? "true" : "false") << std::endl;

	info(5);
	std::cout << "5! = " << faculty(5) << std::endl;
	std::cout << "4! = " << faculty(4) << std::endl;
	std::cout << "3! = " << faculty(3) << std::endl;

	std::cout << "----===##===----" << std::endl;
#pragma endregion
	srand(time(0));

	const size_t SIZE = 20000;
	int numbers[SIZE];
	int numbers2[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		numbers[i] = rand() % 100 + 1;
		numbers2[i] = numbers[i];
		//std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	clock_t start1 = std::clock();
	quickSort(numbers, 0, SIZE - 1);
	clock_t end1 = std::clock();
	std::cout << "QuickSort took " << end1 - start1 << "." << std::endl;

	clock_t start2 = std::clock();
	selectionSort(numbers2, SIZE);
	clock_t end2 = std::clock();
	std::cout << "SelectionSort took " << end2 - start2 << "." << std::endl;

	std::cout << "QickSort was " 
		<< float(end2 - start2) / float(end1 - start1) 
		<< " times faster than SelectionSort." << std::endl;

	std::cout << std::endl;

	
	system("pause");
	return 0;
}


void info(int nr)
{
	if (nr > 0)
	{
		std::cout << "Nr is: " << nr << std::endl;
		info(nr - 1); // ->
	}

	std::cout << "Info() done Nr: " << nr << std::endl;
}

int faculty(int i)
{
	if (i > 1)
	{
		return i * faculty(i - 1);
	}

	return i;
}

template<typename T>
int partition(T data[], int start, int end)
{
	T pivotValue = data[start];
	int pivotPosition = start;

	for (int i = start + 1; i <= end; i++)
	{
		if (data[i] < pivotValue)
		{
			std::swap(data[i], data[pivotPosition + 1]);
			std::swap(data[pivotPosition], data[pivotPosition + 1]);
			pivotPosition++;
		}
	}

	return pivotPosition;
}

template<typename T>
void quickSort(T data[], int start, int end)
{
	if (start < end)
	{
		int pivot = partition(data, start, end);
		quickSort(data, start, pivot - 1);
		quickSort(data, pivot + 1, end);
	}
}

template<typename T>
void selectionSort(T data[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		int minIndex = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (data[j] < data[minIndex])
			{
				minIndex = j;
			}
		}

		std::swap(data[i], data[minIndex]);
	}
}