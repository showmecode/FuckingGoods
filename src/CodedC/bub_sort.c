#include <stdio.h>

void bub_sort(int *arr, int n)
{
	int i, j;
	int flag = 0;	/*����һ����־λ*/

	for (i = 0; i < n-1; i++)	/*n-1������*/
	{
		for (j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1]) /*������Ԫ���б�ǰ��С�ľͽ���*/
			{	
				arr[j] = arr[j] + arr[j+1];
			  arr[j+1] = arr[j] - arr[j+1];
				arr[j] = arr[j] - arr[j+1];
			   	  flag = 1;	/*����־λ����Ϊ1����ʾ������*/
			}
		}

		if (flag == 0) /*��û�з����������ͽ����㷨*/
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
