#include <iostream>
#include <Windows.h>
#include <vector>

void merge_sort(std::vector<int>* arr, int size);
std::vector<int> merge(std::vector<int> arr, std::vector<int> arr2, int size1, int size2);
void printArray(int* arr, int size);
std::vector<int> convertToVector(int* arr, int size);
void applyToArray(std::vector<int> vect, int* arr, int size);

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	
	/*const int size{10};
	int arr[size]{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };*/
	
	
	/*const int size{15};
	int arr[size]{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25 ,74 };*/
	
	const int size{ 18 };
	int arr[size]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

	std::cout << "Исходный массив: ";
	printArray(arr, size);

	std::vector<int> tempVect = convertToVector(arr, size);

	merge_sort(&tempVect, size);

	applyToArray(tempVect, arr, size);

	std::cout << "Отсортированный массив: ";
	printArray(arr, size);

	return EXIT_SUCCESS;
}

void merge_sort(std::vector<int>* arr, int size)
{
	if (size != 1)
	{
		int a = static_cast<int>(size / 2);
		int b = size - a;
		std::vector<int> tempVect;
		std::vector<int> tempVect1;
		for (int i = 0; i < a; ++i)
		{
			tempVect.push_back((*arr).at(i));
		}
		for (int i = a; i < size; ++i)
		{
			tempVect1.push_back((*arr).at(i));
		}
		merge_sort(&tempVect, a);
		merge_sort(&tempVect1, b);
		std::vector<int> mergedArr = merge(tempVect, tempVect1, a, b);

		for (int i = 0; i < size; ++i)
		{
			(*arr).at(i) = mergedArr.at(i);
		}
	}
}

std::vector<int> convertToVector(int* arr, int size)
{
	std::vector<int> resVector;
	for (int i = 0; i < size; ++i)
	{
		resVector.push_back(arr[i]);
	}

	return resVector;
}

void applyToArray(std::vector<int> vect, int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = vect.at(i);
	}
}

std::vector<int> merge(std::vector<int> arr, std::vector<int> arr2, int size1, int size2)
{
	int a = 0, b = 0;
	std::vector<int> vectorRes;

	while ((a < size1) || (b < size2))
	{
		if (a == size1) {
			vectorRes.push_back(arr2.at(b));
			b++;
		}
		else if (b == size2) {
			vectorRes.push_back(arr.at(a));
			a++;
		}
		else if (arr.at(a) <= arr2.at(b)) {
			vectorRes.push_back(arr.at(a));
			a++;
		}
		else {
			vectorRes.push_back(arr2.at(b));
			b++;
		}
	}

	return vectorRes;
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}