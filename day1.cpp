#include <iostream>
using namespace std;
void swap(int arr[], int pos1, int pos2) {
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot) {
	int i = low;
	int j = low;
	while (i <= high) {
		if (arr[i] > pivot) {
			i++;
		}
		else {
			swap(arr, i, j);
			i++;
			j++;
		}
	}
	return j - 1;
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[high];
		int pos = partition(arr, low, high, pivot);

		quickSort(arr, low, pos - 1);
		quickSort(arr, pos + 1, high);
	}
}
int abs(int a, int b)
{
	if (a >= b)
	{
		return a - b;
	}
	if (b > a)
	{
		return b - a;
	}
}
int main()
{
	int a[1000];
	int b[1000];
	for (int i = 0; i < 1000; i++)
	{
		cin >> a[i] >> b[i];
	}
	quickSort(a, 0, 999);
	quickSort(b, 0, 999);
	int sum = 0;
	// part 1:
	/*for (int i = 0; i < 1000; i++)
	{
		int diff = abs(a[i], b[i]);
		sum += diff;
	}
	cout << sum;*/
	int index = 0;
	for (int i = 0; i < 1000; i++)
	{
		int counter = 0;
		for (int j = index; j < 1000; j++)
		{
			if (a[j] == b[i])
			{
				counter++;
				index = j;
			}
		}
		sum = sum + counter * b[i];
	}
	cout << sum;
	
}