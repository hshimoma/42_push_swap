/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:45:54 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 00:23:44 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//メモリを動的に確保するための関数で連続したメモリ領域を確保

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	if (size > 0 && nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	ptr = (unsigned char *)malloc(nmemb * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_memset(ptr, '\0', nmemb * size);
	return ((void *)ptr);
}

// int main(void)
// {
//     // int *arr = (int*)ft_calloc(5, sizeof(int));
// 	int *arr = (int*)calloc(0, 0);

//     if (arr == NULL)
//     {
//         printf("メモリ確保に失敗しました。\n");
//         return (1);
//     }

//     for (int i = 0; i < 5; i++) {
//         printf("arr[%d] = %d\n", i, arr[i]);
//     }

//     free(arr);
//     return (0);
// }
