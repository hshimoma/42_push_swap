/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:17:10 by hshimoma          #+#    #+#             */
/*   Updated: 2025/04/18 17:50:33 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
