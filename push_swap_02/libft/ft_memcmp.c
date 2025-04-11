/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:03:43 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/19 19:11:03 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//メモリブロックの比較をする関数

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = s1;
	const unsigned char	*p2 = s2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
		{
			return (p1[i] - p2[i]);
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int main(void)
// {
//     char s1[] = "Hello";
//     char s2[] = "World";

//     int result = ft_memcmp(s1, s2, sizeof(s1));
//     printf("結果: %d\n", result);
//     return (0);
// }

// int main(void)   //testcase2 0になる
// {
//     char s1[] = "Hello";
//     char s2[] = "Hello";

//     int result = ft_memcmp(s1, s2, sizeof(s1));
//     printf("結果: %d\n", result);
//     return (0);
// }
