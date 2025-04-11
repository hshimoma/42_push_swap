/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:04:42 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/19 00:55:03 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//メモリのブロックの中身をコピーする関数

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = src;
	d = dest;
	if (d == NULL && s == NULL)
		return (NULL);
	if (d == NULL && n != 0)
		ft_strlen(NULL);
	if (n == 0)
		return (dest);
	if (s == NULL)
		ft_strlen(NULL);
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}

// int main(void)
// {
// char src[] = "Hello, world!";
// char dest[100];
// memset(dest, 'A', 100);

// ft_memcpy(dest,src,sizeof(src));
// printf("%s\n",dest);
// ft_memcpy(dest,NULL, 0);
// printf("dest:NULL %s\n",dest);
// printf("dest:NULL %s\n",(char *)ft_memcpy(((void *)0), ((void *)0), 3));
// ft_memcpy(dest,NULL,0);
// printf("src:NULL %s\n",dest);
//     return (0);
// }
