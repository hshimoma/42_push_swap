/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimoma <hshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:53:24 by hshimoma          #+#    #+#             */
/*   Updated: 2024/11/17 17:00:44 by hshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//表示文字かどうかのテスト

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// int main(void)
// {
//     printf("a = %d \n",ft_isprint('a'));
//     printf("偽 = %d \n",ft_isprint(31));
//     printf("32 = %d \n",ft_isprint(32));
//     printf("126 = %d \n",ft_isprint(126));
//     printf("偽 = %d \n",ft_isprint(127));
//     printf("偽 = %d \n",ft_isprint(-1));
//     return (0);
// }