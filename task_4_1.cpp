#include <iostream>
#include <Windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int actualSize{};
	int logicalSize{};

	std::cout << "¬ведите фактичеcкий размер массива: ";
	std::cin >> actualSize;

	std::cout << "¬ведите логический размер массива: ";
	std::cin >> logicalSize;

	if (logicalSize > actualSize)
	{
		std::cout << "ќшибка! Ћогический размер массива не может превышать фактический!" << std::endl;
		return 0;
	}

	int* dymamicArray = new int[actualSize] {};

	for (int i = 0; i < actualSize; ++i)
	{
		if (i < logicalSize)
		{
			std::cout << "¬ведите arr[" << i << "]: ";
			std::cin >> dymamicArray[i];
		}
	}

	print_dynamic_array(dymamicArray, logicalSize, actualSize);

	delete [] dymamicArray;

	return EXIT_SUCCESS;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	std::cout << "ƒинамический массив: ";

	for (int i = 0; i < actual_size; ++i)
	{
		if (i < logical_size)
		{
			std::cout << arr[i] << " ";
		}
		else
		{
			std::cout << "_ ";
		}
	}
}