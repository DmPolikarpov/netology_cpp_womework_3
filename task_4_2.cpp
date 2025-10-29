#include <iostream>
#include <Windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size);
int* appendItemToArray(int* dymamicArray, int itemToAdd, int* logicalSize, int* actualSize);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int actualSize{};
	int logicalSize{};
	int itemToAdd{};

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
	std::cout << std::endl;

	std::cout << "¬ведите 0, чтобы выйти из программы!" << std::endl;

	do
	{
		std::cout << "¬ведите элемент дл€ добавлени€: ";
		std::cin >> itemToAdd;
		if (itemToAdd != 0)
		{
			dymamicArray = appendItemToArray(dymamicArray, itemToAdd, &logicalSize, &actualSize);
			print_dynamic_array(dymamicArray, logicalSize, actualSize);
			std::cout << std::endl;
		}
	} while (itemToAdd != 0);


	delete[] dymamicArray;

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

int* appendItemToArray(int* dymamicArray, int itemToAdd, int* logicalSize, int* actualSize)
{
	if (*logicalSize == *actualSize)
	{
		*actualSize *= 2;
		*logicalSize += 1;
		int* newArr = new int[*actualSize] {};
		for (int i = 0; i < *logicalSize - 1; ++i)
		{
			newArr[i] = dymamicArray[i];
		}
		newArr[*logicalSize - 1] = itemToAdd;
		return newArr;
	}
	else
	{
		dymamicArray[*logicalSize] = itemToAdd;
		*logicalSize += 1;
		return dymamicArray;
	}
}