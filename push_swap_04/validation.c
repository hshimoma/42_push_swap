/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:08:15 by hshimoma          #+#    #+#             */
/*   Updated: 2025/04/18 18:15:05 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	all_num(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i] != NULL)
	{
		j = 0;
		if (strs[i][j] == '-')
			j++;
		while (strs[i][j] != '\0')
		{
			if (strs[i][j] < '0' || strs[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
