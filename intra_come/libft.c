/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:38:53 by hshimoma          #+#    #+#             */
/*   Updated: 2025/04/18 23:59:17 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//文字列（"123","-1"など）を整数に変換する関数
//特徴：空白や+/-をスキップ。不正な文字があるとえerror()で終了。intの範囲を超えるとerror()。
int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

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
	if (*str == '\0')
		error();
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			error();
		result = result * 10 + (*str - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			error();
		str++;
	}
	return ((int)(result * sign));
}

//与えられた値（整数）を持つ新しいノードを（要素）を作成する
//mallocでt_node構造体のメモリを確保。valueに渡された値を代入。indexはまだ未設定なので０にする。nextは一旦NULL。
t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		error();
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

//ノードをスタックの末尾に追加する
//１．*stackが空なら、そのままnodeを先頭にする　２．すでにノードがある場合は最後まで移動
//３．最後の.nextにnodeをセット
void	add_node(t_node **stack, t_node *node)
{
	t_node	*tmp;

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

//スタックにいくつノードがあるか（長さ）を数える
//１．stackの先頭から順番に.nextをたどる　２．そのたびにcount++して数える　３．最後までいったらcountを返す
int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
