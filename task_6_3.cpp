#include <iostream>
#include <Windows.h>

int find_substring_light_rabin_karp(std::string str1, std::string str2);
int simple_string_hash(std::string input);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::string strToSearchIn{};
	std::string strToLookFor{};

	std::cout << "Введите строку, в которой будет осуществляться поиск: ";
	std::cin >> strToSearchIn;

	do
	{
		std::cout << "Введите подстроку, которую нужно найти: ";
		std::cin >> strToLookFor;
		int res = find_substring_light_rabin_karp(strToSearchIn, strToLookFor);
		if (res == -1)
		{
			std::cout << "Подстрока  " << strToLookFor << " не найдена" << std::endl;
		}
		else
		{
			std::cout << "Подстрока  " << strToLookFor << " найдена по индексу " << res << std::endl;
		}

	} while (strToLookFor != "exit");

	return EXIT_SUCCESS;
}

int find_substring_light_rabin_karp(std::string str1, std::string str2)
{
	int h{};
	int k{ static_cast<int>(str2.size()) };

	int str2_hash = simple_string_hash(str2);

	for (std::string::size_type i = 0; i < str1.size()-k; ++i)
	{
		if (i == 0)
		{
			h = simple_string_hash(str1.substr(0, k));
		}
		else
		{
			h -= static_cast<int>(str1[i-1]);
			h += static_cast<int>(str1[i+k-1]);
		}
		if (h == str2_hash)
		{
			for (std::string::size_type j = 0; j < str2.size(); ++j)
			{
				if (str1[i + j] != str2[j]) continue;
			}
			return i;
		}
	}
	
	return -1;
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