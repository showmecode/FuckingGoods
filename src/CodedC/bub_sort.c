#include <stdio.h>

void bub_sort(int *arr, int n)
{
	int i, j;
	int flag = 0;	/*定义一个标志位*/

	for (i = 0; i < n-1; i++)	/*n-1趟排序*/
	{
		for (j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1]) /*若后面元素有比前面小的就交换*/
			{	
				arr[j] = arr[j] + arr[j+1];
			  arr[j+1] = arr[j] - arr[j+1];
				arr[j] = arr[j] - arr[j+1];
			   	  flag = 1;	/*将标志位设置为1，表示交换过*/
			}
		}

		if (flag == 0) /*若没有发生过交换就结束算法*/
		{
			break;
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
	bub_sort(arr, 8);
	print_arr(arr, 8);
}
