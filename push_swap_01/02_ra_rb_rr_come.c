#include "push_swap.h"

void rotate(t_stack *stack) //スタックの最上部の要素を下に移動させる関数
{
    t_node *first; //最上部のノードを指すポインタ
    t_node *last; //最下部のノードを指すポインタ

    if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
        return ;
    first = stack->top; //最上部のノードを取得
    stack->top = first->next; //スタックの最上部を次のノードに更新
    first->next = NULL; //最上部のノードを次のNULLに設定（下に移動させるため）
    last = stack->top; //新しい最上部のノードを見つける
    while (last->next) //最後のノードまで移動
        last = last->next;
    last->next = first; //最後のノードの次に最上部のノードを追加
}

void ra(t_stack *a) //スタックAを回転させる関数
{
    rotate(a);
    printf("rb\n");
}

void rb(t_stack *b) //スタックBを回転させる関数
{
    rotate(b);
    printf("rb\n");
}

void rr(t_stack *a, t_stack *b) //スタックAとスタックBを同時に回転させる関数
{
    rotate(a);
    rotate(b);
    printf("rr\n");
}

//main
t_node *create_node(int value) //スタックのノードを作成する関数
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

t_stack *create_stack(void) //スタックを初期化する関数
{
    t_stack *stack;
    stack = (t_stack *)malloc(sizeof(t_node));
    stack->top = NULL;
    return (stack);
}

void push_to_stack(t_stack *stack, int value) //スタックにノードを追加する関数
{
    t_node *new_node;

    new_node = create_node(value);;
    new_node->next = stack->top;
    stack->top = new_node;
}

void print_stack(t_stack *stack) //スタックの内容を表示する関数
{
    t_node *current;

    current = stack->top;
    printf("stack: ");
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main(void)
{
    t_stack *a;
    t_stack *b;

    a = create_stack();
    b = create_stack();

    push_to_stack(a, 1);
    push_to_stack(a, 2);
    push_to_stack(a, 3);
    push_to_stack(a, 4);

    push_to_stack(b, 5);
    push_to_stack(b, 6);

    printf("befor:\n");
    print_stack(a);
    print_stack(b);

    ra(a);
    printf("after ra:\n");
    print_stack(a);

    rb(b);
    printf("after rb:\n");
    print_stack(b);

    rr(a, b);
    printf("after rr:\n");
    print_stack(a);
    print_stack(b);

    free(a);
    free(b);
    return (0);
}