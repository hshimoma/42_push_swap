/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:17:10 by hshimoma          #+#    #+#             */
/*   Updated: 2025/04/18 23:46:09 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//スタックAの先頭要素をBへ移す
void	pb(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}

//スタックBの先頭要素をAへ移す
void	pa(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}

//スタックAを上から下に１つ回す
//１．最初の要素をfirstに保存。　２．最後の要素をlastまで走査。３．スタックの先頭を２番目に変更
//４．lastの次にfirstをつける、（最後に回す）５．first->next = NULLで終端にする
void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

//スタックAの先頭2つを入れ替える
//１．first = *a,second = first->next ２．ポインタを操作してsecondを先頭にする
void	sa(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (a == NULL || (*a) == NULL || ((*a)->next) == NULL)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	write(1, "sa\n", 3);
}

//スタックAを下から上に１つ回す（逆回転）
//１．lastを走査して一番最後の要素を見つける　２．その１つ前のsecond_from_backを記録
//３．second_from_back->next = NULL（末尾の切り離し）
//４．lastを先頭に持ってきて、last->next = *a 5.先頭を更新*a = last
void	rra(t_node **a)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_from_back;

	first = *a;
	last = *a;
	second_from_back = NULL;
	while (last->next)
	{
		second_from_back = last;
		last = last->next;
	}
	second_from_back->next = NULL;
	*a = last;
	last->next = first;
	write(1, "rra\n", 4);
}
