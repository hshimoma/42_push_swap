#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//スタックのノード構造体を定義
typedef struct s_node
{
    int value; //実際の値
    int index; //ソートされたときのインデックス
    struct s_node *next; //次のノードへのポインタ
} t_node;

//エラーが発生したときのメッセージを出して終了する関数
void error(void)
{
    write (2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

//文字列を整数に変換するatoiの自作版
int ft_atoi(const char *str)
{
    long result;
    int sign;

    result = 0;
    sign = 1;
    while ((*str >= 9 && *str <= 13) || *str == ' ')
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    if (*str == '\0') //符号の後が空ならエラー
            error();
    while (*str != '\0') //数値に変換
    {
        if (*str < '0' || *str > '9')
            error();
        result = result * 10 + (*str - '0');
        if (result * sign > 2147483647 || result * sign < -2147483648) //intの範囲外ならエラー
            error();
        str++;
    }
    return ((int)(result * sign));    
}

t_node *new_node(int value) //新しいノードを作成
{
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (node == NULL)
        error();
    node->value = value;
    node->index = 0;
    node->next = NULL;
    return (node);
}

void add_node(t_node **stack, t_node *node)//スタックの末尾にノードを追加
{
    t_node *tmp;

    if (*stack == NULL)
        *stack = node;
    else
    {
        tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = node;
    }
}

int stack_size(t_node *stack) //スタックのサイズ（ノード数）を数える
{
    int count;

    count = 0;
    while (stack != NULL)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}

void free_stack(t_node *stack) //スタックの全ノードをfreeで解放
{
    t_node *tmp;

    while (stack != NULL)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

int *stack_to_array(t_node *stack, int size) //スタックの値を配列にコピー
{
    int *arr;
    int i;

    arr = (int *)malloc(sizeof(int) * size);
    if (arr == NULL)
        error();
    i = 0;
    while (i < size)
    {
        arr[i] = stack->value;
        stack = stack->next;
        i++;
    }
    return (arr);
}

void bubble_sort(int *arr, int size) //バブルソートで配列を昇順に並び替える
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

void assign_index(t_node *stack, int *arr, int size) //各ノードに昇順配列のインデックスを割り当てる
{
    int i;

    while (stack != NULL)
    {
        i = 0;
        while (i < size)
        {
            if (stack->value == arr[i])
            {
                stack->index = i;
                break;
            }
            i++;
        }
        stack = stack->next;
    }
}

void pb(t_node **a, t_node **b) //スタックaの先頭をbへ移す（push）
{
    t_node *temp;

    if (*a == NULL)
        return ;
    temp = *a;
    *a = (*a)->next;
    temp->next = *b;
    *b = temp;
    write (1, "pb\n", 3);
}

void pa(t_node **a, t_node **b) //スタックbの先頭をaへ移す(push)
{
    t_node *temp;

    if (*b == NULL)
        return ;
    temp = *b;
    *b = (*b)->next;
    temp->next = *a;
    *a = temp;
    write (1, "pa\n", 3);
}

void ra(t_node **a) //スタックaの先頭要素を最後に移動(rotate)
{
    t_node *first;
    t_node *last;

    if (*a == NULL || (*a)->next == NULL)
        return ;
    first = *a;
    last = *a;
    while (last->next)
        last = last->next;
    *a = first->next;
    first->next = NULL;
    last->next = first;
    write (1, "ra\n", 3);
}

void radix_sort(t_node **a, t_node **b) //ビットごとの比較でソートを行う（基数ソート）
{
    int size;
    int max_index;
    int max_bits;
    int i;
    int j;

    size = stack_size(*a);
    max_index = size - 1; //stackAの要素
    max_bits = 0;
    while ((max_index >> max_bits) != 0) //ソートに必要なビット数を計算
        max_bits++;
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if (((*a)->index >> i) & 1) //i番目のビットが1ならra,0ならpb
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (*b != NULL) //bにある全要素をaに戻す
            pa(a, b);
        i++;
    }
}

//arr配列の先頭size個の要素が昇順に並んでいるかを確認、昇順なら1をそうでなければ0を返す
int sort_check(int *arr, int size)
{
    int i;

    i = 0;
    while(i < size - 1)
    {
        if(arr[i] > arr[i + 1])
            return(0);
        i++;
    }
    return(1);
}

int main(int argc, char *argv[])
{
    t_node *a = NULL;
    t_node *b = NULL;
    t_node *node;
    int size;
    int *arr;
    int i;

    if (argc < 2)
        return (0);
    //引数をノードとしてスタックaに追加
    i = 1;
    while (i < argc)
    {
        node = new_node(ft_atoi(argv[i]));
        add_node (&a, node);
        i++;
    }
    size = stack_size(a);
    arr = stack_to_array(a, size); //スタックを配列にコピー
    //ソート済みの場合は何も出力せずに正常終了
    if (sort_check(arr, size))
    {
        free(arr);
        free_stack(a);
        return(0);
    }
    bubble_sort(arr, size); //配列をソート
    //重複をチェック
    i = 0;
    while (i < size - 1)
    {
        if (arr[i] == arr[i + 1])
            error();
        i++;
    }
    assign_index(a, arr, size); //ソート順にインデックスを割り当て
    free(arr);
    radix_sort(&a, &b); //基数ソートを実行
    free_stack(a); //スタックのメモリを解放
    return (0);
}