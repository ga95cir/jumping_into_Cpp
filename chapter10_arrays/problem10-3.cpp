/*
Write a program that detects whether an array is
sorted or not, and if it is not sorted, sort it.
*/

#include <iostream>
using namespace std;

void fill_array(int arr[], int size);
void sort_array(int arr[], int size);
int find_min(int arr[], int size);

int main()
{
    int size;
    cin << size << endl;
    int arr[size];
    fill_array(arr, size);
    sort_array(arr, size);
    return 0;
}

void sort_array(int arr[], size)
{

}
