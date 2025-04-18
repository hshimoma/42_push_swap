/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:02:51 by hshimoma          #+#    #+#             */
/*   Updated: 2025/04/18 18:11:05 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

void				pb(t_node **a, t_node **b);
void				pa(t_node **a, t_node **b);
void				ra(t_node **a);
void				sa(t_node **a);
void				rra(t_node **a);
void				sort_two(t_node **a);
void				sort_three(t_node **a);
void				sort_four(t_node **a, t_node **b);
void				sort_five(t_node **a, t_node **b);
void				error(void);
void				free_stack(t_node *stack);
int					*stack_to_array(t_node *stack, int size);
void				compression(int *arr, int size);
void				assign_index(t_node *stack, int *arr, int size);
int					ft_atoi(const char *str);
t_node				*new_node(int value);
void				add_node(t_node **stack, t_node *node);
int					stack_size(t_node *stack);
char				**ft_split(const char *str);
void				free_split(char **arr);
int					sort_check(int *arr, int size);
int					all_num(char **strs);

#endif
