/*
Write a program that detects whether an array is
sorted or not, and if it is not sorted, sort it.
(Code follows closely 'insertion_sort.cpp', on
p. 144-145 in book.)
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void sort_array(int arr[], int size);
int findSmallestRemainingElement(int arr[], int size, int index);
void swap(int arr[], int first_index, int second_index);
void displayArray(int arr[], int size);

int main()
{
    int arr[10];
    srand( time( NULL ) );
    for (int i=0; i<10; i++)
    {
        arr[i] = rand() % 100;
    }
    cout << "Original array: ";
    displayArray(arr, 10);
    cout << '\n';

    sort_array(arr, 10);
    cout << "Sorted array: ";
    displayArray(arr, 10);
    cout << '\n';
}


void sort_array(int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        int index = findSmallestRemainingElement(arr, size, i);
        swap(arr, i, index);
    }
}

int findSmallestRemainingElement(int arr[], int size, int index)
{
    int index_of_smallest_value = index;
    for (int i=index+1; i<size; i++)
    {
        if (arr[i]<arr[index_of_smallest_value])
        {
            index_of_smallest_value = i;
        }
    }
    return index_of_smallest_value;
}

void swap(int arr[], int first_index, int second_index)
{
    int temp = arr[first_index];
    arr[first_index] = arr[second_index];
    arr[second_index] = temp;
}

void displayArray(int arr[], int size)
{
    cout << "{";
    for (int i=0; i<size; i++)
    {
        if (i!=0)
        {
            cout << ", ";
        }
        cout << arr[i];
    }
    cout << "}";
}
