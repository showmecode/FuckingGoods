#include <stdio.h>
#include <malloc.h>

/*定义二叉树节点结构体*/
typedef struct bt_node
{
    char value;
    struct bt_node *l_son;
    struct bt_node *r_son;
}BT_NODE;

/*声明函数*/
BT_NODE *creat_bt_tree(void);
void pre_traverse_bt_tree(BT_NODE *p_root);
void in_traverse_bt_tree(BT_NODE *p_root);
void post_traverse_bt_tree(BT_NODE *p_root);

int
main(void)
{
    BT_NODE *p_root;

    printf("创建二叉树：\n");
    p_root = creat_bt_tree();

    printf("遍历该二叉树：\n");
    pre_traverse_bt_tree(p_root);
    printf("done!\n");

    in_traverse_bt_tree(p_root);
    printf("done!\n");

    post_traverse_bt_tree(p_root);
    printf("done!\n");
    return 0;
}
BT_NODE
*creat_bt_tree(void)
{
    BT_NODE *p_node_a = (BT_NODE *)malloc(sizeof (BT_NODE));
    BT_NODE *p_node_b = (BT_NODE *)malloc(sizeof (BT_NODE));
    BT_NODE *p_node_c = (BT_NODE *)malloc(sizeof (BT_NODE));
    BT_NODE *p_node_d = (BT_NODE *)malloc(sizeof (BT_NODE));
    BT_NODE *p_node_e = (BT_NODE *)malloc(sizeof (BT_NODE));
    BT_NODE *p_node_f = (BT_NODE *)malloc(sizeof (BT_NODE));

    p_node_a->value = 'A';
    p_node_a->l_son = p_node_b;
    p_node_a->r_son = p_node_c;

    p_node_b->value = 'B';
    p_node_b->l_son = p_node_d;
    p_node_b->r_son = p_node_e;

    p_node_c->value = 'C';
    p_node_c->l_son = p_node_f;
    p_node_c->r_son = NULL;

    p_node_d->value = 'D';
    p_node_d->l_son = p_node_d->r_son = NULL;

    p_node_e->value = 'E';
    p_node_e->l_son = p_node_e->r_son = NULL;

    p_node_f->value = 'F';
    p_node_f->l_son = p_node_f->r_son = NULL;

    return p_node_a;
}

void
pre_traverse_bt_tree(BT_NODE *p_root)
{
    /*先序遍历*/
    if (NULL != p_root)
    {
        printf("%c ", p_root->value);

        if (NULL != p_root->l_son)
        {
            pre_traverse_bt_tree(p_root->l_son);
        }

        if (NULL != p_root->r_son)
        {
             pre_traverse_bt_tree(p_root->r_son);
        }

    }
}

void
in_traverse_bt_tree(BT_NODE *p_root)
{
    /*中序遍历*/
    if (NULL != p_root)
    {
        if (NULL != p_root->l_son)
        {
            pre_traverse_bt_tree(p_root->l_son);
        }

        printf("%c ", p_root->value);

        if (NULL != p_root->r_son)
        {
             pre_traverse_bt_tree(p_root->r_son);
        }
    }
}

void
post_traverse_bt_tree(BT_NODE *p_root)
{
     if (NULL != p_root)
    {
        if (NULL != p_root->l_son)
        {
            pre_traverse_bt_tree(p_root->l_son);
        }

        if (NULL != p_root->r_son)
        {
             pre_traverse_bt_tree(p_root->r_son);
        }

         printf("%c ", p_root->value);
    }
}





