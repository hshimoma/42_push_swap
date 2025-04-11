/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:04:43 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/18 21:32:47 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//文字列をコピーする関数

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
	{
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// #include <string.h>

// int main(void)
// 	{
// 		// char dst[100] = "Hello";

// 		// printf("World %lu, dst = %s\n",strlcat(dst, "World", 11), dst);
// 		printf("dst:NULL %lu\n",ft_strlcpy(NULL, "World", 0));
// 		return (0);
// 	}