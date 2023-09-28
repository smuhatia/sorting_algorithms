#include "sort.h"

/**
* selection_sort - a function that sorts an array of integers
* in ascending order using the Selection sort algorithm
* @array: the array to be sorted
* @size: size of the array to be sorted
* Return: nothing
*/

void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min;

	if (size < 2 || array == NULL)
		return;
	/*loop through the elements of the array*/
	for (i = 0; i < size - 1; i++)
	{
		/* set the element at index 0 to be the min value*/
		min = i;
		/*loop through to compare it to the other elements*/
		for (j = i + 1; j < size; j++)
		{
			/*if the min is > the unsorted value, swap*/
			if (array[min] > array[j])
			{
				/*if current min is > than the value, then the value is the new min*/
				min = j;
			}
		}
		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);

		}
	}
}

/**
* swap - swaps two elements of an array
* @a: first element
* @b: second element
*
* Return: nothing
*/

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
