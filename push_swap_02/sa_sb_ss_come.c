#include "push_swap.h"

void swap(t_stack *stack) //スタックの先頭2つの要素を交換する関数
{
    t_node *first; //スタックの最初のノードを指すポインタ
    t_node *second; //スタックの２番目のノードを指すポインタ

    //スタックがNULL、要素が1つ以下の場合は何もしない
    if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
        return ;
    first = stack->top; //スタックの1番上のノード
    second = first->next; //2番目のノード
    first->next = second->next; //最初のノードを3番目以降のノードに接続
    second->next = first; //2番目のノードを最初のノードに接続
    stack->top = second; //2番目のノードをスタックの新しいトップにする
}

// swap関数
// ・スタックの先頭2つの要素を入れ替える
// ・firstが最初の要素、secondが2番目の要素
// ・first->nextをsecond->nextに変更し、second->nextをfirstに変更
// ・結果：スタックのトップがsecondになる

void sa(t_stack *a)
{
    swap(a); //スタックAの先頭2つの要素を交換
    printf("sa\n");
}

void sb(t_stack *b)
{
    swap(b); //スタックBの先頭2つの要素を交換
    printf("sb\n");
}

void ss(t_stack *a, t_stack *b)
{
    swap(a); //スタックAの先頭2つの要素を交換
    swap(b); //スタックBの先頭2つの要素を交換
    printf("ss\n");
}

//main
void print_stack(t_stack *stack)
{
    t_node *current = stack->top;
    while (current)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

t_node *create_node(int value)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

t_stack *create_stack(void)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    stack->top = NULL;
    return (stack);
}

void push(t_stack *stack, int value)
{
    t_node *new_node;

    new_node = create_node(value);
    new_node->next = stack->top;
    stack->top = new_node;
}

int main(void)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = create_stack();
    stack_b = create_stack();

    push(stack_a, 3);
    push(stack_a, 2);
    push(stack_a, 1);

    push(stack_b, 6);
    push(stack_b, 5);
    push(stack_b, 4);

    printf("befor stackA: ");
    print_stack(stack_a);
    printf("befor stackB: ");
    print_stack(stack_b);

    sa(stack_a);
    printf("after sa:\n");
    print_stack(stack_a);

    sb(stack_b);
    printf("after sb:\n");
    print_stack(stack_b);

    ss(stack_a, stack_b);
    printf("after ss:\nstackA: ");
    print_stack(stack_a);
    printf("stackB: ");
    print_stack(stack_b);

    free(stack_a);
    free(stack_b);

    return (0);
}