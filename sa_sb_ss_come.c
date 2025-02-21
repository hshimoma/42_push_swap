#include <stdio.h>
#include <stdlib.h> //malloc,free

typedef struct s_stack //スタックノード構造体、スタックの要素を表す構造体
{
	int value; //ノードが持つ値（整数）
	struct s_stack *next; //次のノードを指すポインタ
} t_stack; //struct s_satckをこの名前で簡単に使えるように名前つけてる

t_stack *new_node(int value) //ノードを作成する関数
{
	t_stack *node;
	
	node = (t_stack *)malloc(sizeof(t_stack)); //メモリを確保
	if (node == NULL) //メモリ確保に失敗した場合
		return (NULL);
	node->value = value; //ノードの値を設定
	node->next = NULL; //次のノードは最初NULL（何も指してない）
	return (node); //作成したノードを返す
}

void ft_swap(t_stack **stack) //スタックの先頭２要素を交換
{
	t_stack *first; //先頭ノード
	t_stack *second; //2番目のノード
	
	if (stack == NULL || (*stack) == NULL || ((*stack)->next) == NULL)
		return; //要素が１つ以下なら何もしない
	first = *stack; //先頭のノードを取得
	second = first->next; //2番目のノードを取得
	first->next = second->next; //先頭ノードのnextを３番目のノードへ変更
	second->next = first; //２番目のノードのnextを先頭ノードへ変更
	*stack = second; //2番目のノードを新しい先頭にする
}

void sa(t_stack **stack_a) //sa:スタックAの先頭の２つの要素を交換
{
	ft_swap(stack_a); //交換を実行
	printf("sa\n"); //実行した操作を表示
}

void sb(t_stack **stack_b) //sb:スタックBの先頭の２つの要素を交換
{
	ft_swap(stack_b);
	printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b) //ss:sa.sbを同時に実行
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	printf("ss\n");
}

//main
void print_stack(t_stack *stack) //スタックの内容を表示するヘルパー関数
{
	while(stack != NULL) //スタックが空になるまでループ
	{
		printf("%d -> ", stack->value); //ノードの値を表示
		stack =stack->next; //次のノードに移動
	}
	printf("NULL\n"); //最後にNULLを表示（スタックの終端）
}

void free_stack(t_stack *stack) //スタックのメモリ解放関数
{
	t_stack *tmp; //一時的にノードを保持する変数
	while (stack != NULL) //スタックが空になるまでループ
	{
		tmp = stack; //現在のノードを保存
		stack = stack->next; //次のノードへ移動
		free(tmp); //保存しておいたノードのメモリを解放
	}
}

int main(void)
{
	//スタックAの作成（1 -> 2 -> 3）
	t_stack *stack_a = new_node(1); //スタックAの初期化
	stack_a->next = new_node(2);
	stack_a->next = new_node(3);

	//スタックBの作成（4 -> 5-> 6）
	t_stack *stack_b = new_node(4); //スタックBの初期化
	stack_b->next = new_node(5);
	stack_b->next = new_node(6);

	printf("befor sa:\nstack A: ");
	print_stack(stack_a);
	sa(&stack_a);
	printf("after sa:\nstack A: ");
	print_stack(stack_a);

	printf("befor sb:\nstackB: ");
	print_stack(stack_b);
	sb(&stack_b);
	printf("after sb:\nstack B: ");
	print_stack(stack_b);

	printf("befer ss:\nstack A: ");
	print_stack(stack_a);
	printf("stack B: ");
	print_stack(stack_b);
	ss(&stack_a,&stack_b);
	printf("after ss:\nstack A: ");
	print_stack(stack_a);
	printf("stack B: ");
	print_stack(stack_b);

	free_stack(stack_a); //メモリ解放
	free_stack(stack_b);

	return (0);
}
