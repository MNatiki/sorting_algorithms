#include "sort.h"

/**
 * swap_ints - swap an array of integers
 *
 * @a: para
 * @b: para
 */
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * lomuto_partition - partion an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @left: start
 * @right: end
 * Return: mid
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
int *driver, up, down;

driver = array + right;

for (up = down = left; down < right; down++)
{
if (array[down] < *driver)
{
if (up < down)
{
swap_ints(array + down, array + up);
print_array(array, size);
}
up++;
}
}
if (array[up] > *driver)
{
swap_ints(array + up, driver);
print_array(array, size);
}
return (up);
}

/**
 * quick_sort_helper - sort an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @left: start
 * @right: end
 */
void quick_sort_helper(int *array, size_t size, int left, int right)
{
int belong;

if (right - left > 0)
{
belong = lomuto_partition(array, size, left, right);
quick_sort_helper(array, size, left, belong - 1);
quick_sort_helper(array, size, belong + 1, right);
}
}

/**
 * quick_sort - sort an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_helper(array, size, 0, size - 1);
}
