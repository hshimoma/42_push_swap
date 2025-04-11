/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:44:05 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/19 19:05:36 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//メモリ領域を0で初期化する関数

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

// #include <strings.h>    //bzero関数を実行の際に必要
// #include <stdio.h>

int main(void)
{
    char str[] = "Hello, World!";
    ft_bzero(str, 1);
    printf("結果 + 1: %s\n", str + 1);
    return (0);
}
