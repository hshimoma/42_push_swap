/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:03:07 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/19 19:07:58 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//メモリ内の特定の文字を検索する

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (const unsigned char)c)
		{
			return ((void *)&p[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <string.h>

// int main(void)
// {
//     const char str[] = "Hello, World!";
//     char *result = memchr(str, 'W', strlen(str));

//     if (result != NULL)
//     {
//         printf("Found 'W' at position: %ld\n", result - str);
//     }
//     else
//     {
//         printf("'W' not found.\n");
//     }

//     return (0);
// }
