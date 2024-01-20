#include "sort.h"
#include <stdio.h>

void quicksort_lomuto(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition scheme)
 *
 * @array: Array of integers to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_lomuto(array, 0, size - 1, size);
}

/**
 * quicksort_lomuto - Recursive function for Quick
 * sort (Lomuto partition)
 *
 * @array: Array of integers to be sorted
 * @low: Low index of the partition
 * @high: High index of the partition
 * @size: Size of the array
 */
void quicksort_lomuto(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_idx = lomuto_partition(array, low, high, size);

		quicksort_lomuto(array, low, pivot_idx - 1, size);
		quicksort_lomuto(array, pivot_idx + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 *
 * @array: Array of integers to be partitioned
 * @low: Low index of the partition
 * @high: High index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);

	return (i + 1);
}
