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

void sa(t_node **a)
{
	t_node *first;
	t_node *second;

	if (a == NULL || (*a) == NULL || ((*a)->next) == NULL)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	write (1, "sa\n", 3);
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

void sort_tow(t_node **a)
{
	if ((*a)->value == (*a)->next->value)
		error();
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void sort_three(t_node **a)
{
	int first;
	int second;
	int third;
	
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first < second && second < third)
		;
	else if (first < third && third < second)
	{
		sa(a);
		ra(a);
	}
	else if (second < first && first < third)
		sa(a);
	else if (second < third && third < first)
	{
		ra(a);
		sa(a);
	}
	else if (third < first && first < second)
		ra(a);
	else if (third < second && second < first)
	{
		sa(a);
		ra(a);
		sa(a);
	}
}

void sort_four(t_node **a, t_node **b)
{
	t_node *tmp;
	int min;
	int pos;

	tmp = *a;
	min = tmp->value;
	pos = 0;
	while (tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp && tmp->value != min)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos == 1)
		ra(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3)
	{
		ra(a);
		ra(a);
		ra(a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void sort_five(t_node **a, t_node **b)
{
	t_node *tmp;
	int min;
	int pos;
	int i;

	i = 0;
	tmp = *a;
	min = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	tmp = *a;
	pos = 0;
	while (tmp != NULL && tmp->value != min)
	{
		pos++;
		tmp = tmp->next;
	}
	while (pos-- > 0)
		ra(a);
	pb(a, b);

	i = 0;
	tmp = *a;
	min = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	tmp = *a;
	pos = 0;
	while (tmp != NULL && tmp->value != min)
	{
		pos++;
		tmp = tmp->next;
	}
	while (pos-- > 0)
		ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

char *ft_strncpy(char *dst, const char * src, int size)
{
	int i;

	i = 0;
	while (i < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char **ft_split(const char *str)
{
	char **arr;
	int i;
	int j;
	int k;
	int len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[len] != '\0')
			len++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
	}
	arr = (char **)malloc(sizeof(char *) * (len + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		if (i != j)
		{
			arr[k] = (char *)malloc(sizeof(char) * (i - j + 1));
			if (arr[k] == NULL)
				return (NULL);
			ft_strncpy(arr[k], &str[j], (i - j));
			k++;
		}
	}
	arr[k] = NULL;
	return (arr);
}

void free_split(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

int main(int argc, char *argv[])
{
	t_node *a = NULL;
	t_node *b = NULL;
	t_node *node;
	char **args;
	int size;
	int *arr;
	int i;

	if (argc < 2)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1]);
	else
		args = &argv[1];
	i = 0;
	while (args[i] != NULL)
	{
		node = new_node(ft_atoi(args[i]));
		add_node(&a, node);
		i++;
	}
	size = stack_size(a);
	if (size == 2)
		sort_tow(&a);
	else if (size == 3)
		sort_three(&a);
	else if (size == 4)
		sort_four(&a, &b);
	else if (size == 5)
		sort_five(&a, &b);
	arr = stack_to_array(a, size);
	if (sort_check(arr, size))
	{
		free(arr);
		free_stack(a);
		if (argc == 2)
			free_split(args);
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
	if (argc == 2)
		free_split(args);
	return (0);
}
