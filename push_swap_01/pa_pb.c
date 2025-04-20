/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:55:38 by hshimoma          #+#    #+#             */
/*   Updated: 2025/03/03 09:18:24 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_front(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node->next = stack->top;
	stack->top = new_node;
}

t_node	*node_clear(t_stack *stack)
{
	t_node	*top_node;

	if (stack == NULL || stack->top == NULL)
		return (NULL);
	top_node = stack->top;
	stack->top = stack->top->next;
	top_node->next = NULL;
	return (top_node);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*moved_node;

	if (!b || !b->top)
		return ;
	moved_node = node_clear(b);
	lstadd_front(a, moved_node);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*moved_node;
	// t_node	*temp;

	if (!a || !a->top)
		return ;
	moved_node = node_clear(a);
	// if (!b->top)
	// {
	// 	push(b, moved_node);
	// 	return ;
	// }
	// temp = b->top;
	// while (temp->next)
	// 	temp = temp->next;
	// temp->next = moved_node;
	// moved_node->next = NULL;
	// // push(b, moved_node);
    moved_node->next = b->top;
    b->top = moved_node;
}


//main
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

void free_stack(t_stack *stack)
{
	t_node *current;
	t_node *next;

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
	t_stack a = {NULL};
	t_stack b = {NULL};

	lstadd_front(&a, create_node(3));
	lstadd_front(&a, create_node(2));
	lstadd_front(&a, create_node(1));

	printf("befor:\n");
	print_stack(&a, "A");
	print_stack(&b, "B");

	pb(&a, &b);
	pb(&a, &b);

	printf("\nafter pb twice:\n");
	print_stack(&a, "A");
	print_stack(&b, "B");

	pa(&a, &b);

	printf("\nafter pa once:\n");
	print_stack(&a, "A");
	print_stack(&b, "B");

	free_stack(&a);
	free_stack(&b);

	return (0);
}