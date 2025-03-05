#include "push_swap.h"

t_node *new_node(int value) //新しいノードを作成
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node)); //メモリ確保
	if (node == NULL)
		return (NULL); //メモリ確保失敗時のエラーハンドリング
	node->value = value; //ノードに値をセット
	node->next = NULL; //最初は次のノードがない
	return (node);
}

void ft_swap(t_node **stack) //スタックの最初の２つの要素を交換
{
    t_node *first;
    t_node *second;

    if (stack == NULL || (*stack) == NULL || ((*stack)->next) == NULL)
        return ; //要素が１つ以下なら何もしない
    first = *stack; //最初の要素
    second = first->next; //2番目の要素
    first->next = second->next; //2番目の要素の次を１番目の要素の次にする
    second->next = first; //2番目の要素の次を１番目の要素にする
    *stack = second; //2番目の要素をスタックのトップにする
}

void sa(t_node **stack_a) //stackAの先頭２つを交換し、"sa"と表示
{
    ft_swap(stack_a);
    printf("sa\n");
}

void sb(t_node **stack_b) //stackBの先頭２つを交換し、"sb"と表示
{
    ft_swap(stack_b);
    printf("sb\n");
}

void ss(t_node **stack_a, t_node **stack_b) //stackA & stackB両方を同時に交換し、"ss"と表示
{
    ft_swap(stack_a);
    ft_swap(stack_b);
    printf("ss\n");
}

//main
void print_stack(t_node *stack) //スタックの中身を表示
{
    while (stack != NULL)
    {
        printf("%d -> ", stack->value); //ノードの値を表示
        stack = stack->next; //次のノードに移動
    }
    printf("NULL\n");
}

void free_stack(t_node *stack) //スタックのメモリを解放
{
    t_node *tmp;
    while (stack != NULL)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp); //メモリ解放
    }
}

int main(void)
{
    //stackAに1->2->3を追加
    t_node *stack_a = new_node(1);
    stack_a->next = new_node(2);
    stack_a->next->next = new_node(3);

    //stackBに4->5->6を追加
    t_node *stack_b = new_node(4);
    stack_b->next = new_node(5);
    stack_b->next->next = new_node(6);

    printf("befor sa:\nstack A: ");
    print_stack(stack_a);
    sa(&stack_a);
    printf("after sa:\nstackA: ");
    print_stack(stack_a);

    printf("befor sb:\nstackB: ");
    print_stack(stack_b);
    sb(&stack_b);
    printf("after sb:\nstackB: ");
    print_stack(stack_b);

    printf("befor ss:\nstackA ");
    print_stack(stack_a);
    printf("stackB: ");
    print_stack(stack_b);
    ss(&stack_a, &stack_b);
    printf("after ss:\nstackA: ");
    print_stack(stack_a);
    printf("stackB: ");
    print_stack(stack_b);

    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}

// 結果
// % cc -Wall -Wextra -Werror push_swap.c -o push_swap
// % ./push_swap
// befor sa:
// stack A: 1 -> 2 -> 3 -> NULL
// sa
// after sa:
// stack A: 2 -> 1 -> 3 -> NULL

// befor sb:
// stack B: 4 -> 5 -> 6 -> NULL
// sb
// after sb:
// stack B: 5 -> 4 -> 6 -> NULL

// befor ss:
// stack A: 2 -> 1 -> 3 -> NULL
// stack B: 5 -> 4 -> 6 -> NULL
// ss
// after ss:
// stack A: 1 -> 2 -> 3 -> NULL
// stack B: 4 -> 5 -> 6 -> NULL
