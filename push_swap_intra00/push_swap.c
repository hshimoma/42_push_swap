/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:11:05 by hshimoma          #+#    #+#             */
/*   Updated: 2025/04/15 23:11:07 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_sort(t_node **a, t_node **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
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

static t_node	*initialize_stack(int argc, char *argv[], char ***args_out)
{
	t_node	*a;
	t_node	*node;
	char	**args;
	int		i;

	a = NULL;
	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1]);
	}
	else
		args = &argv[1];
	*args_out = args;
	if (all_num(args) != 1)
		return (NULL);
	while (args[i] != NULL)
	{
		node = new_node(ft_atoi(args[i]));
		add_node(&a, node);
		i++;
	}
	return (a);
}

static int	check(t_node **a, int size, int argc)
{
	int	*arr;
	int	i;

	arr = stack_to_array(*a, size);
	if (argc == 2)
		return (free(arr), 1);
	if (sort_check(arr, size))
	{
		free(arr);
		return (1);
	}
	compression(arr, size);
	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
			error();
		i++;
	}
	assign_index(*a, arr, size);
	free(arr);
	return (0);
}

static void	free_args(char **args, int argc)
{
	int	i;

	i = 0;
	if (argc != 2)
		return ;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args[i]);
	free(args);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	char	**args;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = initialize_stack(argc, argv, &args);
	if (a == NULL)
		return (write(1, "Error\n", 6), free_split(args), 1);
	if (check(&a, stack_size(a), argc) == 1)
		return (free_args(args, argc), free_stack(a), 0);
	else if (stack_size(a) == 2)
		sort_two(&a);
	else if (stack_size(a) == 3)
		sort_three(&a);
	else if (stack_size(a) == 4)
		sort_four(&a, &b);
	else if (stack_size(a) == 5)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);
	return (free_stack(a), free_stack(b), 0);
}
