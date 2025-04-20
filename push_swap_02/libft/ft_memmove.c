/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:06:14 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/20 03:14:06 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//メモリブロックのコピー

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	return (dest);
}

// int main(void)
// {
//     char src[] = "Hello, World!";
//     char dest[20];

//     memmove(dest, NULL, 0);
//     printf("Copied string: %s\n", src);
//     return (0);
// }
