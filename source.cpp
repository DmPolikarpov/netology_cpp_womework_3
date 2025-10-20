#include <iostream>
#include <Windows.h>

int getBiggerNumbers(int* numbers, int size, int number);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int numbersArray[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int number{};

	std::cout << "Введите число: ";
	std::cin >> number;

	int biggerNumbers{ getBiggerNumbers(numbersArray, 9, number) };

	std::cout << "Количество элементов в массиве больших, чем " << number << ": " << biggerNumbers << std::endl;

	return EXIT_SUCCESS;
}

int getBiggerNumbers(int* numbers, int size, int number)
{
	int left = 0;
	int right = size - 1;

	if (numbers[0] > number)
	{
		return size;
	}
	else if (numbers[right] < number)
	{
		return 0;
	}

	while (left < right)
	{
		int middle = (left + right) / 2;

		if (numbers[middle] > number)
		{
			right = middle;
		}
		else if (numbers[middle] <= number)
		{
			left = middle + 1;
		}
	}

	return size - left;
}