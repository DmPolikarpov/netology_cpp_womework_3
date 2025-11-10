#include <iostream>
#include <Windows.h>

int simple_string_hash(std::string input);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);


	std::string userInput{};
	do
	{
		std::cout << "Введите строку: ";
		std::cin >> userInput;
		std::cout << "Наивный хэш строки " << userInput << " = " << simple_string_hash(userInput) << std::endl;
	} while (userInput != "exit");

	return EXIT_SUCCESS;
}

int simple_string_hash(std::string input)
{
	int result{0};
	for (std::string::iterator it = input.begin(); it != input.end(); ++it)
	{
		result += static_cast<int>(*it);
	}
	return result;
}