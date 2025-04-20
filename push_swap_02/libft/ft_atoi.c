/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:43:25 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/19 19:03:03 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//文字列を整数にする関数

#include "libft.h"

static int	sign_count(const char *str, int *i, int *sign)
{
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
		{
			*sign = -1;
		}
		else
		{
			*sign = 1;
		}
		(*i)++;
		if (str[*i] == '+' || str[*i] == '-')
		{
			return (0);
		}
	}
	return (1);
}

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\v')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *nptr)
{
	int				i;
	long long int	nbr;
	int				sign;

	i = 0;
	while (is_space(nptr[i]))
		i++;
	sign = 1;
	if (sign_count(nptr, &i, &sign) == 0)
		return (0);
	nbr = 0;
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (sign == 1 && nbr > (LONG_MAX - (nptr[i] - '0')) / 10)
			return (-1);
		else if (sign == -1 && nbr > (LONG_MAX - (nptr[i] - '0')) / 10)
			return (0);
		nbr = (nbr * 10) + (nptr[i] - '0');
		if (sign == 1 && nbr == INT_MAX)
			return (INT_MAX);
		else if (sign == -1 && INT_MIN == -nbr)
			return (INT_MIN);
		i++;
	}
	return ((int)(nbr * sign));
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
// 	printf("%d\n",ft_atoi(--42));
// 	return (0);
// }
