#include "sort.h"

/**
 * quick_sort - sorts an array of int using quick sort
 * with lomutu partition scheme
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	size_t start = 0;
	size_t end = size - 1;

	if (array == NULL || size < 2)
		return;

	recursive_sort(array, start, end, size);
}

/**
 * partition - partitions the array
 * @low: the start of the array
 * @high: the end of the array
 * @array: array to be used
 * @size: size of the array
 * Return: current position of the pivot
 */

int partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t a = low;
	size_t c;

	for (c = low; c <= high - 1; c++)
	{
		if (array[c] < pivot)
		{
			if (a != c)
			{
				swap(&array[a], &array[c]);
				print_array(array, size);
			}
			a++;
		}
	}

	if (pivot != array[a])
	{
		swap(&array[a], &array[high]);
		print_array(array, size);
	}
	return (a);
}

/**
 * recursive_sort - recursively sorts an array
 * @array: the array
 * @low: the first element
 * @high: the last element
 * @size: size of the array
 * Return: nothing
 */

void recursive_sort(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		if (pivot > 0 && pivot > low)
			recursive_sort(array, low, pivot - 1, size);
		if (pivot < high)
			recursive_sort(array, pivot + 1, high, size);
	}
}

/**
 * swap - swaps two elements in an array
 * @a: first element
 * @b: second element
 * Return: nothing
 */

void swap (int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
