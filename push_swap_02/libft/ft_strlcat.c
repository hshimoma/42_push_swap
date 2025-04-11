/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:16:39 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/18 21:32:51 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//文字列を安全に連結する関数

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	if ((dst == NULL && size != 0) || src == NULL)
		ft_strlen(NULL);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (size + src_len);
	i = 0;
	j = dst_len;
	while (j + 1 < size && src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst_len + src_len);
}

// #include <string.h>

// int main(void)
// 	{
// 		// char dst[100] = "Hello";

// 		// printf("World %lu, dst = %s\n",strlcat(dst, "World", 11), dst);
// 		printf("dst:NULL %lu\n",strlcat(NULL, "World", 0));
// 		return (0);
// 	}