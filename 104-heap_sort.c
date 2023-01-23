#include "sort.h"

/**
 * _swap - swapped two values.
 * @array: the array for swapping values
 * @i: first index
 * @j: second index
 * @r_size: the size constant for printing
 *
 * Return: Nothing
 */
void _swap(int *array, int i, int j, const int r_size)
{
	int tmp;
	(void) r_size;

	if (i != j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, (size_t)r_size);
	}
}

/**
 * _largest - Find the largest number between the layers
 * @array: the array for sort
 * @size: the size for main element
 * @i: the largest.
 * @r_size: the size for print in swap
 *
 * Return: Nothing
 */
void _largest(int *array, size_t size, int i, const int r_size)
{
	int largest = i;
	int lft = (2 * i) + 1;
	int rgt = (2 * 1) + 2;

	if (lft < (int)size && array[lft] > array[largest])
		largest = lft;

	if (rgt < (int)size && array[rgt] > array[largest])
		largest = rgt;
	if (largest != i)
	{
		_swap(array, i, largest, r_size);
		_largest(array, size, largest, r_size);
	}
}

/**
 * heap_sort - call largest while layers exist
 * @array: the array that generate the layers
 * @size: size of the array
 *
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	const int r_size = (const int)size;
	int i;

	if (size < 2 || !array)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		_largest(array, size, i, r_size);

	for (i = size - 1; i >= 0; i--)
	{
		_swap(array, 0, i, r_size);
		_largest(array, i, 0, r_size);
	}
}
