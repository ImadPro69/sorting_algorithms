#include "sort.h"

/**
 * quick_sort - Sorts an array of Integers in ascending
 * order using the Quick sort Algorithm
 * @array: array with elements
 * @size: size of Array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	rec_func(array, 0, size, size);
}

/**
 * rec_func - Creates multiple recursions to Send to lomuto_partition
 * @array: array with elements
 * @start: index of the first Element
 * @end: index Of the last element
 * @size: size of array
 *
 * Return: Nothing
 */
void rec_func(int *array, int start, int end, size_t size)
{
	int index = 0;

	if (end - start <= 1)
		return;
	index = lomuto_partition(array, start, end, size);

	if (index > start)
		rec_func(array, start, index, size);

	rec_func(array, index + 1, end, size);
}

/**
 * lomuto_partition - Swap array elements
 * @array: array with elements
 * @start: index of the first element
 * @end: index of the last element
 * @size: size of array
 *
 * Return: Nothing
 */
size_t lomuto_partition(int *array, int start, int end, size_t size)
{
	int i = start, j = 0, tmp = 0, index_part = 0, save = 0;
	int pivote = array[end - 1], flag = 0;

	for (i = start; i < end; i++)
	{
		if (array[i] > pivote)
		{
			for (j = i + 1; j < end; j++)
			{
				if (j == end - 1)
				{
					flag = -1;
					save = i;
				}
				if (array[j] <= pivote)
				{
					tmp = array[j];
					array[j] = array[i];
					array[i] = tmp;
					break;
				}
			}
			print_array(array, size);
			if (flag == -1)
				break;
		}
	}
	if (flag == 0)
		return (end - 1);
	index_part = save;
	i = start;
	return (index_part);
}
