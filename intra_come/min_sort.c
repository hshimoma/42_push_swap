/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:10:53 by hshimoma          #+#    #+#             */
/*   Updated: 2025/04/18 23:25:15 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//要素数が2のスタックをソート
//もし同じ数字が2つある場合→エラー、上の方が大きいならsa(a)
void	sort_two(t_node **a)
{
	if ((*a)->value == (*a)->next->value)
		error();
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

//3つの要素を並べ替えるための条件分岐ソート
//first,second,thirdにそれぞれの値を代入して比較。入力が3つだと、並び方は全部で6通り
//それぞれのパターンに応じて、sa（スワップ）ra(回転)rra(逆回転)を組み合わせる
void	sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && first < third)
		sa(a);
	else if (first > second && first > third && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first < second && first < third && second > third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && first > third)
		rra(a);
	return ;
}

//4つの要素を並べる
//１．index == 3を探す（値が一番大きいノードを探す）　２．それをスタックのトップに移動する（回転or逆回転）
//３．pb(a, b)でスタックAからスタックBにその一番大きい値を一時退避　４．残りの３つをsort_threeで並び替え
//５．最後にpa(a, b)で退避してた要素を戻す。　６．そしてra(a)で正しい場所に戻す
void	sort_four(t_node **a, t_node **b)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = *a;
	while (tmp->index != 3)
	{
		i++;
		tmp = tmp->next;
	}
	if (i > 2)
	{
		while (i++ < 4)
			rra(a);
	}
	else
	{
		while (i-- > 0)
			ra(a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
	ra(a);
}

//５つの要素を並び替える　（sort_fourと同じイメージ）
void	sort_five(t_node **a, t_node **b)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = *a;
	while (tmp->index != 4)
	{
		i++;
		tmp = tmp->next;
	}
	if (i > 2)
	{
		while (i++ < 5)
			rra(a);
	}
	else
	{
		while (i-- > 0)
			ra(a);
	}
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
	ra(a);
}
