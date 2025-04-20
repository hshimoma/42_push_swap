/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:52:28 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/11 21:51:57 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ascii文字かどうかのテスト

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <stdio.h>

// int main(void)
// {
//     printf("a = %d \n",ft_isascii('a'));
//     printf("5 = %d \n",ft_isascii('5'));
//     printf("@ = %d \n",ft_isascii('@'));
//     printf("偽 = %d \n",ft_isascii(128));
//     printf("偽 = %d \n",ft_isascii(-1));
//     return (0);
// }