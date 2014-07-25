#include <stdio.h>

/*快速排序法*/

int 
find_pos(int *arr, int low, int high)
{
	int val = arr[low];
	
	while (low < high)
	{
		while (low < high && arr[high] >= val)
		{
			high--;
		}
		
		arr[low] = arr[high];
		
		while (low < high && arr[low] <= val)
		{
			low++;
		}
		
		arr[high] = arr[low];
	}	//end while 终止条件 low == high
	
	arr[low] = val;
	
	return low;
}

void 
quick_sort(int *arr, int low, int high)
{
	int pos;
	
	if (low < high)
	{
		pos = find_pos(arr, low,  high);
		quick_sort(arr, low, pos - 1);
		quick_sort(arr, pos + 1, high);
	}
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

int 
main(void)
{
	int i;
	int a[] = {3, 49, 90, 3, 7, 1, 67};
	
	
	printf("排序前：\n");
	print_arr(a, 7);
	
	quick_sort(a, 0, 6);
	
	printf("输出快速排序结果：\n");	
	print_arr(a, 7);
	return ;
}
