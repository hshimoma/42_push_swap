/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:11:05 by hshimoma          #+#    #+#             */
/*   Updated: 2025/04/15 23:11:07 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//基数ソート(2進数ベースに並び替えアルゴリズム)
//各ノードにつけたindexのビット(0or1)を見て、aからbに移動させながら並び替える
//高速なアルゴリズム
static void	radix_sort(t_node **a, t_node **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b != NULL)
			pa(a, b);
		i++;
	}
}

//スタック（連結リスト）を作る関数
//文字列で渡された数字をt_nodeに変換してリストとしてつなげます
//argc = 2の時(./push_swap "3 2 1")は分割が必要なのでft_splitを使う。
//引数の中に数字以外があればエラーを返す。完成したスタックを返す。
static t_node	*initialize_stack(int argc, char *argv[], char ***args_out)
{
	t_node	*a;
	t_node	*node;
	char	**args;
	int		i;

	a = NULL;
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1]);
	else
		args = &argv[1];
	*args_out = args;
	if (all_num(args) != 1)
		return (NULL);
	while (args[i] != NULL)
	{
		if (ft_atol(args[i]) > INT_MAX || ft_atol(args[i]) < INT_MIN)
			return (NULL);
		node = new_node(ft_atol(args[i]));
		add_node(&a, node);
		i++;
	}
	return (a);
}

//入力を検査する関数
//スタックの内容を配列に変換して、すでにソートされているかをチェック、重複があるかをチェック(あればerror();)
//assign_index:値を圧縮（小さい値に番号を割り振る）
static int	check(t_node **a, int size, int argc)
{
	int	*arr;
	int	i;

	arr = stack_to_array(*a, size);
	if (argc == 2 && stack_size(*a) == 0)
		return (free(arr), 1);
	if (sort_check(arr, size))
	{
		free(arr);
		return (1);
	}
	bubble_sort(arr, size);
	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
			return (free(arr), error(), 1);
		i++;
	}
	assign_index(*a, arr, size);
	free(arr);
	return (0);
}

//動的に確保したargs（文字列配列）のメモリを開放する関数
//argc == 2 の時のみ（ft_splitを使った時）。各文字をfree()して最後に配列自体もfree()。
static void	free_args(char **args, int argc)
{
	int	i;

	i = 0;
	if (argc != 2)
		return ;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args[i]);
	free(args);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	char	**args;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = initialize_stack(argc, argv, &args);
	//コマンドライン引数から数字を読み込んで、スタックに変換
	if (a == NULL) //無効な入力ならエラーを出して終了
		return (error(), free_args(args, argc), 1);
	if (check(&a, stack_size(a), argc) == 1) //同じ値がないか、ソート済みかをチェック
		return (free_args(args, argc), free_stack(a), 0);
	else if (stack_size(a) == 2) //要素数が少なければ、専用のソートを関数を使う
		sort_two(&a);
	else if (stack_size(a) == 3)
		sort_three(&a);
	else if (stack_size(a) == 4)
		sort_four(&a, &b);
	else if (stack_size(a) == 5)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b); //要素数が多ければ、radix_sortを使って並べる
	return (free_args(args, argc), free_stack(a), free_stack(b), 0); //ソートが終わったら、メモリを開放してプログラム終了
}
