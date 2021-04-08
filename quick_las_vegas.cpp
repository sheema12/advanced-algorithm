// C++ implementation QuickSort using las vegas algorithm
#include <cstdlib>
#include <iostream>
#include<time.h>
using namespace std;
int seperate(int arr[], int low, int high)
{

	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot) {

			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}
int random_part(int arr[], int low, int high)
{

	srand(time(NULL));
	int random = low + rand() % (high - low);
	swap(arr[random], arr[high]);

	return seperate(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = random_part(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void display(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver Code
int main()
{
    printf("Sheema Zainab MI 19MID0014\n");
	int arr[] = { 78,23,11,45,67 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	printf("Sorted array is : \n");
	display(arr, n);
	return 0;
}

