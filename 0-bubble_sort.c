#include "sort.h"
#include <stdbool.h>
#include <stddef.h>

/**
 * bubble_sort - sorts an array of integers in ascending order
 *               using the Bubble sort algorithm.
 * @array: Pointer to the array of integers to be sorted.
 * @size: size of the array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	bool swap;

	if (array == NULL || size < 2)
		return;

	i = 0;

	while (i < size - 1)
	{
		swap = false;
		j = 0;

		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = true;
				print_array(array, size);
			}
			j++;
		}
		if (!swap)
			break;
		i++;
	}
}
