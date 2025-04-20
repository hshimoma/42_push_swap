#include "push_swap.h"

void push(t_stack *from, t_stack *to) //スタックからノードを移動させる関数
{
    t_node *moved_node; //移動させるノードを格納するポインタ

    if (from == NULL || from->top == NULL) //空ならなにもしない
        return ;
    //fromスタックの一番上のノードを移動させる
    moved_node = from->top; //移動させるノードを取得
    from->top = moved_node->next; //fromスタックの一番上を次のノードに更新
    moved_node->next = to->top; //移動させたノードの次をtoスタックの一番上に設定
    to->top = moved_node; //toスタックの一番上を移動させたノードに更新
}

//スタックbからスタックaにノードを移動させる関数
void pa(t_stack *a, t_stack *b)
{
    push(b, a); //bからaにノードを移動
    printf("pa\n");
}

//スタックaからスタックbにノードを移動させる関数
void pb(t_stack *a, t_stack *b)
{
    push(a, b); //aからbにノードを移動
    printf("pb\n");
}

// コードの説明
// ・t_node構造体は、スタックの各要素（ノード）を表します。各ノードは、次のノードへのポインタと、
// そのノードが持つ値を持っています。
// ・t_stack構造体は、スタック全体を表し、一番上のノードへのポインタを持っています。
// ・push関数は、指定されたスタックから別のスタックにノードを移動させる機能を持っています。
// 移動元のスタックが空ではない場合にのみ、ノードを移動します。
// ・pa関数は、スタックbからスタックaにノードをさせるラッパー関数で、移動後に"pa"というメッセージを残す
// ・pb関数は、スタックaからスタックbにノードをさせるラッパー関数で、移動後に"pb"というメッセージを残す

//main
void print_stack(t_stack *stack)
{
    t_node *current = stack->top;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

t_node *create_node(int value)
{
    t_node *new_node;
    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

int main(void)
{
    t_stack a = {NULL};
    t_stack b = {NULL};

    //スタックAにノードを追加
    a.top = create_node(1);
    a.top->next = create_node(2);
    a.top->next->next = create_node(3);

    printf("initial stackA: ");
    print_stack(&a);
    printf("initial stackB: ");
    print_stack(&b);

    //pbを呼び出してスタックAからスタックBにノードを移動
    pb(&a, &b);
    printf("after pb:\nstackA: ");
    print_stack(&a);
    printf("stack B: ");
    print_stack(&b);

    //paを呼び出してスタックBからスタックAにノードを移動
    pa(&a, &b);
    printf("after pa:\nstackA: ");
    print_stack(&a);
    printf("stackB: ");
    print_stack(&b);

    return (0);
}
