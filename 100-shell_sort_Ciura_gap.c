#include "sort.h"
#include <stddef.h>

/**
 * shell_sort_Ciura - sorts an array of integers in ascending order using
 *              the Shell sort algorithm using the Ciura gap sequence
 * @array: the array to sort
 * @size: the size of the array
 **/
void shell_sort_Ciura(int *array, size_t size)
{
	/* Define Ciura gap sequence */
	size_t gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
	size_t i, j, k, gap;
	int temp;

	/* Check for NULL or empty arrays */
	if (array == NULL || size < 2)
		return;
	/* Start with the largest gap and work down to a gap of 1 */
	for (k = 0; k < sizeof(gaps) / sizeof(gaps[0]); k++)
	{
		gap = gaps[k];
		/* Do a gapped insertion sort for every elements in gaps */
		/* Each loop leaves a[0..gap-1] in gapped order */
		for (i = gap; i < size; i++)
		{
			/* save a[i] in temp and make a hole at position i */
			temp = array[i];
			/*shift earlier gap-sorted elements up until the correct location*/
			/* for a[i] is found */
			for (j = i; (j >= gap) && (array[j - gap] > temp); j -= gap)
			{
				array[j] = array[j - gap];
			}
			print_array(array, size);
			/* put temp (the original a[i]) in its correct location */
			array[j] = temp;
		}
	}
}
