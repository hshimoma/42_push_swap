/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:55:49 by hshimoma          #+#    #+#             */
/*   Updated: 2025/03/03 09:48:45 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack *a)
{
    t_node *prev;
    t_node *last;

    if (a == NULL || a->top == NULL || a->top->next == NULL)
        return ;
    prev = NULL;
    last = a->top;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = a->top;
    a->top = last;
}

void rrb(t_stack *b)
{
    rra(b);
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}

//main
void lstadd_front(t_stack *stack, t_node *new_node)
{
    if (stack == NULL || new_node == NULL)
        return ;
    new_node->next = stack->top;
    stack->top = new_node;
}

t_node *new_node(int value)
{
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (node == NULL)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

void print_stack(t_stack *stack, char *name)
{
    t_node *current;

    printf("stack %s: ", name);
    current = stack->top;
    while (current)
    {
        printf("%d, -> ",current->value);
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

int main(void)
{
    t_stack a = {NULL};
    t_stack b = {NULL};

    lstadd_front(&a, new_node(3));
    lstadd_front(&a, new_node(2));
    lstadd_front(&a, new_node(1));

    lstadd_front(&b, new_node(6));
    lstadd_front(&b, new_node(5));
    lstadd_front(&b, new_node(4));

    printf("befor:\n");
    print_stack(&a, "A");
    print_stack(&b, "B");

    rra(&a);
    printf("\nafter rra:\n");
    print_stack(&a, "A");
    print_stack(&b, "B");

    rrb(&b);
    printf("\nafter rrb:\n");
    print_stack(&a, "A");
    print_stack(&b, "B");

    rrr(&a, &b);
    printf("\nafter rrr:\n");
    print_stack(&a, "A");
    print_stack(&b, "B");

    free_stack(&a);
    free_stack(&b);

    return (0);
}
