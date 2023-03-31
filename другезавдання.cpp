#include<iostream>
using namespace std;

void inputMatrix(double** arr, int size);
double findMin(double** arr, int size, int i);
void findMax(double* arr, int size);
void outputMatrix(double** arr, int size);

int main()
{
	int size, min, max = 0;
	cin >> size;
	double** array = new double* [size];
	for (int i = 0; i < size; i++)
	{
		array[i] = new double[size];
	}
	inputMatrix(array, size);
	double* temp = new double[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = 0;
	}
	cout << "\n\n";
	outputMatrix(array, size);
	for (int i = 0; i < size; i++)
	{
		if (array[i][i] < 0)
		{
			temp[i] = findMin(array, size, i);
		}
	}
	cout << "\n\n";
	findMax(temp, size);
}
void inputMatrix(double** arr, int size)
{
	cout << "Enter matrix: ";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> arr[i][j];
		}
	}
}
double findMin(double** arr, int size, int i)
{
	double min = arr[i][0];
	for (int j = 0; j < size; j++)
	{
		if (min > arr[i][j])
		{
			min = arr[i][j];
		}
	}
	return min;
}
void findMax(double* arr, int size)
{
	double max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (max == 0)
		{
			max = arr[i];
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (max < arr[i] && arr[i] != 0)
		{
			max = arr[i];
		}
	}
	cout << "Max number among minimal: " << max << endl;
}
void outputMatrix(double** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}cout << endl;
	}
}
