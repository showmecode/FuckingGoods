#include "stdio.h"
void sel_sort(int *arr, int len) 
{
	int i, j, k;

	for (i = 0; i < len-1; i++) /*外层len-1趟比较*/
	{
		k = i; /*设置标志位*/
		for (j = i +1; j < len; j++)
		{
			if (arr[k] > arr[j]) /*发现前面大于后面元素，改变标志位*/ 
				k = j;
		}

		if (k != i) /*如果标志位改变过 ，交换*/
		{
			arr[k] = arr[i] + arr[k];
			arr[i] = arr[k] - arr[i];
			arr[k] = arr[k] - arr[i];
		}
	}

	return ;
}

print_arr(int *arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void)
{
	int arr[8] = {2, 78, 90, 23, 10, 26, 99, 1};
	print_arr(arr, 8);
	sel_sort(arr, 8);
	print_arr(arr, 8);
}
