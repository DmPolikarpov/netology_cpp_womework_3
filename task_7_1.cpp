#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int** createArray(int row, int column);
void removeArray(int** arr, int rows);
void dfs(int** arr, int vertNumber);
void dfsn(int** arr, int vertNumber, int currVert, std::vector<int>* visited);

int main()
{
	setlocale(LC_ALL, "Russian");

	int rows{}, columns{}, row{}, column{};

	std::ifstream iText("input.txt");

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

	dfs(arr, columns);

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

void dfs(int** arr, int vertNumber)
{
	std::vector<int> visited;
	for (int i = 0; i < vertNumber; ++i)
	{
		visited.push_back(0);
	}
	std::cout << "Порядок обхода вершин: ";

	for (int i = 0; i < vertNumber; ++i)
	{
		if (visited.at(i) == 0)
		{
			dfsn(arr, vertNumber, i, &visited);
		}
	}
}

void dfsn(int** arr, int vertNumber, int currVert, std::vector<int>* visited)
{
	(*visited).at(currVert) = 1;
	std::cout << " " << currVert+1;
	for (int i = 0; i < vertNumber; ++i)
	{
		if (i == currVert) continue;
		if (arr[currVert][i] == 1 && (*visited).at(i) == 0)
		{
			dfsn(arr, vertNumber, i, visited);
		}
	}
}