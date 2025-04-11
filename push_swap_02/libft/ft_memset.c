/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:08:01 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/20 03:19:18 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memset、メモリ領域を定数バイトで埋める

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// int main(void)
// {
//     char memori[10];

//     ft_memset(memori, "a", sizeof(memori));

//     size_t i;

//     i = 0;
//     while (i < sizeof(memori))
//     {
//         printf("%c ",memori[i]);
//         i++;
//     }
//     printf("\n");
//     return (0);
// }
