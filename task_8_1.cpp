#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int** createArray(int row, int column);
void removeArray(int** arr, int rows);
void printGraph(int** arr, int rows, int columns);

int main()
{
	setlocale(LC_ALL, "Russian");

	int rows{}, columns{}, row{}, column{};

	std::ifstream iText("input1.txt");

	iText >> rows;
	columns = rows;

	int** arr = createArray(rows, columns);

	if (iText.is_open())
	{
		std::string data{};

		while (iText >> data)
		{
			if (column == columns)
			{
				row++;
				column = 0;
			}

			arr[row][column] = std::stoi(data);
			column++;
		}

	}
	else
	{
		std::cout << "some error happened!" << std::endl;
	}

	iText.close();

	printGraph(arr, rows, columns);

	removeArray(arr, rows);

	return EXIT_SUCCESS;
}

int** createArray(int row, int column)
{
	int** arr = new int* [row] {};

	for (int index{}; index < row; index++)
	{
		arr[index] = new int[column] {};
	}
	return arr;
}

void removeArray(int** arr, int rows)
{
	for (int row{}; row < rows; row++)
	{
		delete[] arr[row];
	}
	delete[] arr;
}

void printGraph(int** arr, int rows, int columns)
{
	std::cout << "Текстовый вид орграфа: " << std::endl;
	for (int row{}; row < rows; row++)
	{
		std::cout << row + 1 << ": ";
		bool isLinksExist = false;
		for (int column{ }; column < columns; column++)
		{
			if (arr[row][column] == 1)
			{
				std::cout << column + 1 << "  ";
				isLinksExist = true;
			}
		}
		if (!isLinksExist)
		{
			std::cout << "нет";
		}
		std::cout << std::endl;
	}
}
