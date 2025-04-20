#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_node
{
	int value;
	int index;
	struct s_node * next;
} t_node;

void error(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int ft_atoi(const char *str)
{
	long result;
	int sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		error();
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			error();
		result = result * 10 + (*str - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			error();
		str++;
	}
	return ((int)(result * sign));
}

t_node *new_node(int value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		error();
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void add_node(t_node **stack, t_node *node)
{
	t_node *tmp;

	if (*stack == NULL)
		*stack = node;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

int stack_size(t_node *stack)
{
	int count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void free_stack(t_node *stack)
{
	t_node *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int *stack_to_array(t_node *stack, int size)
{
	int *arr;
	int i;

	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		error();
	i = 0;
	while (i < size)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (arr);
}

void bubble_sort(int *arr, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void assign_index(t_node *stack, int *arr, int size)
{
	int i;

	while (stack != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (stack->value == arr[i])
			{
				stack->index = i;
				break;
			}
			i++;
		}
		stack = stack->next;
	}
}

void pb(t_node **a, t_node **b)
{
	t_node *temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write (1, "pb\n", 3);
}

void pa(t_node **a, t_node **b)
{
	t_node *temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write (1, "pa\n", 3);
}

void ra(t_node **a)
{
	t_node *first;
	t_node *last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	write (1, "ra\n", 3);
}

void radix_sort(t_node **a, t_node **b)
{
	int size;
	int max_index;
	int max_bits;
	int i;
	int j;

	size = stack_size(*a);
	max_index = size - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b != NULL)
			pa(a, b);
		i++;
	}
}

int sort_check(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	t_node *a = NULL;
	t_node *b = NULL;
	t_node *node;
	int size;
	int *arr;
	int i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		node = new_node(ft_atoi(argv[i]));
		add_node(&a, node);
		i++;
	}
	size = stack_size(a);
	arr = stack_to_array(a, size);
	if (sort_check(arr, size))
	{
		free(arr);
		free_stack(a);
		return (0);
	}
	bubble_sort(arr, size);
	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
			error();
		i++;
	}
	assign_index(a, arr, size);
	free(arr);
	radix_sort(&a, &b);
	free_stack(a);
	return (0);
}
