/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:51:14 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/11 21:48:46 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// alphaであるかの文字のテスト

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// #include <stdio.h>

// int main(void)
// {
//     char c;

//     c = 'a';
//     if (ft_isalpha(c))
//     {
//         printf("%c は真である\n",c);
//     }
//     else
//     {
//         printf("%c は偽である\n",c);
//     }
//     return (0);
// }