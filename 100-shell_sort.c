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
 * shell_sort - sorts an array of integers in ascending order using
 *              the Shell sort algorithm using the Knuth sequence
 * @array: the array to sort
 * @size: the size of the array
 **/
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 0;

	if (array == NULL || size < 2)
		return;
	/* Calculate gap using Knuth sequence */
	while (gap < (size / 3))
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(&array[j], &array[j - gap]);
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
