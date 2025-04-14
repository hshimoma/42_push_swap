/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:29:32 by hshimoma          #+#    #+#             */
/*   Updated: 2025/03/04 17:43:39 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack *stack)
{
    t_node *first;
    t_node *second;

    if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
        return ;
    first = stack->top;
    second = first->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
}

void sa(t_stack *a)
{
    swap(a);
    printf("sa\n");
}

void sb(t_stack *b)
{
    swap(b);
    printf("sb\n");
}

void ss(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
    printf("ss\n");
}

void print_stack(t_stack *stack)
{
    t_node *current = stack->top;
    while (current)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

t_node *create_node(int value)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

t_stack *create_stack(void)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    stack->top = NULL;
    return (stack);
}

void push(t_stack *stack, int value)
{
    t_node *new_node;

    new_node = create_node(value);
    new_node->next = stack->top;
    stack->top = new_node;
}

int main(void)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = create_stack();
    stack_b = create_stack();

    push(stack_a, 3);
    push(stack_a, 2);
    push(stack_a, 1);

    push(stack_b, 6);
    push(stack_b, 5);
    push(stack_b, 4);

    printf("befor stackA: ");
    print_stack(stack_a);
    printf("befor stackB: ");
    print_stack(stack_b);

    sa(stack_a);
    printf("after sa:\n");
    print_stack(stack_a);

    sb(stack_b);
    printf("after sb:\n");
    print_stack(stack_b);

    ss(stack_a, stack_b);
    printf("after ss:\nstackA: ");
    print_stack(stack_a);
    printf("stackB: ");
    print_stack(stack_b);

    free(stack_a);
    free(stack_b);

    return (0);
}