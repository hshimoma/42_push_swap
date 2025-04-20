#include "push_swap.h"

void reverse_rotate(t_stack *stack) //スタックを逆回転させる関数
{
    t_node *before; //前のノードを指すポインタ
    t_node *last; //最後のノードを指すポインタ

    if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
        return ;
    before = NULL; //最初の前のノードはNULL
    last = stack->top; //lastをスタックのトップに設定
    while (last->next) //スタックの最後のノードを見つける
    {
        before = last; //beforをlastに更新
        last = last->next; //lastを次のノードに移動
    }
    //最後のノードをスタックのトップに移動させる
    before->next = NULL; //prevの次をNULLにして最後のノードを切り離す
    last->next = stack->top; //lastの次を元のトップに設定
    stack->top = last; //スタックのトップをlastに更新
}

void rra(t_stack *a) //スタックAを逆回転させる関数
{
    reverse_rotate(a);
    printf("rra\n");
}

void rrb(t_stack *b) //スタックBを逆回転させる関数
{
    reverse_rotate(b);
    printf("rrb\n");
}

void rrr(t_stack *a, t_stack *b) //スタックAとスタックBを同時に逆回転させる関数
{
    reverse_rotate(a);
    reverse_rotate(b);
    printf("rrr\n");
}

//main
void push(t_stack *stack, int value) //スタックにノードを追加する関数
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
}

void print_stack(t_stack *stack) //スタックの内容を表示する関数
{
    t_node *current = stack->top;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main(void)
{
    t_stack a;
    t_stack b;
    
    a.top = NULL;
    //スタックAに要素を追加
    push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    push(&a, 4);

    printf("initial stackA: ");
    print_stack(&a);

    //スタックAを逆回転
    rra(&a);
    printf("after rra: ");
    print_stack(&a);

    //スタックBを作成
    b.top = NULL;

    //スタックBに要素を追加
    push(&b, 5);
    push(&b, 6);
    push(&b, 7);

    printf("initial stackB: ");
    print_stack(&b);

    //スタックBを逆回転
    rrb(&b);
    printf("after rrb: ");
    print_stack(&b);

    //両方のスタックを逆回転
    rrr(&a, &b);
    printf("after rrr: ");
    printf("stackA: ");
    print_stack(&a);
    printf("stackB: ");
    print_stack(&b);

    return (0);
}
