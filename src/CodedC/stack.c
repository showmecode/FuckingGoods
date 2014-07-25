#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct Node
{
	int value;
	struct Node *link;
}NODE;

typedef struct
{
	NODE *p_top;
	NODE *p_botton;
}STACK;

/*��������*/
void init(STACK *p_stack);
void push(STACK *p_stack, int value);
void traverse(STACK *p_stack);
int	 pop(STACK *p_stack, int *value);
int isempty(STACK *p_stack);
int	pop(STACK *p_stack, int *value);
int clear(STACK *p_stack);

int 
main(void)
{
	STACK stack;
	int value; /*�����ջ��ֵ*/
	
	/*��ʼ��ջ,����һ����ջ*/
	init(&stack);

	traverse(&stack);

	/*ѹջ*/
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);
	push(&stack, 6);

	/*�������*/
	traverse(&stack);
		
	/*��ջ*/
	if (0 == pop(&stack, &value))
	{
		printf("��ջʧ�ܣ������ԣ�");
	}
	else
	{
		printf("��ջ��Ԫ����:%d\n", value);
	}
	
	traverse(&stack);

	/*���ջ*/
	if (0 == clear(&stack))
	{
		printf("���ʧ�ܣ�");
	}
	else
	{
		printf("��ճɹ���");
	}

	traverse(&stack);

	return 0;
}

void 
init(STACK *p_stack)
{
	/*Ϊջ��ָ�뿪���ڴ�ռ䣬��ʹջ��ָ��ָ��ÿռ�*/
	p_stack->p_botton = (NODE *)malloc(sizeof (NODE));
	if (NULL == p_stack->p_botton)
	{
		printf("ջ�ڴ�ռ����ʧ�ܣ�������!");
		exit(-1);
	}
	else
	{	
		p_stack->p_top = p_stack->p_botton;	/*ʹջ�׺�ջ��ָ��ͬʱָ�򿪱ٵĿռ�*/
		p_stack->p_botton->link = NULL;		/*��ʼ�����ٵĿռ䣬����ָ������Ϊ�գ�*/
	}
	

	
	return ;
}

void push(STACK *p_stack, int value)
{
	/*Ϊ�½ڵ㿪�ٿռ�*/
	NODE *p_new = (NODE *)malloc(sizeof (NODE));
	
	/*��ʼ���½ڵ�*/
	p_new->value   = value;			/*����ֵ*/
	p_new->link    = p_stack->p_top;	/*���½ڵ��ָ����ָ��ԭջ���ڵ�*/
	p_stack->p_top = p_new;			/*ջ��ָ��ָ���½ڵ�*/

	return ;
}


void traverse(STACK *p_stack)
{
	NODE *p_current = p_stack->p_top;
	
	if (p_current == p_stack->p_botton)
	{
		printf("ջΪ�գ�\n");
		return ;
	}

	while (p_current != p_stack->p_botton)
	{
		printf("%d " , p_current->value);
		p_current = p_current->link; 
	}

	printf("\n");	

	return ;
}

/*
	calls (TRUE FALSE)
	return int : 0/1 
*/
int
isempty(STACK *p_stack)
{
	if (p_stack->p_top == p_stack->p_botton)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*
	calls (TRUE FALSE)
	input ���ڽ��ճ�ջ��ֵ
	return int : 0/1 
*/
int	
pop(STACK *p_stack, int *value)
{
	NODE *p_current;	/*���ڴ��ջ��ָ��*/

	if (1 == isempty(p_stack))
	{
		return FALSE;
	}
	
	/*��ջ*/
	p_current      = p_stack->p_top;				/*����ָ��ָ��ջ��ָ��*/
	p_stack->p_top = p_stack->p_top->link;			/*����ջ��ָ��*/
	*value         = p_current->value;				/*���ճ�ջ��ֵ*/
	free(p_current);								/*�ͷų�ջ��Ŀռ�*/
	

	return TRUE;
}

int 
clear(STACK *p_stack)
{
	NODE *p_current;
	NODE *p_previous;

	if (1 == isempty(p_stack))
	{
		return FALSE;
	}
	
	p_current = p_stack->p_top;
	p_previous = NULL;

	while (p_current != p_stack->p_botton)
	{
		p_previous = p_current->link;
		free(p_current);
		p_current  = p_previous;
	}

	p_stack->p_top = p_stack->p_botton;

	return TRUE;
}