/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:21:38 by hshimoma          #+#    #+#             */
/*   Updated: 2025/04/18 20:39:56 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//エラーを表示してプログラムを強制終了する関数
//exit(EXIT_FAINURE)で即座にプログラムを終了（1と同じ意味）
void	error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

//スタックのメモリをすべて解放する関数
//スタックはt_node型の連結リスト。各ノードを順番にfree()して、メモリリークを防ぐ。
//tmpという一時変数で次のノードを覚えておいて、今のノードを削除してから次へ進む。
void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

//スタックの値を普通の配列に変換する関数　check関数で使用
//ソートや重複チェックのために、スタックの中身をint配列にコピー
//メモリを確保して、スタックをたどりながらvalueをコピー。失敗したらerror()を呼んで終了
int	*stack_to_array(t_node *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
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

//配列の中身を小さい順に並び替える関数（バブルソート）
//数字がそれくらい小さいかを見分けるために、まず並び替える必要がある
//小さい数字ほど前の方に来るようにする。
//バブルソートとは隣同士の数字を比べて順番がおかしかったら変換する、それを繰り返して正しい順番に並べる
void	compression(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

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

//各ノードに「小さい順の番号(index)を割り当てる関数
//arrには並べた整数たちが入ってる。スタックの中身(value)と一致する値を探して、何番目かをindexとして代入
//radix_sortではこのindexを使って並び替えをするので超重要！！！
void	assign_index(t_node *stack, int *arr, int size)
{
	int	i;

	while (stack != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (stack->value == arr[i])
			{
				stack->index = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}
