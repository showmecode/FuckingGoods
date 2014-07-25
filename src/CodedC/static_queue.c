#include <stdio.h>
#include <malloc.h>
#define QUEUE_LENGTH 6
#define TRUE 1
#define FALSE 0

typedef struct queue
{
	int *link;
	int front;
	int rear;
}QUEUE;

/*��������*/
void init(QUEUE *p_queue);
int is_full(QUEUE *p_queue);
int en_queue(QUEUE *p_queue, int value);
void traverse(QUEUE *p_queue);
int out(QUEUE *p_queue, int *p_value);
int is_empty(QUEUE *p_queue);
void in_state(int status);
void out_state(int status);

int main(void)
{
	QUEUE queue;
	int value;

	init(&queue);

	in_state(en_queue(&queue, 1));
	in_state(en_queue(&queue, 3));
	in_state(en_queue(&queue, 6));
	in_state(en_queue(&queue, 4));
	in_state(en_queue(&queue, 9));
	in_state(en_queue(&queue, 10));
	in_state(en_queue(&queue, 19));

	traverse(&queue);

	out_state(out(&queue, &value));
	printf("����Ԫ�أ�%d\n", value);

	traverse(&queue);

	return ;
}

void
init(QUEUE *p_queue)
{
	p_queue->link = (int *)malloc(sizeof (int) * QUEUE_LENGTH);
	p_queue->front = 0;
	p_queue->rear = 0;

	return ;
}

int
is_full(QUEUE *p_queue)
{
	if ((p_queue->rear + 1) % QUEUE_LENGTH == p_queue->front)
	{
		printf("����������\n");
		return TRUE;
	}

	return FALSE;
}

int
is_empty(QUEUE *p_queue)
{
	if (p_queue->rear == p_queue->front)
	{
		printf("����Ϊ��");
		return TRUE;
	}

	return FALSE;
}

int
en_queue(QUEUE *p_queue, int value)
{
	if (1 == is_full(p_queue))
	{
		return FALSE;
	}

	p_queue->link[p_queue->rear] = value;
	p_queue->rear = (p_queue->rear + 1) % QUEUE_LENGTH;

	return TRUE;
}

void
traverse(QUEUE *p_queue)
{
	int tmp = p_queue->front;
	while (tmp != p_queue->rear)
	{
		printf("%d ", p_queue->link[tmp]);
		tmp = (tmp + 1) % QUEUE_LENGTH;
	}

	return ;
}

void
in_state(int status)
{
	if (1 == status)
	{
		printf("��ӳɹ���\n");
	}
	else
	{
		printf("���ʧ�ܣ�\n");
	}

	return ;
}

int
out(QUEUE *p_queue, int *p_value)
{
	if (1 == is_empty(p_queue))
	{
		printf("����ʧ�ܣ�\n");
		return FALSE;
	}

	*p_value = p_queue->link[p_queue->front];
	p_queue->front = (p_queue->front + 1) % QUEUE_LENGTH;

	return TRUE;
}

void
out_state(int status)
{
	if (1 == status)
	{
		printf("���ӳɹ���\n");
	}
	else
	{
		printf("����ʧ�ܣ�\n");
	}

	return ;
}