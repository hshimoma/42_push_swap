#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int value;
	struct s_stack *next;
} t_stack;

t_stack *new_node(int value)
{
	t_stack *node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void ft_swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (stack == NULL || (*stack) == NULL || ((*stack)->next) == NULL)
		return;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	printf("sa\n");
}

void sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	printf("ss\n");
}

void print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%d -> ", stack->value);
		stack = stack->next;
	}
	printf("NULL\n");
}

void free_stack(t_stack *stack)
{
	t_stack *tmp;
	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int main(void)
{
	t_stack *stack_a = new_node(1);
	stack_a->next = new_node(2);
	stack_a->next = new_node(3);

	t_stack *stack_b = new_node(4);
	stack_b->next = new_node(5);
	stack_b->next = new_node(6);

	printf("befor sa:\nstack A: ");
	print_stack(stack_a);
	sa(&stack_a);
	printf("after sa:\nstack A: ");
	print_stack(stack_a);

	printf("before sb:\nstack B: ");
	print_stack(stack_b);
	sb(&stack_b);
	printf("after sb:\nstack B: ");
	print_stack(stack_b);

	printf("before ss:\nstack A: ");
	print_stack(stack_a);
	printf("stack B: ");
	print_stack(stack_b);
	ss(&stack_a, &stack_b);
	printf("after ss:\nstack A: ");
	print_stack(stack_a);
	printf("stack B: ");
	print_stack(stack_b);

	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
