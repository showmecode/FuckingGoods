/*
  fileName sort.c
*/
#include <stdio.h>

/* data struct */
typedef struct record
{
	int key;
	char *data;
}RECORD;

typedef struct tableData
{
	int key;
	char *data;
	signed int next;
}TABLE_DATA;


/* function declarations */
void prinRecordKey(RECORD *arr, int n);
void printTableKey(TABLE_DATA *arr, int n);
void insertSort(RECORD *arr, int size);
void binarySort(RECORD *arr, int size);
void tableInsertSort(TABLE_DATA *arr, int size);

int
main(void)
{
	RECORD arr[] = {{77, "Lucy"}, {44, "Alex"}, {99, "Mary"}, {66, "Eric"},
					{33, "Zuck"}, {55, "Lily"}, {88, "Mike"}, {22, "Tom"}};
	TABLE_DATA arrEx[] = {{77, "Lucy"}, {44, "Alex"}, {99, "Mary"}, {66, "Eric"},
					    	{33, "Zuck"}, {55, "Lily"}, {88, "Mike"}, {22, "Tom"}};

	int size = (sizeof (arr)) / (sizeof (RECORD));	

	
	/*
	printf("%d\n", size);
	printf("%d\n", arr[0].key);
	printf("%s\n", arr[0].data);
	*/
	printf("before sort:\n");
	prinRecordKey(arr, size);
	//insertSort(arr, size);
	binarySort(arr, size);
	printf("late of sort:\n");
	prinRecordKey(arr, size);

	printf("..............\n");
/* error	
	printf("before sort:\n");
	printTableKey(arrEx, 8);
	tableInsertSort(arrEx, 8);
	printf("late of sort:\n");
	printTableKey(arrEx, 8);
*/
	return 0;
}

/* print data struct sort by key */
void
prinRecordKey(RECORD *arr, int n)
{
	int i;

	for (i=0; i<n; i++)
	{
		printf("%d ", (*(arr+i)).key);	
	}
	
	printf("\n");
}

/*error! */
void
printTableKey(TABLE_DATA *arr, int n)
{
	int i, j;
	int EXC = 0;/* EXC: exchanged*/
	TABLE_DATA arrExchange;

	for (i=0; i<n; i++)
	{
		for (j=0; j<n-1; j++)
		{
			if (arr[j].next < arr[j+1].next)
			{
				arrExchange = arr[j+1];
				arr[j+1]    = arr[j];
				arr[j]      = arrExchange;
				EXC         = 1;
			}
		}
		
		if (EXC == 0)
		{
			break;
		}
	}
	
	for (i=0; i<n; i++)
	{
		printf("%d ", (*(arr+i)).key);	
	}
	
	printf("\n");
}


/*  straight insertion sort */
void insertSort(RECORD *arr, int size)
{
	int i, j;

	for (i=1; i < size; i++) /* size-1 times, arr[0] sorted, start at arr[1]  */
	{
		RECORD beWatch = arr[i];/* save be watch vairable  */
		j = i - 1;
		
		while ((beWatch.key < arr[j].key) && (j>=0))/* serach right index and insert */
		{
			arr[j+1] = arr[j];
			j--;
		}
		
		arr[j+1] = beWatch;
	}
}


/* binary sort  */
void binarySort(RECORD *arr, int size)
{
	int i, j;
	for (i=1; i<size; i++) /* n-1 times,start with inedx 1 */
	{
		RECORD beWatch = arr[i];
		int low  = 0;
		int high = i - 1;
		
		while (low <= high) /* serch right index  */
		{
			int mid = (int)((low + high) / 2);
			
			if (beWatch.key > arr[mid].key)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		
		for (j = i-1; j >= high+1; j--)
		{
			arr[j+1] = arr[j]; /* shift index */
		}
		arr[high+1] = beWatch; /* insert data */
	}
}

/* table insert sort */
void tableInsertSort(TABLE_DATA *arr, int size)
{
	int i;
	signed int head = 0;
	for (i=0; i<size; i++)
	{
		arr[i].next = -1;
	}

	for (i=1; i<size; i++)
	{
		signed int qtr = -1;
		signed int ptr = head;
		
		while (ptr != -1 && arr[i].key >= arr[ptr].key)	
		{
			qtr = ptr;
			ptr = arr[ptr].next;
		}
		arr[i].next = ptr;
		
		if (qtr == -1)
		{
			head = i;
		}
		else
		{
			arr[qtr].next = i;
		}
	}
}





























