#include <iostream>
#include <Windows.h>


void printArray(int* arr, int size);
void printHeap(int* arr, int size);
void printCurrentValue(int* arr, int size, int index, int level);
int getParentIndex(int index);
int getLevel(int index);
void startTravel(int* arr, int size);
int getNewIndex(int* arr, int size, int index, std::string command);
int getLeftChildIndex(int index);
int getRightChildIndex(int index);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);


	const int size{6};
	int arr[size]{ 1, 3, 6, 5, 9, 8 };

	/*const int size{ 8 };
	int arr[size]{ 94, 67, 18, 44, 55, 12, 6, 42 };*/

	/*const int size{ 10 };
	int arr[size]{ 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };*/


	std::cout << "Исходный массив: ";
	printArray(arr, size);

	std::cout << "Пирамида: " << std::endl;
	printHeap(arr, size);

	startTravel(arr, size);

	return EXIT_SUCCESS;
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

void printHeap(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		int level = getLevel(i);
		printCurrentValue(arr, size, i, level);
	}
}

void printCurrentValue(int* arr, int size, int index, int level)
{
	if (index == 0)
	{
		std::cout << index << " root " << arr[index] << std::endl;
	}
	else
	{
		int parentIndex = getParentIndex(index);
		bool isLeft = index % 2 != 0;
		std::string child = isLeft ? " left " : " right ";
		std::cout << level << " " << child << "(" << arr[parentIndex] << ") " << arr[index] << std::endl;
	}
}

int getParentIndex(int index)
{
	return (index - 1) / 2;
}

int getLevel(int index)
{
	int level = 0;
	while (index > 0)
	{
		++level;
		index = getParentIndex(index);
	}
	return level;
}

void startTravel(int* arr, int size)
{
	int index = 0;
	std::string command{};
	do
	{
		int level = getLevel(index);
		std::cout << "Вы находитесь здесь: ";
		printCurrentValue(arr, size, index, level);
		std::cout << "Введите команду: ";
		std::cin >> command;
		index = getNewIndex(arr, size, index, command);
	} while (command != "exit");
}

int getNewIndex(int* arr, int size, int index, std::string command)
{
	if (command == "exit") return index;
	if (command == "up")
	{
		if (index > 0) return getParentIndex(index);

		std::cout << "Ошибка! Отсутствует родитель" << std::endl;
		return index;
	}
	else if (command == "left")
	{
		int newIndex = getLeftChildIndex(index);
		if (newIndex < size) return newIndex;

		std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
		return index;
	}
	else if (command == "right")
	{
		int newIndex = getRightChildIndex(index);
		if (newIndex < size) return newIndex;

		std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
		return index;
	}
	else
	{
		std::cout << "Ошибка! Такой команды нет!" << std::endl;
		return index;
	}
}

int getLeftChildIndex(int index)
{
	return 2 * index + 1;
}

int getRightChildIndex(int index)
{
	return 2 * index + 2;
}