#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	if (a != b)
{
		int temp = *a;
		*a = *b;
		*b = temp;
}
}

/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: The array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 *
 * Return: The index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
	if (array[j] < pivot)
	{
		i++;
		swap(&array[i], &array[j]);
	if (i != j)
		print_array(array, size);
	}
}
	swap(&array[i + 1], &array[high]);
	if ((i + 1) != high)
		print_array(array, size);
		return (i + 1);
}

/**
 * quicksort_rec - Recursively sorts the array using quicksort
 * @array: The array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
void quicksort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
{
		int pi = lomuto_partition(array, low, high, size);

		quicksort_rec(array, low, pi - 1, size);
		quicksort_rec(array, pi + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_rec(array, 0, size - 1, size);
}

