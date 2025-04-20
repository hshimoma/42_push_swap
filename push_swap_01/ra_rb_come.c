#include "push_swap.h"

//スタックの先頭ノードを取り出す関数（スタックから削除）
t_node *node_clear(t_stack *stack) //pa_pb.c
{
    t_node *top_node;

    if (stack == NULL || stack->top == NULL) //スタック空ならなにもしない
        return (NULL);
    top_node = stack->top; //スタックのトップノードを取得
    stack->top = stack->top->next; //トップを次のノードに更新
    top_node->next = NULL; //取得したノードのnextをNULLに（安全対策）
    return (top_node); //取り出したノードを返す
}

//'ra'(rotate a)->'stack A'の最初の要素を最後に移動する
void ra(t_stack *a)
{
    t_node *first;
    t_node *last;

    if (a == NULL || a->top == NULL || a->top->next == NULL) //要素が１つ以下なら何もしない
        return ;
    first = node_clear(a); //'stackA'の先頭ノードを取得し、削除
    last = a->top;
    while (last->next) //'stackA'の最後のノードを探す
        last = last->next;
    last->next = first; //最後のノードのnextを'first'に設定
    first->next = NULL; //'first'を新しい最後のノードにする
}

//'rb'(rotate b)->'stackB'の最初の要素を最後に移動する（'ra'を流用）
void rb(t_stack *b)
{
    re(b); //'rb'は'ra'と同じ動作なので再利用
}

//'rr'(rotate both)->'ra'と'rb'を同時に実行
void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}

//main
//'lstadd_front':スタックの先頭に新しいノードを追加する
void lstadd_front(t_stack *stack, t_node *new_node)
{
    if (stack == NULL || new_node == NULL) //NULLチェック
        return ;
    new_node->next = stack->top; //新しいノードのnextを現在のトップに設定
    stack->top = new_node; //スタックのトップを新しいノードに更新
}

//ノードを作成し、値を設定する関数
t_node *create_node(int value)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node)); //ノードのメモリ確保
    if (new_node == NULL) //メモリ確保失敗時はNULLを返す
        return (NULL);
    new_node->value = value; //ノードに値を設定
    new_node->next = NULL; //'next'をNULLに初期化
    return (new_node);
}

//スタックの内容を表示する関数
void print_stack(t_stack *stack, char *name)
{
    t_node *current;

    printf("stack %s: ", name); //スタック名を表示
    current = stack->top;
    while (current) //スタックのノードを順番に表示
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n"); //末尾を示す
}

//スタックのメモリ解放関数
void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *next

    current = stack->top;
    while (current) //スタックを空にする
    {
        next = current->next;
        free(current);
        current = next;
    }
    stack->top = NULL; //スタックを空にする
}

int main(void)
{
    t_stack a = {NULL}; //初期化
    t_stack b = {NULL}; //初期化

    //'stackA' に3,2,1を追加（’1’がトップ）
    lstadd_front(&a, creare_node(3));
    lstadd_front(&a, create_node(2));
    lstadd_front(&a, create_node(1));

    //'stackB'に6,5,4を追加（’4’がトップ）
    lstadd_frotn(&b, create_node(6));
    lstadd_front(&b, create_node(5));
    lstadd_front(&b, create_node(4));

    //初期化状態を表示
    printf("befor:\n");
    print_stack(&a, "A");
    print_stack(&b, "B");

    //'ra'を実行
    ra(&b);
    printf("\nafter rb:\n");
    print_stack(&a, "A");
    print_stack(&b, "B");

    //'rr'を実行
    rr(&a, &b);
    printf("\nafter rr:\n");
    print_stack(&a, "A");
    print_stack(&b, "B");

    //メモリ解放
    free_stack(&a);
    free_stack(&b);

    return (0);
}

// コードの流れ
// １．stackAに3,2,1を追加（1がトップ）
//     ・stackA:1->2->3->NULL
//     ・stackB:->4->5->6->NULL
// ２．raを実行（stackAのトップを末尾に移動）
//     ・stackA:2->3->1->NULL
//     ・stackB:4->5->6->NULL
// ３．raを実行（stackBのトップを末尾に移動）
//     ・stackA:2->3->1->NULL
//     ・stackB:5->6->4->NULL
// ４．rrを実行（両方回転）
//     ・stackA:3->1->2->NULL
//     ・stackB:6->4->5->NULL

