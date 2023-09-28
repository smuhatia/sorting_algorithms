#include "sort.h"

/**
 * shell_sort -sorts an array of integers in ascending order
 * using the shell sort algortithm, the knuth sequence
 * @array: array to be used
 * @size: size of the array
 *
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t gap;
	size_t i;
	size_t j;
	int temp;

	gap = 1;

	if (size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j > gap - 1 && array[j - gap] >= temp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}

