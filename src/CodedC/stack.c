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

/*声明函数*/
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
	int value; /*保存出栈的值*/
	
	/*初始化栈,产生一个空栈*/
	init(&stack);

	traverse(&stack);

	/*压栈*/
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);
	push(&stack, 6);

	/*遍历输出*/
	traverse(&stack);
		
	/*出栈*/
	if (0 == pop(&stack, &value))
	{
		printf("出栈失败！请重试！");
	}
	else
	{
		printf("出栈的元素是:%d\n", value);
	}
	
	traverse(&stack);

	/*清空栈*/
	if (0 == clear(&stack))
	{
		printf("清空失败！");
	}
	else
	{
		printf("清空成功！");
	}

	traverse(&stack);

	return 0;
}

void 
init(STACK *p_stack)
{
	/*为栈底指针开辟内存空间，并使栈底指针指向该空间*/
	p_stack->p_botton = (NODE *)malloc(sizeof (NODE));
	if (NULL == p_stack->p_botton)
	{
		printf("栈内存空间分配失败，请重试!");
		exit(-1);
	}
	else
	{	
		p_stack->p_top = p_stack->p_botton;	/*使栈底和栈顶指针同时指向开辟的空间*/
		p_stack->p_botton->link = NULL;		/*初始化开辟的空间，将其指针域设为空，*/
	}
	

	
	return ;
}

void push(STACK *p_stack, int value)
{
	/*为新节点开辟空间*/
	NODE *p_new = (NODE *)malloc(sizeof (NODE));
	
	/*初始化新节点*/
	p_new->value   = value;			/*赋新值*/
	p_new->link    = p_stack->p_top;	/*将新节点的指针域指向原栈顶节点*/
	p_stack->p_top = p_new;			/*栈顶指针指向新节点*/

	return ;
}


void traverse(STACK *p_stack)
{
	NODE *p_current = p_stack->p_top;
	
	if (p_current == p_stack->p_botton)
	{
		printf("栈为空！\n");
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
	input 用于接收出栈的值
	return int : 0/1 
*/
int	
pop(STACK *p_stack, int *value)
{
	NODE *p_current;	/*用于存放栈顶指针*/

	if (1 == isempty(p_stack))
	{
		return FALSE;
	}
	
	/*出栈*/
	p_current      = p_stack->p_top;				/*用新指针指向将栈顶指针*/
	p_stack->p_top = p_stack->p_top->link;			/*下移栈顶指针*/
	*value         = p_current->value;				/*接收出栈的值*/
	free(p_current);								/*释放出栈后的空间*/
	

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