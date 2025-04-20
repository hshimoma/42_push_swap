/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:20:45 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 00:14:38 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//文字列を作った領域に複製する関数

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	size_t	len;
	char	*dup;

	len = ft_strlen(s) + 1;
	dup = malloc(len);
	if (dup == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     const char *original = "Hello, World!";
//     char *copy = ft_strdup(original);

//     if (copy)
//     {
//         printf("Original: %s\n", original);
//         printf("Copy: %s\n", copy);
//         free(copy);
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }

//     return (0);
// }
