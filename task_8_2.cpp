#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int** createArray(int row, int column);
void removeArray(int** arr, int rows);
void topologicalSort(int** arr, int rows, int columns);
void dfs(int** arr, int rows, int columns, std::vector<int>* visited, std::vector<int>* order, int i);

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

	topologicalSort(arr, rows, columns);

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

void topologicalSort(int** arr, int rows, int columns)
{
	std::vector<int> order;
	std::vector<int> visited;
	for (int i{}; i < rows; ++i)
	{
		visited.push_back(0);
	};
	for (int i{}; i < rows; ++i)
	{
		if (visited.at(i) == 0)
		{
			dfs(arr, rows, columns, &visited, &order, i);
		}
	}
	std::cout << "Топологический порядок вершин: ";
	for (int i{}; i < rows; ++i)
	{
		std::cout << order.at(i) << "  ";
	};
}

void dfs(int** arr, int rows, int columns, std::vector<int>* visited, std::vector<int>* order, int i)
{
	(*visited).at(i) = 1;
	for (int v{}; v < columns; ++v)
	{
		if (v == i) continue;
		if (arr[i][v] == 1 && (*visited).at(v) == 0)
		{
			dfs(arr, rows, columns, visited, order, v);
		}
	}
	(*order).insert((*order).begin(), i + 1);
}
