#include <iostream>
#include <Windows.h>

int fibb(int n);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int n = 10;

	std::cout << "Числа Фибоначчи: ";
	for (int i = 0; i < n; ++i)
	{
		std::cout << fibb(i) << " ";
	}

	return 0;

	return EXIT_SUCCESS;
}

int fibb(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		return (fibb(n - 1) + fibb(n - 2));
	}
}