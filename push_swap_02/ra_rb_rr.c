#include "push_swap.h"

void rotate(t_stack *stack)
{
    t_node *first;
    t_node *last;

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

void ra(t_stack *a)
{
    rotate(a);
    printf("ra\n");
}

void rb(t_stack *b)
{
    rotate(b);
    printf("rb\n");
}

void rr(t_stack *a, t_stack *b)
{
    rotate(a);
    rotate(b);
    printf("rr\n");
}
