/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:05:33 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/11 20:05:57 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

// #include <stdio.h>

// int main(void)
// {
//     const char str[] = "1234567890";
//     size_t s = ft_strlen(str);

//     printf("%zu\n", s);

//     return (0);
// }
