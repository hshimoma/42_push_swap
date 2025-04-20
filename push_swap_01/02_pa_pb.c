#include "push_swap.h"

void push(t_stack *from, t_stack *to)
{
    t_node *moved_node;

    if (from == NULL || from->top == NULL)
        return ;
    moved_node = from->top;
    from->top = moved_node->next;
    moved_node->next = to->top;
    to->top = moved_node;
}

void pa(t_stack *a, t_stack *b)
{
    push(b, a);
    printf("pa\n");
}

void pb(t_stack *a, t_stack *b)
{
    push(a, b);
    printf("pb\n");
}
