#include "sort.h"

void counting_sort(int *array, size_t size)
{
	int i, k, *count_array, *array_b, val, d;

	if (array == NULL || size < 2)
		return;
	k = array[0];

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > k)
		{
			k = array[i];
		}
	}
	count_array = malloc((k + 1) *  sizeof(int));

	for (i = 0; i < k + 1; i++)
	{
		count_array[i] = 0;
	}

	for (i = 0; i < (int)size; i++)
	{
		int  value = array[i];
		count_array[value] += 1;
	}
	for (i = 1; i < k + 1; i++)
	{
		count_array[i] = count_array[i] + count_array[i - 1];
	}
	print_array(count_array, k+1);

	array_b = malloc( size * sizeof(int));

	if (array_b == NULL)
		return;
	for (i = (int)size - 1; i >= 0; i--)
	{
		d = array[i];
		val = count_array[d] - 1;
		array_b[val] = array[i];
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = array_b[i];
	}
	free(array_b);
	free(count_array);
}
