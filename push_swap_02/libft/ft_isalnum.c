/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:46:26 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/16 23:12:39 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//英数字であるかの文字テスト

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9'));
}

// #include <stdio.h>

// int main(void)
// {
//     printf("a = %d \n",ft_isalnum('a'));
//     printf("5 = %d \n",ft_isalnum('5'));
//     printf("@ = %d \n",ft_isalnum('@'));
//     printf("空白 = %d \n",ft_isalnum(' '));
//     printf("Z = %d \n",ft_isalnum('Z'));
//     return (0);
// }
