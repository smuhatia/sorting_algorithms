#include "sort.h"

/**
* bubble_sort - a function that sorts an array of integers using bubble sort
* @array: the array to be sorted
* @size: the size of the array
* Return: 0 on success and 1 on failure
*/
void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int tmp;
	int swapped;

	if (size < 2 || array == NULL)
	{
		return;
	}
	/*loop through to get the elements*/
	for (a = 0; a < size - 1; a++)
	{
		swapped = 0;
		/* loop to compare*/
		for (b = 0; b < size - a - 1 ; b++)
		{
			/* if the 1st index is greater than the second swap*/
			if (array[b] > array[b + 1])
			{
				tmp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = tmp;
				swapped = 1;
				print_array(array, size);/* print after each swap*/
			}
		}
		if (swapped == 0)
		{
			return;
		}
	}
}
