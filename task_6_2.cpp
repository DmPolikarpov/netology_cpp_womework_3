#include <iostream>
#include <Windows.h>
#include <cmath>

int real_string_hash(std::string input, int p, int n);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int p{ 0 };
	int n{ 0 };
	std::string userInput{};

	std::cout << "Введите p: ";
	std::cin >> p;

	std::cout << "Введите n: ";
	std::cin >> n;

	do
	{
		std::cout << "Введите строку: ";
		std::cin >> userInput;
		std::cout << "хэш строки " << userInput << " = " << real_string_hash(userInput, p, n) << std::endl;
	} while (userInput != "exit");

	return EXIT_SUCCESS;
}

int real_string_hash(std::string input, int p, int n)
{
	long long result{ 0 };
	for (std::string::size_type i = 0; i < input.size(); ++i)
	{
		result += static_cast<int>(input[i]) * pow(p, i);
	}
	return result % n;
}