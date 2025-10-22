#include <iostream>
#include <Windows.h>

int fibb(int n, int* memo);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	const int n = 10;
	int memo[n]{};

	std::cout << "Числа Фибоначчи: ";
	for (int i = 0; i < n; ++i)
	{
		std::cout << fibb(i, memo) << " ";
	}

	return 0;

	return EXIT_SUCCESS;
}

int fibb(int n, int* memo)
{
	if (memo[n])
	{
		return memo[n];
	}
	else if (n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		memo[n] = (fibb(n - 1, memo) + fibb(n - 2, memo));
		return memo[n];
	}
}