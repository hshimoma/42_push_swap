#include "push_swap.h"

void reverse_rotate(t_stack *stack)
{
    t_node *before;
    t_node *last;

    if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
        return ;
    before = NULL;
    last = stack->top;
    while (last->next)
    {
        before = last;
        last = last->next;
    }
    before->next = NULL;
    last->next = stack->top;
    stack->top = last;
}

void rra(t_stack *a)
{
    reverse_rotate(a);
    printf("rra\n");
}

void rrb(t_stack *b)
{
    reverse_rotate(b);
    printf("rrb\n");
}

void rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    printf("rrr\n");
}
