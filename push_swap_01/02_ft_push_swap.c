/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:23:14 by hshimoma          #+#    #+#             */
/*   Updated: 2025/03/03 22:32:57 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sa(t_stack *a)
{
	swap(a);
	printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	printf("sb\n");
}
void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}

void	push(t_stack *from, t_stack *to)
{
	t_node	*moved_node;

	if (from == NULL || from->top == NULL)
		return ;
	moved_node = from->top;
	from->top = moved_node->next;
	moved_node->next = to->top;
	to->top = moved_node;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	printf("pb\n");
}

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_stack *a)
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}

void	reverse_totate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a)
{
	reverse_totate(a);
	printf("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_totate(b);
	printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_totate(a);
	reverse_totate(b);
	printf("rrr\n");
}

// main
t_node	*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push_stack(t_stack *stack, int value)
{
	t_node	*new;

	new = new_node(value);
	if (new == NULL)
		return ;
	new->next = stack->top;
	stack->top = new;
}

void	print_stack(t_stack *stack, char *name)
{
	t_node	*current;

	current = stack->top;
	printf("stack %s: ", name);
	while (current)
	{
		printf("%d -> ", current->value);
		current = current->next;
	}
	printf("NULL\n");
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
}

int	main(void)
{
	t_stack	a;
	t_stack	b;

	a = {NULL};
	b = {NULL};
	push_stack(&a, 3);
	push_stack(&a, 2);
	push_stack(&a, 1);
	printf("befor:\n");
	print_stack(&a, "A");
	print_stack(&b, "B");
	sa(&a);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pa(&a, &b);
	ra(&a);
	rb(&b);
	rr(&a, &b);
	rra(&a);
	rrb(&b);
	rrr(&a, &b);
	printf("after:\n");
	print_stack(&a, "A");
	print_stack(&b, "B");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
