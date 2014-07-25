#include "stdio.h"
void sel_sort(int *arr, int len) 
{
	int i, j, k;

	for (i = 0; i < len-1; i++) /*���len-1�˱Ƚ�*/
	{
		k = i; /*���ñ�־λ*/
		for (j = i +1; j < len; j++)
		{
			if (arr[k] > arr[j]) /*����ǰ����ں���Ԫ�أ��ı��־λ*/ 
				k = j;
		}

		if (k != i) /*�����־λ�ı�� ������*/
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
