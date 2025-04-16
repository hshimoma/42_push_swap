/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:10:53 by hshimoma          #+#    #+#             */
/*   Updated: 2025/04/16 20:59:03 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_node **a)
{
	t_node *first;
	t_node *last;
	t_node *second_from_back;

	first = *a;
	last = *a;
	second_from_back = NULL;
	while (last->next) {
		second_from_back = last;
		last = last->next;
	}
	second_from_back->next = NULL;
	*a = last;
	last->next = first;
	write(1, "rra\n", 4);
}

void sort_two(t_node **a)
{
	if ((*a)->value == (*a)->next->value)
		error();
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void sort_three(t_node **a)
{
	int first;
	int second;
	int third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if(first > second && first < third)
		sa(a);
	else if (first  > second && first > third && second > third)
	{
		sa(a);
		rra(a);
	}
	else if(first > second && first > third && second < third)
		ra(a);
	else if(first < second && first < third && second > third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && first > third)
		rra(a);
	return ;
}

void sort_four(t_node **a, t_node **b)
{
	int i = 0;
	t_node *tmp;

	tmp = *a;
	while (tmp->index != 3)
	{
		i++;
		tmp = tmp->next;
	}
	if(i > 2)
	{
		while(i < 4)
		{
			rra(a);
			i++;
		}
	}
	else
	{
		while(i > 0)
		{
			ra(a);
			i--;
		}
	}
	pb(a, b);
	sort_three(a);
	pa(a,b);
	ra(a);
}

void sort_five(t_node **a, t_node **b)
{
	int i = 0;
	t_node *tmp;

	tmp = *a;
	while (tmp->index != 4)
	{
		i++;
		tmp = tmp->next;
	}
	if(i > 2)
	{
		while(i < 5)
		{
			rra(a);
			i++;
		}
	}
	else
	{
		while(i > 0)
		{
			ra(a);
			i--;
		}
	}
	pb(a,b);
	sort_four(a,b);
	pa(a,b);
	ra(a);
}
