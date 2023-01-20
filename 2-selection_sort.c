#include "sort.h"

/**
 * _swap - swap two numbers
 * @a: integer
 * @b: integer
 */
void _swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be printed
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
			_swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
