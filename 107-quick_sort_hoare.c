#include "sort.h"

/**
 * _swap - swaps two values in an array
 * @array: array to sort
 * @i: first value
 * @j: second value
 *
 * Return: Nothing
 */
void _swap(int *array, int i, int j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/**
 * partition - sorts a partition of data in relation to pivot
 * @array: array to sort
 * @min: left elements
 * @max: right elements
 * @size: size of array
 *
 * Return: New pivot
 */
int partition(int *array, int min, int max, size_t size)
{
	int i, j, pivot = array[max];

	for (i = min, j = max; 1; i++, j--)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i >= j)
			return (i);
		_swap(array, i, j);
		print_array(array, size);
	}
}

/**
 * quicksort - sorts data in ascending order using the quick
 * sort algorithm
 * @array: array to sort
 * @min: left elements
 * @max: right elements
 * @size: size of array
 *
 * Return: Nothing
 */
void quicksort(int *array, int min, int max, size_t size)
{
	int p;

	if (min < max)
	{
		p = partition(array, min, max, size);
		quicksort(array, min, p - 1, size);
		quicksort(array, p, max, size);
	}
}

/**
 * quick_sort_hoare - sorts data in ascending order using the quick
 * sort algorithm Hoare partition scheme
 * @array: array of data to sort
 * @size: size of array
 *
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
