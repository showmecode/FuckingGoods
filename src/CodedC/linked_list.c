/*
		Copyright:	2012 ByCN
		File Name:	creat_linkedlist.c
	  Description:	����һ����ѭ���������������ڵ���룬�ڵ���Ŀͳ��
	       Author:	CN 
		  Version:	1.0
			 Date:	2012-08-01
		  History:	none	

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define FALSE 0;
#define TRUE 1;
#include <assert.h>

/*
	���嵥����ר�ýṹ��
	��Ӧ�÷���NODE.h�ļ�
*/
typedef
struct Node
{
	int value;
	struct Node *link; /*ָ����*/
}NODE;

/*��������*/
NODE *creat_list(void);
void traverse_linkedlist(NODE *p_root);
void traverse_linkedlist(NODE *p_root);
int sll_count_nodes(NODE *p_first);
int sll_remove(NODE **linkp, NODE *p_del, int *del_val);

int 
main(void)
{
	NODE *p_root = NULL;
	int del_val;

	p_root = creat_list(); /*����һ����ѭ�����������ظ�ָ��*/
	traverse_linkedlist(p_root);	/*��������*/
	
	/*�����½��*/
	if (!sll_insert(&p_root, 19))
	{
		printf("����ڵ�ʧ�ܣ������ԣ�");
	}

	printf("����������");
	traverse_linkedlist(p_root);

	printf("���ڽڵ����Ϊ:%d\n", sll_count_nodes(p_root->link));
	
	/*ɾ���ڵ�*/
	if (sll_remove(&p_root, p_root->link->link, &del_val))
	{
		printf("ɾ���ڵ�ɹ�����ɾ���Ľڵ��ֵΪ��%d\n", del_val);
	}
	
	printf("ɾ���������Ϊ��\n");
	traverse_linkedlist(p_root);

	free(p_root);
	return 0;
}

/*
		 Function��	creat_linkedlist
	  Description:	������ѭ�����������ظ�ָ��
			calls:	stdio.h
					malloc.h
					stdlib.h
					NODE.h
		Called by:	none
			input:	void
		   output:	
		   return:	NODE *
		   others:	none
*/
NODE *
creat_list(void)
{
	int len;
	int i;
	int value;
	NODE *p_root; 
	NODE *p_tail;

	/*��ʼ����ָ�롣��������ݣ�����ָ���һ�����*/
	p_root = (NODE *)malloc(sizeof (NODE));
	if (NULL == p_root)
	{
		printf("��ָ�봴��ʧ�ܣ������ԣ�");
		exit(-1);
	}
	
	/*��ʼ��βָ��,��ָ���ָ��*/
	p_tail = p_root;
	p_tail->link = NULL;

		
	printf("����������Ҫ����������Ľ�������");
	while (scanf("%d", &len),len < 0)
	{
		printf("������Ľ����������⣡���������룺");
	}
	
	
	for (i = 0; i < len; i++)
	{
		NODE *p_new; /*�����½��*/

		printf("�������%d������ֵ:", i+1);
		scanf("%d", &value);

		/*����ռ䲢��������*/
		p_new = (NODE *)malloc(sizeof (NODE));
		if (NULL == p_new)
		{
			printf("��㴴��ʧ�ܣ������ԣ�");
			exit(-1);
		}
		p_new->value = value;	/*���½�����ֵ*/
		p_tail->link = p_new;	/*��ԭβָ��ָ����ָ��*/
		p_new->link  = NULL;	/*����ָ��ָ�������*/
			  p_tail = p_new;	/*����ָ��ת��Ϊβָ��*/
	}

	return p_root;
}

/*
		 Function��	traverse_linkedlist
	  Description:	��������ڵ�
			calls:	stdio.h
					NODE.h
		Called by:	none
			input:	void
		   output:	NODE * ���͵ĸ�ָ��
		   return:	void
		   others:	none	
*/
void 
traverse_linkedlist(NODE *p_root)
{
	NODE *p_current = p_root->link;

	/*�������*/
	printf("������Ԫ��ֵΪ��");
	while (NULL != p_current)
	{
		printf("%d ", p_current->value);
		p_current = p_current->link;
	}

	printf("\n");
	
	return ;
}

/*
		 Function��	sll_insert(ssl:single linked list)
	  Description:	�ڵ����������һ���ڵ�(���ֵ�˳���С����)
			calls:	stdio.h
					malloc.h
					NODE.h
		Called by:	none
			input:	NODE **linkp, int value.
					linkpָ���ָ���ָ��
					value��Ҫ�����ֵ
		   output:	none
		   return:	int : 0/1
		   others:	none		
*/
int 
sll_insert(NODE **linkp, int value)
{
	NODE *p_current;
	NODE *p_new_node;

	// Ѱ����Ҫ�����λ��
	while ((p_current=*linkp) != NULL && p_current->value <= value)
	{
		linkp = & p_current->link;
	}

	// ����ռ�
	p_new_node = (NODE*)malloc(sizeof (NODE));
	if (p_new_node == NULL)
	{
		return FALSE
	}
	p_new_node->value = value;

	// ��������
	*linkp = p_new_node;
	p_new_node->link = p_current;
	return TRUE;
}

/*
		 Function��	sll_count_nodes(ssl:singly linked list)
	  Description:	�ڵ����������ڵ�ĸ���
			calls:	stdio.h
					NODE.h 
		Called by:	none
			input:	NODE *p_first 
					p_first ��һ���ڵ��ָ��
		   output:	none
		   return:	int �ڵ����
		   others:	none		
*/
int 
sll_count_nodes(NODE *p_first)
{
	int count;

	for (count = 0; p_first != NULL; p_first = p_first->link)
	{
		count++;
	}

	return count;
}

/*
		 Function��	sll_remove
	  Description:	�ڵ�����ɾ��ָ��ָ��ڵ��ֵ
			calls:	stdio.h
					NODE.h 
					assert.h
		Called by:	none
			input:	NODE **kinkp, NODE *p_del, int *del_val
					kinkp	ָ���ָ���ָ��
					p_del	��Ҫɾ���Ľڵ��ָ��
					del_val ��ɾ���Ľڵ��ֵ
		   output:	none
		   return:	int 0/1
*/
int
sll_remove(NODE **linkp, NODE *p_del, int *del_val)
{
	register NODE *p_current;

	assert(NULL != p_del);

	/*Ѱ��Ҫɾ���Ľڵ�*/
	while (NULL != (p_current = *linkp) && p_current != p_del)
	{
		linkp = &p_current->link;
	}

	if (p_current == p_del)
	{
		*del_val = p_current->value;
		*linkp = p_current->link;
		free(p_current);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

