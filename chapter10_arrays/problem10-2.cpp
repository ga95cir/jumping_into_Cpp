/*
Problem 10-2: Write a program that takes in 50 values
and prints out the highest, the lowest, the average and
then all 50 input values, one per line.
*/

#include <iostream>
using namespace std;

void enter_array(int arr[], int size);
int find_max(int arr[], int size);
int find_min(int arr[], int size);
float find_average(int arr[], int size);
void display_array(int arr[], int size);


// Note that this program currently only works for integer input values
int main()
{
	int size = 50;
	int arr[size];
	enter_array(arr, size);
	int max = find_max(arr, size);
	int min = find_min(arr, size);
	float average = find_average(arr, size);

	cout << "Maximum: " << max << endl;
	cout << "Minimum: " << min << endl;
	cout << "Average: " << average << endl;

	display_array(arr, size);

	return 0;
}




void enter_array(int arr[], int size)
{
	for (int i=0; i<size; i++)
	{
		cout << "Enter value " << i << ": ";
		cin >> arr[i];
	}
}

int find_max(int arr[], int size)
{
	int max = arr[0];
	for (int i=1; i<size; i++)
	{
		if (max<arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

int find_min(int arr[], int size)
{
	int min = arr[0];
	for (int i=1; i<size; i++)
	{
		if (min>arr[i])
		{
			min = arr[i];
		}
	}
	return min;
}

float find_average(int arr[], int size)
{
	float sum = arr[0];
	float average;
	for (int i=1; i<size; i++)
	{
		sum += arr[i];
	}
	average = sum / size;
	return average;
}

void display_array(int arr[], int size)
{
	for (int i=0; i<size; i++)
	{
		cout << "Index " << i << ": " << arr[i] << endl;
	}
}
