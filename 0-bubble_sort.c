#include "sort.h"

/**
 * swap - swaps two integers positions in as array.
 * @x: First integer
 * @y: Second integer
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 *               using the Bubble sort algorithm.
 * @array: Pointer to the array of integers to be sorted.
 * @size: size of the array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t n, newn, i;

	if (array == NULL || size < 2)
		return;

	n = size;
	do {
		newn = 0;
		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap(&array[i - 1], &array[i]);
				print_array(array, size);
				newn = i;
			}
		}
		n = newn;
	} while (n > 1);
}
