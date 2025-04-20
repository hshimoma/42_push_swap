/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 02:41:09 by hshimoma          #+#    #+#             */
/*   Updated: 2025/03/03 20:50:22 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (stack == NULL || (*stack) == NULL || ((*stack)->next) == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **stack_a)
{
	ft_swap(stack_a);
	printf("sa\n");
}

void	sb(t_node **stack_b)
{
	ft_swap(stack_b);
	printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	printf("ss\n");
}

// main
void	print_stack(t_node *stack)
{
	while (stack != NULL)
	{
		printf("%d -> ", stack->value);
		stack = stack->next;
	}
	printf("NULL\n");
}

void	print_stack(t_stack *stack, char *name)
{
	t_node	*current;

	current = stack->top;
	printf("stack %s: ", name);
	while (current)
	{
		printf("%d-> ", current->value);
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
		free(current);s
		current = next;
	}
	stack->top = NULL;
}

// void free_stack(t_node *stack)
// {
//     t_node *tmp;
//     while (stack != NULL)
//     {
//         tmp = stack;
//         stack = stack->next;
//         free(tmp);
//     }
// }

// int main(void)
// {
//     t_node *stack_a = new_node(1);
//     stack_a->next = new_node(2);
//     stack_a->next->next = new_node(3);

//     t_node *stack_b = new_node(4);
//     stack_b->next = new_node(5);
//     stack_b->next->next = new_node(6);

//     printf("befor sa:\nstack A: ");
//     print_stack(stack_a);
//     sa(&stack_a);
//     printf("after sa:\nstackA: ");
//     print_stack(stack_a);

//     printf("befor sb:\nstackB: ");
//     print_stack(stack_b);
//     sb(&stack_b);
//     printf("after sb:\nstackB: ");
//     print_stack(stack_b);

//     printf("befor ss:\nstackA ");
//     print_stack(stack_a);
//     printf("stackB: ");
//     print_stack(stack_b);
//     ss(&stack_a, &stack_b);
//     printf("after ss:\nstackA: ");
//     print_stack(stack_a);
//     printf("stackB: ");
//     print_stack(stack_b);

//     free_stack(stack_a);
//     free_stack(stack_b);
//     return (0);
// }

void	push(t_stack *stack, int value)
{
	t_node	*new;

	new = new_node(value);
	if (new == NULL)
		return ;
	new->next = stack->top;
	stack->top = new;
}

int	main(void)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = {NULL};
	stack_b = {NULL};
	push(&stack_a, 3);
	push(&stack_a, 2);
	push(&stack_a, 1);
	push(&stack_b, 6);
	push(&stack_b, 5);
	push(&stack_b, 3);
	printf("befor sa:\n");
	print_stack(&stack_a, "A");
	sa(&stack_a.top);
	printf("after sa:\n");
	printf("befor sb:\n");
	print_stack(&stack_b.top, "B");
	sb(&stack_b.top);
	printf("after sb:\n");
	print_stack(&stack_b, "B");
	printf("\nbefor ss:\n");
	print_stack(&stack_a, "A");
	print_stack(&stack_b, "B");
	ss(&stack_a.top, &stack_b.top);
	printf("after ss:\n");
	print_stack(&stack_a, "A");
	print_stack(&stack_b, "B");
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

// todo
//一旦print_stackも同じ関数で使えないかためしてるところ、
//コンパイルできない状態、引数が２個あるのに一つしかないからコンパイルできないと言ってる