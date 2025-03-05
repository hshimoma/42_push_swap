#include "push_swap.h"

//新しいノードをスタックのトップに追加する関数
void	lstadd_front(t_stack *stack, t_node *new_node)
{
	if (stack == NULL || new_node == NULL) //NULLチェック
		return ;
	new_node->next = stack->top; //新しいノードのnextを現在のトップに設定
	stack ->top = new_node; //スタックのトップを新しいノードに更新
}

//スタックのトップのノードを削除し、削除したノードのポインタを返す関数
t_node *node_clear(t_stack *stack)
{
    t_node *top_node;

    if (stack == NULL || stack->top == NULL) //スタックが空ならNULLを返す
        return(NULL);
    top_node = stack->top; //取り出すノードを保存
    stack->top = stack->top->next; //スタックのトップを次のノードに更新
    top_node->next = NULL; //取り出したノードのnextをNULLにする（安全対策）
    return (top_node); //取り出したノードを返す
}

//'pa'(スタックBのトップをスタックAのトップに移動)
void pa(t_stack *a, t_stack *b)
{
    t_node *moved_node;

    if (b == NULL || b->top == NULL) //スタックBが空なら何もしない
        return ;
    moved_node = node_clear(b); //スタックBのトップを取得
    lstadd_front(a, moved_node); //スタックAにプッシュ
}

//'pb'(スタックAのトップをスタックBのトップに移動)
void pb(t_stack *a, t_stack *b)
{
    t_node *moved_node;

    if (a == NULL || a->top == NULL) //スタックが空なら何もしない
        return ;
    moved_node = node_clear(a); //スタックAのトップを取得
    //スタックBのトップに移動('lstadd_front'を使わずに直接処理)
    moved_node->next = b->top; //'moved_node' のnext を　'b'のトップに設定
    b->top = moved_node; //スタックBのトップを'moved_node'に更新
}

//main
//新しいノードを作成し、指定された値を格納する関数
t_node *new_node(int value)
{
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node)); //新しいノードのメモリを確保
    if (node == NULL) //メモリ確保失敗時はNULLを返す
        return (NULL);
    node->value = value; //ノードの値を設定
    node->next = NULL; //'nextをNULLに初期化
    return (node); //作成したノードを返す
}

//スタックの内容を表示する関数
void print_stack(t_stack *stack, char *name)
{
    t_node *now;

    now = stack->top;
    printf("stack %s: ", name); //スタックの名前を表示
    while (now) //スタックのノードを順番に表示
    {
        printf("%d -> ",now->value);
        now = now->next;
    }
    printf("NULL\n"); //末尾を示す
}

void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *next;

    current = stack->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    stack->top = NULL;
}

int main(void)
{
    t_stack a = {NULL}; //スタックAを初期化（空）
    t_stack b = {NULL}; //スタックAを初期化（空）

    //スタックAに3，2，1の順でプッシュ（1がトップになる）
    lstadd_front(&a, new_node(3));
    lstadd_front(&a, new_node(2));
    lstadd_front(&a, new_node(1));

    //初期化状態を表示
    printf("befor:\n");
    print_stack(&a, "A");
    print_stack(&b, "B");

    //'pb'を2回実行（スタックAのトップをBに移動）
    pa(&a, &b);
    pa(&a, &b);

    //'pb'実行後の状態を表示
    printf("\nafter pb twice:\n");
    print_stack(&a, "A");
    print_stack(&b, "B");

    //'pb'を1回実行（スタックBのトップをAに移動）
    pa(&a, &b);

    //'pa'実行後の状態を表示
    printf("\nafter pa once:\n");
    print_stack(&a, "A");
    print_stack(&b, "B");

    //メモリ解放
    free_stack(&a);
    free_stack(&b);

    return (0);
}

// コードの流れ
// １．スタックAに3，2，1を追加（pushを使う）
//     ・stack A: 1 -> 2 -> 3 -> NULL
//     ・stack B: NULL

// ２．pbを２回実行（AのトップをBのトップに移動）
//     ・stack A: 1 -> 2 -> NULL
//     ・stack B: 3 -> 2 -> NULL

// ３．paを１回実行（BのトップをAのトップに移動）
//     ・stack A: 1 -> 2 -> 3 -> NULL
//     ・stack B: 2 -> NULL

// まとめ

// ・lstadd_fornt:スタックのトップにノードを追加
// ・node_clear:スタックのトップのノードを削除して返す
// ・pa:スタックのトップのノードを削除して返す
// ・pb：スタックAのトップをスタックBに移動
// ・create_node：指定した値のノードを作成
// ・print_stack：スタックの状態を表示
